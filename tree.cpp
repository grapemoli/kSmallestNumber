/*
Name: tree.cpp
By: Grace Nguyen
Date: 05 October 2022

Purpose: the Tree class is a binary tree which contains Node (another class). 
    - understand recursion to create a balanced tree given a data set
    - understand recursion to traverse a tree in-order
    - understand the properties of a binary tree to return the k-th smallest value in the tree
*/


#include "tree.h"
#include "node.h"


/*
    Constructors
*/
Tree::Tree() {
    this->root = NULL;
    this->size = 0;
} // end null parameter constructor

Tree::Tree(Node* root) {
    this->root = root;
    this->size = 1;
} // end constructor


/*
    Destructor
*/
Tree::~Tree() {
    // delete using post-order traversal method
    this->deleteTree(this->root);
} // end destructor


/*
    Access Methods
*/
void Tree::setRoot(Node* root) {
    this->root = root;
} // end setRoot

Node* Tree::getRoot() {
    return(this->root);
} // end getRoot

int Tree::getSize() {
    return(this->size);
} // end getSize

/*
    Traversal Methods
*/
// printInOrder()
// GOAL: print all elements in Tree using an in-order traversal (understand recursion)
// INPUT: node addres
// OUTPUT: returns nothing; prints all elements of the Tree in-order
// if-else (inside the recursive function) -- check for children and if they're null before recursing
void Tree::printInOrder(Node* node) {
    // base case - the node does not exist
    if(node != NULL) {
        printInOrder((*node).getLeft());
	    std::cout << (*node).getData() << std::endl;
	    printInOrder((*node).getRight());
    } // end if
} // end printInOrder

// deleteTree()
// GOAL: taking an input, delete the tree the node is a root of (using post-order traversal)
// INPUT: node address
// OUTPUT: returns nothing
void Tree::deleteTree(Node* node) {
    // base case - the node does not exists
    if(node != NULL) {
        deleteTree((*node).getLeft());
        deleteTree((*node).getRight());
        delete(node);
    } // end if
} // end deleteTree

// inOrder()
// GOAL: return the k-smallest value by in-order traversal
// INPUT: node pointer, address to vector
// OUTPUT: nothing
void Tree::inOrder(Node* node, int k, std::vector<int>* intHolder) {
    // keep pushing node data (in order traversal) to vector until vector size == k
    // base case: node pointer is NULL 
    if(node == NULL) {
        if((*intHolder).size() <= k) { // stop recursing when we have traversed k nodes
	        inOrder((*node).getLeft(), k, intHolder);
	        (*intHolder).push_back((*node).getData()); // pop the current node data to vector
	        inOrder((*node).getRight(), k, intHolder);
	    } // end if
    } // end if
} // end inOrder

/*
    Other Methods 
*/
// createTree()
// GOAL: create a fairly balanced tree given a dataset
// INPUT: pointer to parent node, and a vector
// OUTPUT: returns nothing, but will turn the passed vector into a tree
void Tree::createTree(Node* parent, std::vector<int> dataSet) {
    int length = dataSet.size();

    // base case - length must be greater than 2!!
    if(length > 3) {
        // floor median calculation to account for even data sets!
        int median = floor((length - 1)/2); 

        // split the given data set into two halves 
        std::vector<int> dataLeft; // contains elements in indices [0, median)
        std::vector<int> dataRight;  // contains elements in indices (median, 0]

        for(int i = 0; i < median; i++) {
            dataLeft.push_back(dataSet[i]);
	        dataRight.push_back(dataSet[median + i + 1]); // +1 to exclude the median
        } // end for

	if(length%2 == 0) { // acount for even datasets, which do not have have symmetry as odd datasets
	    dataRight.push_back(dataSet.back());
	} // end if

        // find the 'next' medians
        int medianRight = floor((dataRight.size() - 1)/2); 
        int medianLeft = floor((dataLeft.size() - 1)/2);

        // create new children & establish relationships
        Node* right = setNode(dataRight[medianRight], parent, true); // right node
        Node* left = setNode(dataLeft[medianLeft], parent, false); // left node
	this->size = size + 2;

        // recurse
        createTree(left, dataLeft);
        createTree(right, dataRight);
    }
    else if (length == 3) { // applies to only odd datasets
        Node* left = setNode(dataSet[0], parent, false);
        Node* right = setNode(dataSet[2], parent, true);
	this->size = size + 2;
    }
    else if (length == 2){ // applies to only even datasets
        Node* right = setNode(dataSet[1], parent, true); // element 0 is the parent
	this->size = size + 1;
    } // end if-else
} // end createTree

// setNode()
// GOAL: create a node and set it in the appropiate position in the tree
// INPUT: int data, Node* parent, bool where True refers to the new node is a right child (False means left child)
// OUTPUT: the new created node's address
Node* Tree::setNode(int data, Node* parent, bool isRightChild) {
    Node* newNode = new Node(data);
    (*newNode).setParent(parent);
    
    if(isRightChild == true) {
        (*parent).setRight(newNode);
    }
    else {
        (*parent).setLeft(newNode);
    } // end if-else

    return(newNode);
} // end setNode

// getKSmallest()
// GOAL: this method holds quasi-global variables for the actual traversing to find the k-smallest element
// INPUT: address to a node, and an integer 
// OUTPUT: returns the k-th smallest node's data
int Tree::getKSmallest(Node* node, int k) {
    int kSmallest = -1;
    std::vector<int> intHolder;

    if(k == floor((this->size)/2) {
        kSmallest = (*this->root).getData();
    }
    else{
	    inOrder(node, k, &intHolder);	
    } // end if-else

    kSmallest = intHolder[k];
    return(intHolder.size());
} // end getKSmallest



