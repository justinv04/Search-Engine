#include "QueryProcessor.h"
#include <sstream>

void QueryProcessor::getTermsFromInput(string& input)
{
    string word;
    cleanText(input);
    istringstream ISS(input);
    while(ISS >> word)
    {   
        genTerms.push_back(word);
        if(word.substr(0,7) == "person:")
            perTerms.push_back(word.substr(8, word.length() - 7));
        if(word.substr(0,4) == "org:")
            orgTerms.push_back(word.substr(5, word.length() - 4));
    }
}