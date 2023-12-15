#ifndef AVLTree_H
#define AVLTree_H

#include <cstddef>
#include <queue>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class AVLTree
{
    private:

        struct Node
        {
            string key = "";
            unordered_map<string, int> values;
            Node* parentNode = nullptr;
            Node* leftNode = nullptr;
            Node* rightNode = nullptr;
            int height = 0;
            int size = 0;
            int balanceFactor = 0;

            Node(const string& k)
            {
                key = k;
            }

            Node(const string& k, const unordered_map<string, int>& v)
            {
                key = k;
                values = v;
            }

            ~Node()
            {
                parentNode = nullptr;
                leftNode = nullptr;
                rightNode = nullptr;
                delete parentNode;
                delete leftNode;
                delete rightNode;
            }
            
            string asText()
            {
                string nodeAsText = key;
                for(auto pair : values)
                    nodeAsText +=  "|" + pair.first + "," + to_string(pair.second);
                nodeAsText += "\n";
                return nodeAsText;
            }
        };

        Node* find(const string& key)
        {
            Node* currNode = root;
            string currKey;
            while(currNode)
            {
                if(!currNode)
                    return nullptr;
                currKey = currNode->key;
                if(key == currKey)
                    return currNode;
                if(key < currKey)
                    currNode = currNode->leftNode;
                else if (key > currKey)
                    currNode = currNode->rightNode;
            }
            return nullptr;
        };

        Node* root;
        int size;
        int height;

        void rotateLeft(Node* node);
        void rotateRight(Node* node);
        void remove(Node* removeNode);
        void updateMetrics(Node* node);
        void updateBalFact(Node* node, int left, int right);
        void clear(Node* rootNode);
        void print(Node* rootNode, int space); // recursively prints a graphical representation of the tree
        
    public:

        AVLTree();
        ~AVLTree() {clear(root);};
        AVLTree& transferData(AVLTree& other);

        bool isEmpty() {return root == nullptr;};

        void insert(const string& key);
        void remove(const string& key);
        void incrementValue(const string& key, const string& subkey);
        void incrementValueOrInsert(const string& key, const string& subkey);
        void updateValue(const string& key, const string& subkey, const int& value);

        int getSize() {return size;};
        int getHeight() {return height;};
        unordered_map<string, int> getValues(const string& key); 
        bool contains(const string& key) {return find(key) != nullptr ? true : false;}; 
        void printTree() {print(root, 0);}; // accessor method for recursive print
        string getRootKey() {return root->key;};

        void writeToFile(const string& filePath);
};
#endif