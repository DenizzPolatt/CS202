/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: Description of the BSTNode class
*/

#ifndef KMERTREE_H_
#define KMERTREE_H_

#include "BST.h"
#include <fstream>
#include <algorithm>

class KmerTree
{
private:
    BST* bst_;

public:
    KmerTree();
    ~KmerTree();

    void addKmer(string kmer);
    void generateTree(string fileName, int k);
    int getUniqueKmerCount();
    void searchTreeDelete(string key);
    void getUniqueKmerCount(BSTNode*& treePtr, int& count);
    int getNumberOfKmerThatStartWith(char ch);
    int getNumberOfKmerThatStartWith(BSTNode*& treePtr, char ch, int& count);
    void printAll();
    void printAll(BSTNode *treePtr);
    int getHeight();
    vector<string> inorderTraverse(vector<string>& keys);
    int getHeight(BSTNode*& treePtr);
};

#endif 