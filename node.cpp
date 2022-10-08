/*
Name: node.cpp
By: Grace Nguyen
Date: 05 October 2022

Purpose: create a Node class that holds: 
    - integer data 
    - pointer to its parent 
    - pointer to its left/right child(ren)
*/


#include "node.h"


/*
    Constructors
*/
Node::Node() {
    this->data = 0; // data ranges from 1 to user-specified range (will never be 0)
    this->right = NULL;
    this->left = NULL;
    this->parent = NULL;
} // end null parameter constructor

Node::Node(int data) {
    this->data = data;
    this->right = NULL;
    this->left = NULL;
    this->parent = NULL;
} // end constructor

Node::Node(Node* left, int data, Node* right) {
    this->data = data;
    this->right = right;
    this->left = left;
    this->parent = NULL;
} // end constructor


/*
    Getters
*/
int Node::getData() {
    return(this->data);
} // end getData

Node* Node::getRight() {
    return(this->right);
} // end getRight

Node* Node::getLeft() {
    return(this->left);
} // end getLeft

Node* Node::getParent() {
    return(this->parent);
} // end getParent


/*
    Setters
*/
void Node::setData(int data) {
    this->data = data;
} // end setData

void Node::setRight(Node* right) {
    this->right = right;
} // end setRight

void Node::setLeft(Node* left) {
    this->left = left;
} // end setLeft

void Node::setParent(Node* parent) {
    this->parent = parent;
} // end setParent
