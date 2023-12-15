#include "DocumentParser.h"
#include "rapidjson/istreamwrapper.h"
#include <filesystem>

void DocumentParser::readFile(const string& filePath)
{
    IFS.open(filePath);
    rapidjson::IStreamWrapper ISW(IFS);
    currentDocument.ParseStream(ISW);

    auto persons = currentDocument["entities"]["persons"].GetArray(); // get the person entities and store them
    for(auto& person : persons)
    {
        perKeys.incrementValueOrInsert(person["name"].GetString(), filePath);
    }
    
    auto organizations = currentDocument["entities"]["organizations"].GetArray(); // get the organization entities and store them
    for(auto& organization : organizations)
    {
        orgKeys.incrementValueOrInsert(organization["name"].GetString(), filePath);
    }
    string fullText = currentDocument["title"].GetString();
    fullText += " ";
    fullText += currentDocument["text"].GetString();
    parseText(fullText, filePath);
    IFS.close();
}

void DocumentParser::parseText(string text, const string& filePath)
{
    cleanText(text);
    string word;
    ISS.str(text);
    while (ISS >> word)
    {
        if(stopWords.count(word) != 0 || word.empty() || word.length() > 15)
            continue;
        genKeys.incrementValueOrInsert(word, filePath);
        perKeys.incrementValue(word, filePath);
        orgKeys.incrementValue(word, filePath);
    }
    ISS.clear();
}

void DocumentParser::cleanText(string& text)
{
    for(char c : text)
    {
        if(!isalpha(c))
            c = ' ';
        else
            c = tolower(c);
    }
    string newText, word;
    ISS.str(text);
    while(ISS >> word)
    {
        Porter2Stemmer::stem(word);
        newText += word + " "; 
    }
    text = newText;
}

void DocumentParser::printInfoFromDocs(const vector<string>& docs)
{
    cout << "Search Results:\n\n";
    string title, publication, date;
    for(string fileName : docs)
    {
        IFS.open(fileName);
        rapidjson::IStreamWrapper ISW(IFS);
        currentDocument.ParseStream(ISW);
        title = currentDocument["title"].GetString();
        publication = currentDocument["author"].GetString();
        if(publication == "")
            publication = currentDocument["thread"]["site"].GetString();
        date = currentDocument["published"].GetString();
        date = date.substr(0, 10);
        cout << title << ", Publication: " << publication << ", Date Published: " << date << "\n\n";
        IFS.close();
    }
}

