#include "DocumentParser.h"
#include "IndexHandler.h"
#include "QueryProcessor.h"
#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    DocumentParser Parser;
    IndexHandler Handler;
    QueryProcessor Processor;
    cout << "\nWelcome to the SuperSearch search engine!\n"
         << "To index all files in a directory, type 'index <directory name>', minus the brackets, of course \n"
         << "To search by keywords, type 'query <search terms, separated by spaces>'\n"
         << "\tYou can specify a search term as a person or an organization by typing 'person: or org:' before your search term\n"
         << "\tYou can exclude all documents that contain a search term by typing '-' before that term\n"
         << "To read/write the current indicies to/from file, type 'save data' or 'load data'\n"
         << "To exit the program, type 'goodbye'\n\n";

    string userInput, userOperation;
    while(true)
    {
        cout << "Enter an input here:\n";
        getline(cin, userInput);
        cout << "\n";
        if(userInput == "goodbye")
        {
            cout << "Goodbye, and thanks for using SuperSearch!\n";
            return 0;
        }
        userOperation = userInput.substr(0, 5);
        if(userOperation == "query")
        {
            cout << "Searching Documents for your terms...\n";
            string terms = userInput.substr(6, userInput.length() - 6);

            auto start = chrono::high_resolution_clock::now();
            Processor.getTermsFromInput(terms);
            Handler.getDocumentsFromQuery(Processor.getGenTerms(), Processor.getPerTerms(), Processor.getOrgTerms());
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "Search completed in " << duration.count() << " ms\n";
            Parser.printInfoFromDocs(Handler.getTopDocs());
            Handler.getTopDocs().clear();       
        }
        else if(userOperation == "index")
        {
            string directory = userInput.substr(6, userInput.length() - 6);
            cout << "Initiating indexing of directory '" << directory << "'...\n"; 

            auto start = chrono::high_resolution_clock::now();
            Parser.readFileSet(directory);
            Handler.loadDataFromDP(Parser.getGenKeys(), Parser.getPerKeys(), Parser.getOrgKeys());
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "Indexing completed in " << duration.count() << " ms\n";
        }
        else if(userOperation == "save ")
        {
            cout << "Saving indicies to file...\n";

            auto start = chrono::high_resolution_clock::now();
            Handler.saveData();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "Saving completed in " << duration.count() << " ms\n";
        }
        else if(userOperation == "load ")
        {
            cout << "Loading indicies from file...\n";

            auto start = chrono::high_resolution_clock::now();
            Handler.loadDataFromFiles();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = end - start;

            cout << "Loading completed in " << duration.count() << " ms\n";
        }
        else
            cout << "Unrecognized command: please re-read the instructions for properly formatted input\n";
        cout << "\n";
    }
    return 0;
}
