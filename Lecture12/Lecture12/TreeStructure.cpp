#include <iostream>
using namespace std;

struct binaryTreeNode {
	int data;

	binaryTreeNode* left;
	binaryTreeNode* right;
};

//array representation on the binary tree
int a[] = { 3, 5, 9, 6, 8, 20, 10, '\0', '\0', 9, '\0', '\0', '\0', '\0', '\0', '\0', '\0' };

binaryTreeNode* insert(int index) {
	binaryTreeNode* newNode = NULL;

	if (a[index] != NULL) {
		newNode = new binaryTreeNode;
		newNode->data = a[index];
		newNode->left = insert(2 * index + 1); //that's how we can find the index on the left, by 2*parent's index then +1
		newNode->right = insert(2 * index + 2); //that's how we can find the index on the right, by 2*parent's index then +2
	}
	return newNode;
}

void preOrder(binaryTreeNode* root) { //MLR
	if (root != NULL) {
		cout << root->data << ", ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(binaryTreeNode* root) { //LRM
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << ", ";
	}
}

void inOrder(binaryTreeNode* root) { //LMR
	if (root != NULL) {
		inOrder(root->left);
		cout << root->data << ", ";
		inOrder(root->right);
	}
}

int main() {
	//convert the array representation of binary tree to become linked-list based
	binaryTreeNode* root = NULL;

	root = insert(0); //index from 0
	preOrder(root); //to display the preorder trasnversal
	cout << endl;
	postOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;

	return 0;
}