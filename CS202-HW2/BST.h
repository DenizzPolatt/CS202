/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: Description of the BST class
*/

#ifndef BST_H_
#define BST_H_

#include <vector>
#include "BSTNode.h"

class BST {
    BSTNode* root = nullptr;
public:
    BST();
    ~BST();
    BSTNode*& getRoot();
    void traverse(vector<string> &keys, BSTNode *&treePtr);
    void processLeftmost(BSTNode *&nodePtr, string &key);
    vector<string> inorderTraversal(BSTNode *root);
    void searchTreeInsert(string key);
    void insertItem(BSTNode *&treePtr, string newKey);
    void searchTreeDelete(string key);
    void deleteItem(BSTNode *&treePtr, string searchKey);
    void deleteNodeKey(BSTNode *&nodePtr);
};

#endif