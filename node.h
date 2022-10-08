/*
Name: node.h
By: Grace Nguyen
Date: 05 October 2022

Purpose: header for node.cpp; a Node class holds data, and points to its parent and children
*/


#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include <iostream>


class Node {
    private:
        int data;
        Node* right;
        Node* left;
        Node* parent;
    public:
        Node();
        Node(int data); 
        Node(Node* left, int data, Node* right);

        // setters
        void setRight(Node* right);
        void setLeft(Node* left);
        void setParent(Node* parent);
        void setData(int data);

        // getters
        int getData();
        Node* getRight();
        Node* getLeft();
        Node* getParent();
}; // end class definition


#endif
