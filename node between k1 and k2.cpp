// Tree traversal Algorithms Slight
// Preorder traversal print and then print the nodes between the given ranges

#include<iostream>
using namespace std;

class node {
public :
	int data;
	node *left;
	node *right;

	node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


node * insertInBST(node *root, int data) {
	if (root == NULL) {
		return new node(data);
	}
	if (data < root->data) { // insert in left subtree
		root->left = insertInBST(root->left, data);
	}
	else {
		root->right = insertInBST(root->right, data);
	}
	return root;
}



// Build the BST using the arrays
node *buildBST(int n) {
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		int data; cin >> data;
		root = insertInBST(root, data);
	}
	return root;
}

// data left right
void preOrder(node *root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}


void printTree(node *root, int k1 , int k2) {
	if (root == NULL) {
		return;
	}
	printTree(root->left, k1, k2);
	if (root->data >= k1 && root->data <= k2) {
		cout << root->data << " ";
	}
	printTree(root->right, k1, k2);
	return;
}


void inOrder(node *root) {
	if (root = NULL) {
		return;
	}
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
	return;
}


int main() {


	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		node *root = buildBST(n);
		int k1, k2; cin >> k1 >> k2;
		cout << "# Preorder : ";
		preOrder(root);
		cout << endl;
		cout << "# Nodes within range are : ";
		printTree(root, k1, k2);
		cout<<"\n";
	}
	return 0;
}