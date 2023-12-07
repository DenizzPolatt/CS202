/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: Description of the BSTNode class
*/

#ifndef BSTNODE_H_
#define BSTNODE_H_

#include <iostream>
#include <string>

using namespace std;

class BSTNode
{
private:
    string key_;
    int frequency_;
    BSTNode* left_;
    BSTNode* right_;
public:
    BSTNode();
    BSTNode(const string key, int freq, BSTNode *left, BSTNode *right);
    ~BSTNode();

    string getKey();
    int getFreq();
    BSTNode*& getLeft();
    BSTNode*& getRight();

    friend class BST;
};

#endif