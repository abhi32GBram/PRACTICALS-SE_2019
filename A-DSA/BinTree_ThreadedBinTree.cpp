#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
	int key;
	Node* left, * right;
	bool isThreaded;
};

Node* createThreaded(Node* root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;
	if (root->left != NULL)
	{
		Node* l = createThreaded(root->left);
		l->right = root;
		l->isThreaded = true;
	}
	if (root->right == NULL)
		return root;
	return createThreaded(root->right);
}

Node* leftMost(Node* root)
{
	while (root != NULL && root->left != NULL)
		root = root->left;
	return root;
}

void inOrder(Node* root)
{
	if (root == NULL)
		return;
	Node* cur = leftMost(root);
	while (cur != NULL)
	{
		cout << cur->key << " ";
		if (cur->isThreaded)
			cur = cur->right;
		else
			cur = leftMost(cur->right);
	}
}

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->left = temp->right = NULL;
	temp->key = key;
	return temp;
}

int main_Thread()
{
	cout << "\n\t\t~~~ CONVERSION OF BINARY TREE TO THREADED BINARY TREE ~~~ ";
	cout << "\n\nTHE NODE VALUES IN THE GIVE BINARY TREE ARE : SOMETHING ";

	Node* root = newNode(20);
	root->left = newNode(60);
	root->right = newNode(90);
	root->left->right = newNode(65);
	root->right->left = newNode(0);
	root->right->right = newNode(56);
	root->right->right->left = newNode(23);
	root->right->right->right = newNode(711);
	root->right->right->left->right = newNode(57);
	createThreaded(root);

	cout << "\n\n THE EQUIVALENT INORDER TRAVERSAL OF CREATED "	"THREADED TREE IS : ";
	inOrder(root);
	return 0;
	system("pause>0");
}
