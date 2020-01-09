#include "BST.h"
#include <cstddef>
#include <iostream>

BST::BST() {												// default constructor with initilization of root equal to NULL
	root = NULL;
}

tnode* BST::getRoot() {									// function to get root of the tree
	return (this->root);
}

void BST::getParent(int num) {

	tnode* temp = root;
	while (temp != NULL) {
		if (num > temp->data) {
			temp = temp->right;
		}
		else if (num < temp->data) {
			temp = temp->left;
		}
		else {
			std::cout << "Parent of " << num << " is : " << temp->parent->data << std::endl;
			return;
		}
	}
	std::cout << num << " is not found " << std::endl;

}

void BST::insertNonRecursive(int num) {

	tnode* temp = new tnode;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = num;

	if (root == NULL) {
		temp->parent = NULL;
		root = temp;
	}
	else {
		tnode* next = root;
		tnode* current = root;
		while (next != NULL) {
			current = next;
			if (num > next->data) {
				next = next->right;
			}
			else {
				next = next->left;
			}
		}

		if (num > current->data) {
			current->right = temp;
			temp->parent = current;
		}
		else {
			current->left = temp;
			temp->parent = current;
		}
	}
}

int BST::maximumNonRecursive(tnode* max){
	max = root;
	if (max == NULL) {
		return -1;
	}
	else {
		while (max->right != NULL){
			max = max->right;
		}
		return (max->data);
	}
}

int BST::minimumNonRecursive(tnode* min) {
	if (min == NULL) {
		return -1;
	}
	else {
		while (min->left != NULL) {
			min = min->left;
		}
		return (min->data);
	}
}

void BST::inOrderRecursive(tnode* root) {
	if (root == NULL) {
		return;
	}
	else {
		inOrderRecursive(root->left);
		std::cout << root->data << "  ";
		inOrderRecursive(root->right);
	}
}

void BST::searchNonRecursive(int num) {
	tnode* temp = root;
	if (temp == NULL) {
		return;
	}
	else {
		while (temp != NULL) {
			if (num > temp->data) {
				temp = temp->right;
			}
			else if (num < temp->data) {
				temp = temp->left;
			}
			else {
				std::cout << num << " is found" << std::endl;
				return;
			}
		}
		std::cout << num << " is not found" << std::endl;
	}
}

tnode* BST::searchRecursive(int num, tnode* root) {

	if (root == NULL) {
		return 0;
	}
	else if (root->data == num) {
		return (root);
	}
	else {
		if (root->data < num) {
			return searchRecursive(num, root->right);
		}
		else {
			return searchRecursive(num, root->left);
		}
	}
}

int BST::minimumRecursive(tnode* root) {

	if (root == NULL) {
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	else
	{
		return minimumRecursive(root->left);
	}
}

tnode* BST::maximumRecursive(tnode* root) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->right == NULL) {
		return root;
	}
	else {
		return maximumRecursive(root->right);
	}
}

void BST::postOrderRecursive(tnode* root) {
	if (root == NULL) {
		return;
	}
	else {
		postOrderRecursive(root->left);
		postOrderRecursive(root->right);
		std::cout << root->data << "   ";
	}
}

void BST::preOrderRecursive(tnode* root) {
	if (root == NULL) {
		return;
	}else{
		std::cout << root->data << "   ";
		preOrderRecursive(root->left);
		preOrderRecursive(root->right);
	}
}


int BST::successor(tnode* rot, int num) {

	rot = searchRecursive(num, getRoot());
	if (rot == NULL) {
		return -1;
	}
	if (rot->right != NULL) {
		return minimumNonRecursive(rot->right);
	}
	else {
		while (rot != root && rot->data > rot->parent->data) {    // && rot == anynode -> right 
			rot = rot->parent;									  // rot = anynode 
		}														// anynode = anynode->parent
		return (rot->parent->data);								// return rot->data
	}

}


int BST::preDecessor(int num, tnode* rot) {
	rot = searchRecursive(num,getRoot());
	if (rot->left != NULL) {
		return maximumNonRecursive(rot->left);
	}
	else {
		while (rot != root && rot->data < rot->parent->data ){
			rot = rot->parent;
		}
		return (rot->parent->data);
	}
}


void BST::deletion(int num, tnode* rot) {

	tnode* temp = searchRecursive(num, getRoot());
	int del = temp->data;

	if (temp->right == NULL && temp->left == NULL) {
		if (temp->data > temp->parent->data) {
			temp->parent->right = NULL;
			delete temp;
		}
		else {
			temp->parent->left = NULL;
			delete temp;
		}
	}
	else if (temp->right == NULL || temp->left == NULL) {
		if (temp->right == NULL) {
			temp->parent->left = temp->left;
			delete temp;
		}
		else if (temp->left == NULL) {
			temp->parent->right = temp->right;
			delete temp;
		}
	}
	else {
		tnode* max = maximumRecursive(temp);
		temp->data = max->data;
		max->parent->right = NULL;
		delete max;
	}
}
