#include "AVLTree.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

AVLTree::AVLTree()
{
    height = 0;
    size = 0;
    root = nullptr;
}

AVLTree& AVLTree::transferData(AVLTree& other)
{
    if(this != &other)
    {
        other.root = nullptr;
        other.size = 0;
        other.height = 0;
    }
    return *this;
}

void AVLTree::clear(Node* rootNode)
{
    if (rootNode == nullptr) 
        return;
    if(rootNode->leftNode != nullptr)
        clear(rootNode->leftNode);
    if(rootNode->rightNode != nullptr)
        clear(rootNode->rightNode);
    delete rootNode;
}

void AVLTree::insert(const string& key)
{
    if(root == nullptr)
    {
        root = new Node(key);
        root->parentNode = nullptr;
        updateMetrics(root);
        return;
    }
    Node* currNode = root;
    string currKey;
    while(currNode) // travels down the tree
    {
        currKey = currNode->key;
        if(key < currKey) // if the new key < currKey, go left
        {
            if(currNode->leftNode == nullptr)
            {
                currNode->leftNode = new Node(key);
                currNode->leftNode->parentNode = currNode;
                updateMetrics(currNode->leftNode);
                currNode = nullptr;
            }
            else
                currNode = currNode->leftNode;
        }
        else if(key > currKey) // if the new key > currKey, go right
        {
            if(currNode->rightNode == nullptr)
            {
                currNode->rightNode = new Node(key);
                currNode->rightNode->parentNode = currNode;
                updateMetrics(currNode->rightNode);
                currNode = nullptr;
            }
            else
                currNode = currNode->rightNode;
        }
        else
            return;
    }
}

void AVLTree::remove(const string& key)
{
    if (find(key) == nullptr)
        return;
    Node* removeNode = find(key);
    int balFact = removeNode->balanceFactor;
    if(balFact == 0 && removeNode->leftNode == nullptr)
        clear(removeNode);
    Node* replaceNode = nullptr;
    if (balFact == 1)
    {
        replaceNode = removeNode->rightNode;
        if(replaceNode->leftNode)
        {
            while(replaceNode->leftNode)
                replaceNode = replaceNode->leftNode;
            replaceNode->parentNode->leftNode = nullptr;
        }
        else
            replaceNode->parentNode->rightNode = nullptr;
    }
    else if (balFact == -1)
    {
        replaceNode = removeNode->leftNode;
        if(replaceNode->rightNode)
        {
            while(replaceNode->rightNode)
                replaceNode = replaceNode->rightNode;
            replaceNode->parentNode->rightNode = nullptr;
        }
        else
            replaceNode->parentNode->leftNode = nullptr;
    }
    removeNode->key = replaceNode->key;
    removeNode->values = replaceNode->values;
    updateMetrics(replaceNode->parentNode);
    clear(replaceNode);
}

void AVLTree::incrementValue(const string& key, const string& subkey)
{
    Node* keyNode = find(key);
    if(keyNode == nullptr)
        return;
    keyNode->values[subkey]++;
    keyNode = nullptr;
}

void AVLTree::incrementValueOrInsert(const string& key, const string& subkey)
{
    Node* keyNode = find(key);
    if(keyNode == nullptr)
    {
        insert(key);
        keyNode = find(key);
    }
    keyNode->values[subkey]++;
    keyNode = nullptr;
}

void AVLTree::updateValue(const string& key, const string& subkey, const int& newVal)
{
    Node* keyNode = find(key);
    if(keyNode == nullptr)
    {
        insert(key);
        keyNode = find(key);
    }
    keyNode->values[subkey] = newVal;
    keyNode = nullptr;
}

void AVLTree::rotateLeft(Node* node)
{
    if(node->rightNode != nullptr && node->rightNode->balanceFactor == -1)
    {
        rotateRight(node->rightNode);
        return;
    }
    Node* right = node->rightNode;
    if (node == root)
    {
        right->parentNode = nullptr;
        root = right;
    }
    else
    {
        node->parentNode->leftNode == node ? node->parentNode->leftNode = right : node->parentNode->rightNode = right;
        right->parentNode = node->parentNode;
    }
    node->rightNode = right->leftNode;
    if (right->leftNode != nullptr)
        right->leftNode->parentNode = node;
    right->leftNode = node;
    node->parentNode = right;
    updateMetrics(node);
}

void AVLTree::rotateRight(Node* node)
{
    if(node->leftNode && node->leftNode->balanceFactor == 1)
    {
        rotateLeft(node->leftNode);
        return;
    }
    Node* left = node->leftNode;
    if (node == root)
    {
        left->parentNode = nullptr;
        root = left;
    }
    else
    {
        node->parentNode->rightNode == node ? node->parentNode->rightNode = left : node->parentNode->leftNode = left;
        left->parentNode = node->parentNode;
    }
    node->leftNode = left->rightNode;
    if (left->rightNode != nullptr)
        left->rightNode->parentNode = node;
    left->rightNode = node;
    node->parentNode = left;
    updateMetrics(node);
}

void AVLTree::updateMetrics(Node* node)
{
    Node* currNode = node;
    while (currNode)
    {
        //cout << "checking node: " << currNode->key << "\n";
        int leftHeight = (currNode->leftNode) ? currNode->leftNode->height + 1 : 0;
        int leftSize = (currNode->leftNode) ? currNode->leftNode->size + 1 : 0;
        int rightHeight = (currNode->rightNode) ? currNode->rightNode->height + 1 : 0;
        int rightSize = (currNode->rightNode) ? currNode->rightNode->size + 1 : 0;
        currNode->height = (leftHeight >= rightHeight) ? leftHeight : rightHeight;
        currNode->size = leftSize + rightSize;
        currNode->balanceFactor = rightHeight - leftHeight;
        //cout << currNode->height << " " << currNode->size << " " << currNode->balanceFactor << "\n"; 
        if (currNode->balanceFactor == 2)
        {
            //cout << "rotate left!\n";
            rotateLeft(currNode);
            return;
        }
        else if (currNode->balanceFactor == -2)
        {
            //cout << "rotate right!\n";
            rotateRight(currNode);
            return;
        }
        if (currNode->parentNode == nullptr)
            root = currNode;
        currNode = currNode->parentNode;
    }
    size = root->size + 1;
    height = root->height > 0 ? root->height : 1;
}

void AVLTree::print(Node* rootNode, int space)
{
    /*
        Credit for original implementation to Simple Snippets on Youtube
        link: https://youtu.be/xhkSiIeTKQo
    */

    if(rootNode == nullptr)
        return;
    ++space;
    print(rootNode->rightNode, space);
    cout << "\n";
    for(int i = 1; i < space; ++i)
        cout << "     ";
    if(rootNode == root)
        cout << "-->";
    cout << rootNode->key << "\n";
    print(rootNode->leftNode, space);
}

void AVLTree::writeToFile(const string& filePath)
{
    if(root == nullptr)
        return;
    ofstream output;
    queue<Node*> q;
    Node* currNode;
    output.open(filePath);
    q.push(root);
    while(!q.empty())
    {
        currNode = q.front();
        output << currNode->asText();
        if(currNode->leftNode != nullptr)
            q.push(currNode->leftNode);
        if(currNode->rightNode != nullptr)
            q.push(currNode->rightNode);
        q.pop();
    }
    output.close();
}

unordered_map<string, int> AVLTree::getValues(const string& key) 
{
    Node* node = find(key);
    unordered_map<string, int> map;
    if(node != nullptr)
        map = node->values;
    return map;
}