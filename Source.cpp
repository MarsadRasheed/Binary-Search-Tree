#include <iostream>
#include "tnode.h"
#include "BST.h"

using namespace std;

int main() {

	BST tree;

	tree.insertNonRecursive(4);
	tree.insertNonRecursive(6);
	tree.insertNonRecursive(3);
	tree.insertNonRecursive(1);
	tree.insertNonRecursive(5);
	tree.insertNonRecursive(7);

	cout << "maximum leave is : " << tree.maximumNonRecursive(tree.getRoot()) << endl;
	cout << "minimum leave is : " << tree.minimumNonRecursive(tree.getRoot()) << endl;
	
	tree.searchNonRecursive(4);

	tnode* no = tree.searchRecursive(6, tree.getRoot());
	cout << "root data issssssss : " << no->data;

	int mini = tree.minimumRecursive(tree.getRoot());
	cout << "Minimum value is : " << mini << endl;
	tnode* max = tree.maximumRecursive(tree.getRoot());
	cout << "Maximum value is : " << max->data << endl;

	tree.inOrderRecursive(tree.getRoot());
	cout << endl;
	tree.postOrderRecursive(tree.getRoot());
	cout << endl;
	tree.getParent(1);

	cout << "successor : " << tree.successor(tree.getRoot(), 8) << endl;
//	tree.deletion(6, tree.getRoot());
//	tree.deletion(7, tree.getRoot());
//	tree.inOrderRecursive(tree.getRoot());
	cout << "pre decessor : " << tree.preDecessor(5, tree.getRoot());
	cout << endl;

	system("pause");
}