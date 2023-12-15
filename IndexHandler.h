#ifndef IndexHandler_H
#define IndexHandler_H

#include "AVLTree.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class IndexHandler
{
    private:
        AVLTree generalIndex, personIndex, organizationIndex;
        vector<string> topDocs;
        ifstream IFS;
        ofstream OFS;
        istringstream ISS;

    public:
        
        void loadDataFromFiles(); // read in data from the persistance file
        void saveData(); // write out data to the persistance file
        void loadDataFromDP(AVLTree& g, AVLTree& p, AVLTree& o);
        void getDocumentsFromQuery(const vector<string>& genQuery, const vector<string>& perQuery, const vector<string>& orgQuery); // get the documents that contain the searchword from the query
        vector<string>& getTopDocs() 
        {
            return topDocs;
        };
};

#endif