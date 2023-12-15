#include "IndexHandler.h"
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void IndexHandler::loadDataFromFiles()
{
    string inputLine, key, pair, subkey;
    int value;
    IFS.open("../save_data/generalIndex.txt");
    while(getline(IFS, inputLine))
    {
        ISS.str(inputLine);
        getline(ISS, key, '|');
        generalIndex.insert(key);
        while(getline(ISS, pair, '|'))
        {
            int splitPoint = pair.find(',');
            subkey = pair.substr(0, splitPoint);
            value = stoi(pair.substr(splitPoint + 1, pair.length() - splitPoint));
            generalIndex.updateValue(key, subkey, value);
        }
        ISS.clear();
    }
    IFS.close();

    IFS.open("../save_data/personIndex.txt");
    while(getline(IFS, inputLine))
    {
        ISS.str(inputLine);
        getline(ISS, key, '|');
        personIndex.insert(key);
        while(getline(ISS, pair, '|'))
        {
            int splitPoint = pair.find(',');
            subkey = pair.substr(0, splitPoint);
            value = stoi(pair.substr(splitPoint + 1, pair.length() - splitPoint));
            personIndex.updateValue(key, subkey, value);
        }
        ISS.clear();
    }
    IFS.close();

    IFS.open("../save_data/organizationIndex.txt");
    while(getline(IFS, inputLine))
    {
        ISS.str(inputLine);
        getline(ISS, key, '|');
        organizationIndex.insert(key);
        while(getline(ISS, pair, '|'))
        {
            int splitPoint = pair.find(',');
            subkey = pair.substr(0, splitPoint);
            value = stoi(pair.substr(splitPoint + 1, pair.length() - splitPoint));
            organizationIndex.updateValue(key, subkey, value);
        }
        ISS.clear();
    }
    IFS.close();
}

void IndexHandler::saveData()
{
    generalIndex.writeToFile("../save_data/generalIndex.txt");
    personIndex.writeToFile("../save_data/personIndex.txt");
    organizationIndex.writeToFile("../save_data/organizationIndex.txt");
}

void IndexHandler::loadDataFromDP(AVLTree& g, AVLTree& p, AVLTree& o)
{
    generalIndex.transferData(g);
    personIndex.transferData(p);
    organizationIndex.transferData(o);
}

void IndexHandler::getDocumentsFromQuery(const vector<string>& genQuery, const vector<string>& perQuery, const vector<string>& orgQuery)
{
    unordered_map<string, int> finalDocs, currentDocs, docsToRemove;
    for(string keyWord : genQuery)
    {
        if(keyWord.at(0) == '-')
        {
            currentDocs = generalIndex.getValues(keyWord.substr(1, keyWord.length() - 1));
            docsToRemove.insert(currentDocs.begin(), currentDocs.end());
            continue;
        }
        currentDocs = personIndex.getValues(keyWord);
        for (const pair<const string, int>& doc : currentDocs) 
        {
            if (finalDocs.count(doc.first))
                finalDocs[doc.first] += doc.second;
            else
                finalDocs.insert(doc);
        }
    }
    for(string keyWord : perQuery)
    {
        if(keyWord.at(0) == '-')
        {
            currentDocs = generalIndex.getValues(keyWord.substr(1, keyWord.length() - 1));
            docsToRemove.insert(currentDocs.begin(), currentDocs.end());
            continue;
        }
        currentDocs = personIndex.getValues(keyWord);
        for (const pair<const string, int>& doc : currentDocs) 
        {
            if (finalDocs.count(doc.first))
                finalDocs[doc.first] += doc.second;
            else
                finalDocs.insert(doc);
        }
    }
    for(string keyWord : orgQuery)
    {
        if(keyWord.at(0) == '-')
        {
            currentDocs = generalIndex.getValues(keyWord.substr(1, keyWord.length() - 1));
            docsToRemove.insert(currentDocs.begin(), currentDocs.end());
            continue;
        }
        currentDocs = organizationIndex.getValues(keyWord);
        for (const pair<const string, int>& doc : currentDocs) 
        {
            if (finalDocs.count(doc.first))
                finalDocs[doc.first] += doc.second;
            else
                finalDocs.insert(doc);
        }
    }
    finalDocs.erase(docsToRemove.begin(), docsToRemove.end());
    topDocs.reserve(15); 
    vector<pair<string, int>> sortedPairs(finalDocs.begin(), finalDocs.end());
    for (size_t i = 0; i < 15; i++) 
    {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < sortedPairs.size(); j++)
            if (sortedPairs[j].second > sortedPairs[maxIndex].second)
                maxIndex = j;
        if (maxIndex != i) 
            swap(sortedPairs[i], sortedPairs[maxIndex]);
    }
    for (auto it = sortedPairs.begin(); it != sortedPairs.begin() + 15 && it != sortedPairs.end(); ++it)
        topDocs.push_back(it->first);
}
