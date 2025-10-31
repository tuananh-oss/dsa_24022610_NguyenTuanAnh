#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
	bool isBinaryTree(Node* temp, int min, int max) {
		if (temp == nullptr) {
			return true;
		}
		if (temp->data < min || temp->data > max) {
			return false;
		}
		return isBinaryTree(temp->left, min, temp->data) &&
			isBinaryTree(temp->right, temp->data, max);
	}

	int height(Node* root) {
		if (root == nullptr) return 0;
		return 1 + max(height(root->left), height(root->right));
	}

	bool isBalancedBST(Node* root) {
		if (root == nullptr) return true;

		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (abs(leftHeight - rightHeight) > 1)
			return false;

		return isBalancedBST(root->left) && isBalancedBST(root->right);
	}

	int put(Node* root, int val) {
		if (root == nullptr) {
			root->data = val;
			return 0;
		}
		if (val < root->data) {
			return put(root->left, val);
		}
		else if (val > root->data) {
			return put(root->right, val);
		}
		else {
			return -1;
		}
	}

	int get(Node* root, int val) {
		if (root == nullptr) {
			return -1;
		}
		if (val == root->data) {
			return root->data;
		}
		else if (val < root->data) {
			return get(root->left, val);
		}
		else {
			return get(root->right, val);
		}
	}

	int deleteNode(Node* root, int val) {
		if (root == nullptr) {
			return -1;
		}
		if (val < root->data) {
			return deleteNode(root->left, val);
		}
		else if (val > root->data) {
			return deleteNode(root->right, val);
		}
		else {
			int x = root->data;
			if (root->left == nullptr && root->right == nullptr) {
				int x = root->data;
				delete root;
				return x;
			}
			else if (root->left == nullptr) {
				Node* temp = root->right;
				int x = root->data;
				delete root;
				root = temp;
				return x;
			}
			else if (root->right == nullptr) {
				Node* temp = root->left;
				int x = root->data;
				delete root;
				root = temp;
				return x;
			}
			else {
				Node* parent = root;
				Node* child = root->right;
				while (child->left != nullptr) {
					parent = child;
					child = child->left;
				}
				root->data = child->data;
				if (parent != root) {
					parent->left = child->right;
				}
				else {
					parent->right = child->right;
				}
				delete child;
			}
			return x;
		}
	}
};

