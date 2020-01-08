#pragma once

#include "tnode.h"
#include <cstddef>
#include <iostream>

class BST
{
private:
	tnode* root;
public:

	BST();

	tnode* getRoot();
	void getParent(int num);

	void insertNonRecursive(int num);                   // function to insert a leave non recursive
	int maximumNonRecursive(tnode* root);                          // function returning maximum value from tree non recursive  
	int minimumNonRecursive(tnode* root);                          // function returing minimum value from tree non recursive

	void searchNonRecursive(int num);	                // function for searching a number non recursive
	void inOrderRecursive(tnode* root);                 // funtoin to print tree in a inorder form recursively
	void postOrderRecursive(tnode* root);				// function to print tree in post order form recursively

	void preOrderRecursive(tnode* root);				// function to print tree in pre order form recursively
	tnode* searchRecursive(int num, tnode* root);         // function for searching a number recursively
	int minimumRecursive(tnode* root);                  // function to find minimum number in tree recursively
	
	tnode* maximumRecursive(tnode* root);                  // function to find maximum number in tree recursively
	int successor(tnode* root,int num);						// function to find successor in a tree
	void deletion(int num, tnode* rot);                    //  function to delete any node from tree

	int preDecessor(int num, tnode* rot);

};