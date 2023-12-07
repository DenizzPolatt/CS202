/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: Implementation of the BSTNode class
*/

#include "BSTNode.h"

BSTNode::BSTNode(){};
BSTNode::BSTNode(const string key, int freq, BSTNode* left, BSTNode* right) {
    key_ = key;
    frequency_ = freq;
    left_ = left;
    right_ = right;
}

BSTNode::~BSTNode() {
    delete left_;
    delete right_;
}

string BSTNode::getKey() {
    return key_;
}

int BSTNode::getFreq()
{
    return frequency_;
}

BSTNode*& BSTNode::getLeft()
{
    return left_;
}

BSTNode*& BSTNode::getRight()
{
    return right_;
}