//how to build a binary search tree by using linked list
#include <iostream>
using namespace std;

struct BSTTreeNode
{
	int value;

	BSTTreeNode* left;
	BSTTreeNode* right;
};

BSTTreeNode* insert(BSTTreeNode* root, int data)
{
	//1. create new node
	BSTTreeNode* newNode = new BSTTreeNode;
	newNode->value = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL) {
		root = newNode;
		return root;
	}
	//if root is not empty
	BSTTreeNode* currentNode = root;
	BSTTreeNode* parentNode = NULL;

	while(currentNode != NULL) {
		if (currentNode->value == data) {
			cout << "No duplicated key allowed. Unable to insert." << endl;
			return root;
		}
		parentNode = currentNode;

		if (data < currentNode->value) {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}
	}
	if (data < parentNode->value) {
		parentNode->left = newNode;
	}
	else {
		parentNode->right = newNode;
	}
	return root;
}

void preorder(BSTTreeNode* root) //MLR
{
	if (root != NULL) {
		cout << root->value << ", ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BSTTreeNode* root) //LMR
{
	preorder(root->left);
	cout << root->value << ", ";
	preorder(root->right);
}

void postorder(BSTTreeNode* root) // LRM
{
	preorder(root->left);
	preorder(root->right);
	cout << root->value << ", ";
}

int heightofTree(BSTTreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + max(heightofTree(root->left), heightofTree(root->right));
}

int SumofTree(BSTTreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return root->value + SumofTree(root->left) + SumofTree(root->right);
}

int countOfNodeintree(BSTTreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + countOfNodeintree(root->left) + countOfNodeintree(root->right);
}

int max(BSTTreeNode* root) {
	if (root != NULL) {
		BSTTreeNode* current = root;

		while (current->right != NULL) {
			current = current->right;
		}
		return current->value;
	}
}

int min(BSTTreeNode* root) {
	if (root != NULL) {
		BSTTreeNode* current = root;

		while (current->left != NULL) {
			current = current->left;
		}
		return current->value;
	}
}

bool searchData(BSTTreeNode* root, int data);

//remove the node from the binary search tree
BSTTreeNode* remove(BSTTreeNode* root, int deleted_data) {
	if (root == NULL) {
		cout << "No node in the tree yet! Can't delete" << endl;
		return root;
	}

	BSTTreeNode* currentNode = root;
	BSTTreeNode* parentNode = NULL;

	//search which number is the value u wanna remove
	while (currentNode->value != deleted_data) {
		parentNode = currentNode;

		if (deleted_data < currentNode->value) {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}

		if (currentNode == NULL) {
			cout << "The deleted value does not exist in the tree." << endl;
			return root;
		}
	}
	//after found the deleted data, start deleting
	//Situation 1: current node does not have any children (leaf node)
	if (currentNode->left == NULL && currentNode->right == NULL) {
		if (parentNode != NULL) { //leaf
			if (parentNode->left == currentNode) {
				parentNode->left = NULL;
			}
			else {
				parentNode->right = NULL;
			}
		}
		else { //root
			root = NULL;
		}

		delete currentNode;
	}

	//Situation 2: current node only has a right child
	else if (currentNode->left == NULL && currentNode->right != NULL) {
		if (parentNode != NULL) { //middle node
			if (parentNode->left == currentNode) {
				parentNode->left = currentNode->right;
			}
			else {
				parentNode->right = currentNode->right;
			}
		}
		else {
			root = currentNode->right;
		}

		delete currentNode;
	}

	//Situation 3: current node only has a left child
	else if (currentNode->left == NULL && currentNode->right != NULL) {
		if (parentNode != NULL) { //middle node
			if (parentNode->left == currentNode) {
				parentNode->left = currentNode->left;
			}
			else {
				parentNode->right = currentNode->left;
			}
		}
		else {
			root = currentNode->left;
		}

		delete currentNode;
	}

	//Situation 4: current node have both children, we choose from the left subtree(successor) nodes as replacement
	else {
		BSTTreeNode* successor = currentNode->left;
		BSTTreeNode* subParentNode = NULL;

		while (successor->right != NULL) {//find max number in the left subtree}
			subParentNode = currentNode;
			currentNode = currentNode->right;
		}

		currentNode->value = successor->value;

		if (subParentNode == NULL) {
			currentNode->left = successor->left;
		}
		else {
			subParentNode->left = successor->left;
		}

		delete successor;
	}
}

int main()
{
	BSTTreeNode* root = NULL;
	int numberOfDataInserted;

	cout << "How many data would you like to insert to the binary search tree now? ";
	cin >> numberOfDataInserted;

	int data;

	for (int i = 1; i <= numberOfDataInserted; i++) {
		cout << "Value " << i << ": ";
		cin >> data;

		root = insert(root, data);
	}
	cout << endl << "Preorder transversal: ";
	preorder(root);

	cout << endl << "Inorder transversal: ";
	inorder(root);

	cout << endl << "Postorder transversal: ";
	postorder(root);

	cout << endl << endl << "The height level current tree is " << heightofTree(root) << "." << endl;
	cout << "The total value of tree is " << SumofTree(root) << "." << endl;
	cout << "The number of nodes in tree is " << countOfNodeintree(root) << "." << endl;
	cout << "The max value of node in tree is " << max(root) << "." << endl;
	cout << "The min value of node in tree is " << min(root) << "." << endl;

	cout << endl << "Which value you want to remove? ";
	cin >> data;
	remove(root, data);
	preorder(root);
	cout << endl;

	return 0;
}
