# K-th Smallest Number

## Purpose:
This program will return the k-th smallest value in a dataset as quickyly as possible. To lower the speed as much as possible, I demonstrated understanding of Binary Search Trees and recursion.

## Inputs:
For ease, please run this program using the makefile command 'make run.'

The user will first be asked if they would like to use the default data set. The user must type 'yes' or 'no' (case sensitive).
1. The user types 'no': they will be asked to input a k; the user should type an integer between 1 and the listed upper range (in this case, 15). 
*Note: the default data set is {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99}.*
2. The user types 'yes': they will asked to input an integer for data set size. Then, the user is asked to input an integer for a seed (for random data set generation). Lastly, the user will be asked to input an upper limit for the data set; the upper limit must be an integer greater than 0.

Regardless of 'yes' or 'no,' user is asked to input a k. The user must input an integer between 1 and the size of the dataset. The limit shall be printed for the user's convienence.

## Outputs:
The user is printed the unsorted array. Then, the user is printed the binary tree using an in-order traversal (values will appear to be printed in numeric order).

Then, the user is printed the k-th smallest value. For example, if the user inputted the k-value to be 1, then the user is returned the smallest value. If the user inputs the k-value as 3, then the user is returned the 3-rd smallest value.

## Steps:
**1.1 User Inputs** <br>
    1.1.1 The user will be asked if they would like the default data set. <br>
        1.1.1.1 'yes'<br>
            1.1.1.1 Move to 1.1.2<br>
    1.1.1.2 'no'<br>
      1.1.1.2.1 The user will be asked to input a dataset size.<br>
        1.1.1.2.1.1 The user inputs a valid integer.<br>
          1.1.1.2.1.1.1 Move to 1.1.1.2.1.2<br>
        1.1.1.2.1.2 The user inputs an unvalid integer.<br>
          1.1.1.2.1.2.1 Termination.<br>
      1.1.1.2.2 The user will be asked to input a seed.<br>
        1.1.1.2.2.1 The user inputs a valid integer.<br>
          1.1.1.2.2.1.1 Move to 1.1.1.2.3<br>
        1.1.1.2.2.2 The user inputs an unvalid integer.<br>
          1.1.1.2.2.2.1 Termination<br>
      1.1.1.2.3 The user will be asked to input an upper limit for the dataset values.<br>
        1.1.1.2.3.1 The user inputs an integer [1, size(dataSet)]<br>
          1.1.1.2.3.1.1 Move to 1.1.2<br>
        1.1.1.2.3.2 The user inputs an invalid input.<br>
          1.1.1.2.3.2.1 Termination.<br>
    1.1.1.3 User inputs an invalid input.<br>
      1.1.1.3.1 Termination<br>
  1.1.2 The user will be asked to input a k-value.<br>
    1.1.2.1 The user inputs a value within the given domain: [1, size(dataSet)].<br>
      1.1.2.1.1 Move to 1.2<br>
    1.1.2.2 The user inputs an invalid input.<br>
      1.1.2.2.1 Termination<br>
**1.2 Create the Binary Search Tree**<br>
    1.2.1 Sort the dataset.<br>
    1.2.2 Get the median.<br>
        1.2.2.1 The dataset is even.<br>
            1.2.2.1.1 Make the floor of the median a node on the heap.<br>
            1.2.2.1.2 Move to 1.2.3<br>
        1.2.2.2 The dataset is odd.<br>
            1.2.2.2.1 Make the median a node on the heap.<br>
            1.2.2.2.2 Move to 1.2.3<br>
    1.2.3 Make the new node the root of a tree.<br>
    1.2.4 Recursively build the rest of the tree.<br>
        1.2.4.1 Pass a pointer to a parent, and a vector of the dataset. <br>
            1.2.4.1.1 The dataset size is greater than 3. <br>
                1.2.4.1.1.1 Split the passed vector in half. <br>
                    1.2.4.1.1.1.1 The vector is odd.<br>
                        1.2.4.1.1.1.1.1 The two vectors are evenly split, excluding the median.<br>
                        1.2.4.1.1.1.1.2 Continue to 1.2.4.1.1.2 <br>
                    1.2.4.1.1.1.2 The vector is even.<br>
                        1.2.4.1.1.1.2.1 The second of the two halves gets the 'extra' data, both sets excluding the lower median.<br>
                        1.2.4.1.1.1.2.2 Continue to 1.2.4.1.1.2<br>
                1.2.4.1.2 Find the medians of the two split datasets.<br>
                    1.2.4.1.2.1 The dataset is even.<br>
                        1.2.4.1.2.1.1 The bottom/lower of the two medians is chosen. <br>
                        1.2.4.1.2.1.2 Continue to 1.2.4.1.3<br>
                    1.2.4.1.2.2 The dataset is odd.<br>
                        1.2.4.1.2.1 The median is identified.<br>
                        1.2.4.1.2.2 Cotninue to 1.2.4.1.3<br>
                1.2.4.1.3 Make nodes of the two medians.<br>
                    1.2.4.1.3.1 Set the parent of the two nodes to the passed parent parameter.<br>
                    1.2.4.1.3.2 Set the passed parent parameter's right and left child to the two created nodes.<br>
                    1.2.4.1.3.3 Continue to 1.2.4.1.4<br>
                1.2.4.1.4 Move to 1.2.4.1 with the two created nodes as the passed parent parameter, and the two split datasets as the passed vector parameter.<br>
            1.2.4.1.2 The dataset size is 2.<br>
                1.2.4.1.2.1 The value at index 1 is made a node.<br>
                1.2.4.1.2.2 The new node parent is the passed parent parameter.<br>
                1.2.4.1.2.3 The new node is the left child of the parent. <br>
                1.2.4.1.2.4 Continue to 1.3.<br>
            1.2.4.1.3 The dataset size is 3.<br>
                1.2.4.1.3.1 The value at index 0 and 2 are made nodes.<br>
                1.2.4.1.3.2 The two nodes' parents are the passed parent parameter.<br>
                1.2.4.1.3.3 The node of index 0 is the right child of the passed parent parameter.<br>
                1.2.4.1.3.4 The node of index 2 is the left child of the passed parent parameter. <br>
**1.3 Create Binary Search Tree**<br>
**1.4 User Outputs**<br>
  1.4.1 Print Binary Search Tree (in-order traversal)<br>
  1.4.2 Print the K-th smallest value<br>
