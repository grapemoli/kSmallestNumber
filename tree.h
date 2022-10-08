/*
Name: tree.h
By: Grace Nguyen
Date: 05 October 2022

Purpose: header guard for tree.cpp; create a Binary tree class which contains Nodes
*/


#ifndef TREE_H_EXISTS
#define TREE_H_EXISTS

#include <iostream>
#include <vector>
#include <cmath>

#include "node.h"


class Tree {
    private:
        Node* root;
	    int size;
    public:
        Tree();
        ~Tree();
        Tree(Node* root);
	    Tree(Node* root, std::vector<int> dataSet);

        // setters
        void setRoot(Node* root);

        // getters
        Node* getRoot();
	    int getSize();

        // traversal methods
        void printInOrder(Node* node);
        void deleteTree(Node* node); 
	    void inOrder(Node* node, int k, std::vector<int>* intHolder);

        // other methods
	    Node* setNode(int data, Node* parent, bool isRightChild);
        void createTree(Node* parent, std::vector<int> dataSet);
        int getKSmallest(Node* node, int k); 
}; // end class definition


#endif
