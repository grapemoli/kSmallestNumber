/*
    Name: main.cpp
    By: Grace Nguyen
    Date: 05 October 2022

    Purpose: given a user defined k and a data set in a binary search tree,
    return the k-th smallest value in the bst/data set
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#include "node.h"
#include "tree.h"

int main() {
    std::string runDefault;
    std::vector<int> dataSet;
    int k;
    
    // get if the user wants a default data set or no
    std::cout << "Do you want to use the default data set (yes/no)? \n";
    std::cin >> runDefault;

    // if user does not want a default data set, ask the user for (1) data set length, and (2) seed
    if(runDefault == "yes"){
        dataSet = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
    }
    else if (runDefault == "no"){
        int size;
        int seed;
	    int maxData;
        std::cout << "Data set size: " << std::endl; // ask for size
        std::cin >> size;

        std::cout << "Seed (for random number generation): \n"; // ask for seed
        std::cin >> seed;

	    std::cout << "Max of the dataset's range:\n"; // ask for upper limit of data set
	    std::cin >> maxData;

        // create the new data set!
        srand(seed);

        for(int i = 0; i < size; i++) {
            dataSet.push_back( (rand()%maxData) + 1);
        } // end for
    } // end if-else

    // ask user for k
    std::cout << "K (must be less-than/equal-to " << dataSet.size() << "):\n";
    std::cin >> k;


    // print array (unsorted) 
    std::cout << "\n\nYour Dataset:\n";
    for(int i = 0; i < dataSet.size(); i++) {
        std::cout << "(" << (i+1) << ") " << dataSet[i] << ", ";
    } // end for

    // sort data set
    sort(dataSet.begin(), dataSet.end());


    // create root Node, then instantiate Tree with root Node
    int median = floor((dataSet.size() - 1)/2); // account for even datasets
    Node* root = new Node(dataSet[median]);
    Tree t(root);


    // use dataset to create a tree & print
    t.createTree(t.getRoot(), dataSet);
    std::cout << "\n\n~ The Tree (In Order Traversal) ~\n";
    t.printInOrder(t.getRoot());

    // return the k value
    int treeSize = t.getSize();
    int kSmallest = t.getKSmallest(t.getRoot(), k);
    std::cout << "\n" << k << "-th Smallest Value: " << kSmallest << "\n";
} // end main
