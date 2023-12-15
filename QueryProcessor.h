#ifndef QueryProcessor_H
#define QueryProcessor_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "porter2_stemmer.h"

using namespace std;

class QueryProcessor
{
    private:
        istringstream ISS;
        vector<string> genTerms, perTerms, orgTerms;
        void cleanText(string& text) 
        {
            string newText, word;
            ISS.str(text);
            while(ISS >> word)
            {
                Porter2Stemmer::stem(word);
                newText += word + " "; 
            }
            for(char c : newText) 
                c = tolower(c);
            text = newText;
        };
    public:
        void getTermsFromInput(string& input);
        vector<string>& getGenTerms() {return genTerms;};
        vector<string>& getPerTerms() {return perTerms;};
        vector<string>& getOrgTerms() {return orgTerms;};
};

#endif