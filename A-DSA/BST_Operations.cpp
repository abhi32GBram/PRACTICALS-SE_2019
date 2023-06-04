#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node {
	int a;
	struct node* left, * right;
} node;

struct node* root = NULL;

class BST {
	int count;
	struct node* temp = NULL, * t1 = NULL, * s = NULL, * t = NULL;
public:
	BST() {
		count = 0;
	}
	struct node* create();
	void insert();
	int height(struct node* q, int c);
	int findmin(struct node* T);
	void swap(struct node* q);
	void search(struct node* root, int m);
	void display(struct node* q);
};

struct node* BST::create() {
	node* p = new(struct node);
	p->left = NULL;
	p->right = NULL;
	cout << "\n ENTER THE VALUE OF NODE: ";
	cin >> p->a;
	return p;
}

void BST::insert() {
	temp = create();
	if (root == NULL) {
		root = temp;
	}
	else {
		t1 = root;
		while (t1 != NULL) {
			s = t1;
			if ((temp->a) > (t1->a)) {
				t1 = t1->right;
			}
			else {
				t1 = t1->left;
			}
		}
		if ((temp->a) > (s->a)) {
			s->right = temp;
		}
		else {
			s->left = temp;
		}
	}
}

int BST::height(struct node* q, int c) {
	if (q == NULL) {
		return c;
	}
	c++;
	int leftHeight = height(q->left, c);
	int rightHeight = height(q->right, c);
	return max(leftHeight, rightHeight);
}

int BST::findmin(node* T) {
	if (T == NULL) {
		cout << "\n SORRY! THE TREE DOESN'T EXIST";
		return -1;
	}
	while (T->left != NULL) {
		T = T->left;
	}
	return T->a;
}

void BST::swap(struct node* q) {
	if (q == NULL) {
		cout << "\n SORRY! THE TREE DOESN'T EXIST";
		return;
	}
	if (q->left != NULL)
		swap(q->left);
	if (q->right != NULL)
		swap(q->right);
	t = q->left;
	q->left = q->right;
	q->right = t;
}

void BST::search(struct node* root, int m) {
	if (root != NULL) {
		if (root->a == m) {
			cout << "\n" << m << " NODE IS FOUND!!!";
			return;
		}
		if (m > root->a)
			search(root->right, m);
		else
			search(root->left, m);
	}
	else {
		cout << "\n" << m << " NODE IS NOT FOUND!!!";
	}
}

void BST::display(struct node* q) {
	if (q == NULL) {
		cout << "\n SORRY! THE TREE DOESN'T EXIST";
		return;
	}
	cout << "\n" << q->a;
	if (q->left != NULL) {
		display(q->left);
	}
	if (q->right != NULL) {
		display(q->right);
	}
}

int main_BST() {
	BST b;
	int x, m, c = 0, cnt, min;
	do {
		cout << "\n\t\t ~~~CONSTRUCTION OF BINARY SEARCH TREE ~~~";

		cout << "\n 1. INSERT A NODE";
		cout << "\n 2. NUMBER OF NODES IN LONGEST PATH";
		cout << "\n 3. SMALLEST VALUE IN THE BST";
		cout << "\n 4. SWAP THE BST";
		cout << "\n 5. SEARCH AN ELEMENT";
		cout << "\n 6. DISPLAY THE BST";
		cout << "\n 7. EXIT THE PROGRAM";

		cout << "\n\n ENTER THE CHOICE OF OPERATION: ";

		cin >> x;
		switch (x) {
		case 1:
			b.insert();
			break;
		case 2:
			cnt = b.height(root, c);
			cout << "\n NO OF NODES IN LONGEST PATH: " << cnt;
			break;
		case 3:
			min = b.findmin(root);
			cout << "\n SMALLEST NODE IN THE BST: " << min;
			break;
		case 4:
			b.swap(root);
			break;
		case 5:
			cout << "\n ENTER THE NODE TO BE SEARCHED: ";
			cin >> m;
			b.search(root, m);
			break;
		case 6:
			b.display(root);
			break;
		case 7:
			exit(0);
		}
	} while (x != 7);
	return 0;
}
