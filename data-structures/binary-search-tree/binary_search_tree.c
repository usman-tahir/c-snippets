#include <stdio.h>
#include <stdlib.h>

// Basic definition of a node in a Binary Search Tree
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/*
	A helper function that allocates a new node with the given data
	and NULL left and right pointers
*/
struct node* newNode(int data) {
	struct node* node = new (struct node);
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/*
	Given a Binary Tree, return true if a node with the target data
	is found in the tree. Recurse down the tree, and choose the left
	or right branch by comparing the target to each node.
*/
static int lookup(struct node* node, int target) {
	// Base case: an empty tree (the target is not found; return false) {
	if (node == NULL) {
		return(false);
	} else {
		if (target == node->data) {
			return(true);
		} else {
			if (target < node->data) {
				return(lookup(node->left, target));
			} else {
				return(lookup(node->right, target));
			}
		}
	}
}

/*
	Given a binary search tree and a number, inserts a new node with the
	given number in the correct place in the tree. Returns the new root
	pointer, which the caller should then use
*/
struct node* insert(struct node* node, int data) {
	// If the tree is empty, return a new, single node
	if (node == NULL) {
		return(newNode(data));
	} else {
		// Recurse down the tree
		if (data <= node->data) {
			node->left = insert(node->left, data);
		} else {
			node->right = insert(node->right, data);
		}
	}

	// Return the unchanged node pointer
	return(node);
}

struct node* build123() {
	struct node* root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);

	return(root);
}

int main() {
	struct node* a = build123();

	int search;
	printf("Enter a number to search the BST: ");
	scanf("%d", &search);

	int result = lookup(a, search);
	if (result == 1) {
		printf("%d is in the BST\n", search);
	} else {
		printf("%d is not in the BST\n", search);
	}
	return 0;
}