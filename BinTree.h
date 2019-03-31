/*
ADT: Binary Search Tree  By Zhaoning Qiu (1876501)
BinTree class:
-allows output tree by inorder
-allows create a new tree as a copy of given tree
-allows to make tree empty and check empty
-allows to check two tree are equal or not
-allows to get the height of given nodedata
-allows to search and retrieve the data from the tree
-allows to transform an array to bintree, or transform bintree to array


Assumption:
-Equal/Not Equal ()
If tree1 and tree2 are both empty,  tree1==tree2  return true; tree1!=tree2 return false

-retrieve()
If the given data does not found, there's no change to the second parameter

-getHeight()
If the given data does not match the tree, return 0

*/
#pragma once
#include <iostream>
#include <string>
#include "NodeData.h"
class BinTree {						// you add class/method comments and assumptions

	friend ostream& operator<<(ostream& output, const BinTree& tree);
public:
	BinTree();											// constructor
	BinTree(const BinTree &);							// copy constructor
	~BinTree();											// destructor, calls makeEmpty	
	bool isEmpty() const;								// true if tree is empty, otherwise false
	void makeEmpty();									// make the tree empty so isEmpty returns true
	BinTree& operator=(const BinTree &);				//assign operator overload
	bool operator==(const BinTree &) const;				// equal operator overload
	bool operator!=(const BinTree &) const;				// not equal operator overload
	bool insert(NodeData*);								//insert the nodedata as a node into the bintree
	bool retrieve(const NodeData &, NodeData* &) const; //retrieve the nodedata from the tree
	void displaySideways() const;						// provided below, displays the tree sideways
	int getHeight(const NodeData &) const;				//get the highest node level in the tree
	void arrayToBSTree(NodeData*[]);					//transfer array element to bintree nodes
	void bstreeToArray(NodeData*[]);					//transfer bintree data to array elements
	int getSize() const;										//nodes amount

private:
	struct Node {
		NodeData* data;									// pointer to data object
		Node* left;										// left subtree pointer
		Node* right;									// right subtree pointer
	};
	Node* root;											// root of the tree
	int size;

// utility functions
	Node* retrieveNode(const NodeData &, Node *) const;
	void deleteNode(Node *& n);							//recursion method delete each node
	int retrieveLevel(Node *n) const;					//recursion method retrieve the node's level 
	void inorderToArrayHelper(NodeData*[], Node*, int&) const;				 //cesursion helper for toarray method
	void sideways(Node*, int) const;					// provided elow, helper for displaySideways()
	bool equalHelper(Node*, Node*) const;					//recursive helper method for operation== overload
	Node* copyConstrHelper(const Node*) const;				//copy constructer's recursive helper method
	Node* inorderToTreeHelper(NodeData*[], int, int);		//recursion helper for to tree method
	void inorderOutputHelper(ostream&, Node*) const;		// recursion helper for output overload method


};
