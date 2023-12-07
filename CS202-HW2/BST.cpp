/**
* Title: Binary Search Trees
* Author: Deniz Polat
* ID: 22103590
* Section: 1
* Homework: 2 * Description: Implementation of the BST class
*/

#include "BSTNode.h"
#include "BST.h"

BST::BST() = default;
BST::~BST() {
    delete root;
}
BSTNode*& BST::getRoot() {return root;}

void BST::traverse(vector<string>& keys, BSTNode*& treePtr)
{
    if(treePtr->left_ != NULL)
    {
        traverse(keys, treePtr->left_);
    }
    keys.push_back(treePtr->getKey());
    if(treePtr->right_ != NULL)
    {
        traverse(keys, treePtr->right_);
    }
}

void BST::processLeftmost(BSTNode*& nodePtr, 
                        string& key)
                        {

    if (nodePtr->left_ == NULL) {
        key = nodePtr->key_;
        BSTNode* delPtr = nodePtr;
        nodePtr = nodePtr->right_;
        delPtr->right_ = NULL; 
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->left_, key);
}


vector<string> BST::inorderTraversal(BSTNode* root)
{
    vector<string> keys;
    traverse(keys, root);
    return keys;
}

void BST::searchTreeInsert(string key)
{
    insertItem(root, key);
}

void BST::insertItem(BSTNode*& treePtr, string newKey) 
{
    if(treePtr == NULL)
    {   

        treePtr = new BSTNode(newKey, 1, nullptr, nullptr);
        if(treePtr == NULL)
        {
            cout << "Insert " << newKey << " unsuccessful" << endl;
        }

    }
    else if(newKey.compare(treePtr->key_) < 0){
        insertItem(treePtr->left_, newKey);
    }
    else if (newKey.compare(treePtr->key_) > 0) {
        insertItem(treePtr->right_, newKey);
    } else {
        treePtr->frequency_ ++;
    }
}

void BST::searchTreeDelete(string key)
{
    deleteItem(root, key);
}

void BST::deleteItem(BSTNode*& treePtr, string searchKey)
{
    if(treePtr == NULL)
    {
        cout << "Delete failed" << endl;
    }

    else if (searchKey == treePtr->getKey())
    {
        deleteNodeKey(treePtr);
    }

    else if(searchKey.compare(treePtr->key_) < 0)
    {
        deleteItem(treePtr->left_, searchKey);
    }
    else {
        deleteItem(treePtr->right_, searchKey);
    }
}

void BST::deleteNodeKey(BSTNode*& nodePtr)
{
    BSTNode* delPtr;
    string replacementKey;

    // case 1: deleting a leaf bstNode
    if((nodePtr->left_ == NULL) && (nodePtr->right_ == NULL))
    {
        delete nodePtr;
        nodePtr = NULL;
    }

    // case 2 : no left child
    else if(nodePtr->left_ == NULL)
    {
        delPtr = nodePtr;
        nodePtr = nodePtr->right_;
        delPtr->right_ = NULL;
        delete delPtr; 
    }

    // case 3: no right child
    else if(nodePtr->right_ == NULL)
    {
        delPtr = nodePtr;
        nodePtr = nodePtr->left_;
        delPtr->left_ = NULL;
        delete delPtr; 
    }

    //case 4: deleting a bstNode with two children.
    //we need the inorder inorderSuccessoressor for this operation.
    else {
        processLeftmost(nodePtr->right_, replacementKey);
        nodePtr->key_ = replacementKey;
    }
}