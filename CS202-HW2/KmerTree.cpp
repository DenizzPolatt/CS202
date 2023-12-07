/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: Implementation of the KmerTree class
*/

#include "KmerTree.h"

KmerTree::KmerTree(){
    bst_ = new BST();
};
KmerTree::~KmerTree() { delete bst_; }

void KmerTree::addKmer(string kmer)
{
    bst_->searchTreeInsert(kmer);
}

void KmerTree::generateTree(string fileName, int k)
{
    ifstream file(fileName);

    string file_contents((std::istreambuf_iterator<char>(file)),
        (std::istreambuf_iterator<char>()));
    transform(file_contents.begin(), file_contents.end(), file_contents.begin(), ::tolower);

    for(int i = 0; i < file_contents.length()-(k-1); i += k)
    {
        string key = file_contents.substr(i, k);
        addKmer(key);
    }
}

int KmerTree::getUniqueKmerCount()
{
    int count = 0;
    getUniqueKmerCount(bst_->getRoot(), count);
    return count;
}

void KmerTree::getUniqueKmerCount(BSTNode*& treePtr, int& count)
{
    if(treePtr->getLeft() != NULL)
    {
        getUniqueKmerCount(treePtr->getLeft(), count);
    }
    if(treePtr->getFreq() >= 1)
    {
        count++;
    }
    if(treePtr->getRight() != NULL)
    {
        getUniqueKmerCount(treePtr->getRight(), count);
    }
}

void KmerTree::searchTreeDelete(string key)
{
    bst_->searchTreeDelete(key);
}

int KmerTree::getNumberOfKmerThatStartWith(char ch)
{
    int count = 0;
    getNumberOfKmerThatStartWith(bst_->getRoot(), ch, count);
    return count;
}

int KmerTree::getNumberOfKmerThatStartWith(BSTNode*& treePtr, char ch, int& count)
{
    if(treePtr->getLeft() != NULL)
    {
        getNumberOfKmerThatStartWith(treePtr->getLeft(), ch, count);
    }
    if(treePtr->getKey().at(0) == ch)
    {
        count++;
    }
    if(treePtr->getRight() != NULL)
    {
        getNumberOfKmerThatStartWith(treePtr->getRight(), ch, count);
    }

    return count;
}

void KmerTree::printAll()
{   
    printAll(bst_->getRoot());
}

void KmerTree::printAll(BSTNode* treePtr)
{
    if(treePtr->getLeft() != NULL)
    {
        printAll(treePtr->getLeft());
    }

    cout << treePtr->getKey() << ", frequency = " << treePtr->getFreq() << endl;

    if(treePtr->getRight() != NULL)
    {
        printAll(treePtr->getRight());
    }
}

int KmerTree::getHeight()
{
    return getHeight(bst_->getRoot());
}

vector<string> KmerTree::inorderTraverse(vector<string>& keys)
{
    keys = bst_->inorderTraversal(bst_->getRoot());
    return keys;
}

int KmerTree::getHeight(BSTNode*& treePtr)
{
    if(treePtr == NULL)
    {
        return 0;
    }
    else {
        return max(getHeight(treePtr->getLeft()), getHeight(treePtr->getRight())) + 1;
    }
}