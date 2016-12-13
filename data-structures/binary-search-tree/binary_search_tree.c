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

/*
	Compute the size of a given BST (count the number of nodes, including
	the root)
*/
int size(struct node* node) {
	if (node == NULL) {
		return 0;
	} else {
		return(size(node->left) + 1 + size(node->right));
	}
}

/*
	Compute the max depth of a tree - the number of nodes along the longest
	path from the root node down to the farthest leaf node
*/
int maxDepth(struct node* node) {
	if (node == NULL) {
		return(0);
	} else {
		// Compute the depth of each subtree
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);

		// Return the larger of the two depths
		if (leftDepth > rightDepth) {
			return(leftDepth + 1);
		} else {
			return (rightDepth + 1);
		}
	}
}

/*
	Given a non-empty BST, return the minimum data value found in that
	tree.
*/
int minValue(struct node* node) {
	struct node* current = node;
	//loop to find the left most node
	while (current->left != NULL) {
		current = current->left;
	}

	return(current->data);
}

/*
	Given a BST, print out its data elements in increasing sorted order
*/
void printTree(struct node* node) {
	if (node == NULL) {
		return;
	} else {
		printTree(node->left);
		printf("%d ", node->data);
		printTree(node->right);
	}
}

/*
	Given a BST, print its nodes according to the "bottom-up" postorder
	traversal
*/
void printPostOrder(struct node* node) {
	if (node == NULL) {
		return;
	} else {
		// Recurse on both subtrees
		printTree(node->left);
		printTree(node->right);

		// Deal with the actual node
		printf("%d ", node->data);
	}
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
	printf("The size of this BST is: %d\n", size(a));
	printf("The max depth of this BST is: %d\n", maxDepth(a));
	printf("The minimum data value that exists in this tree is: %d\n", minValue(a));

	printf("\nNormal, increasing order printout:\n");
	printTree(a);
	printf("\n\nPost-Order printout:\n");
	printPostOrder(a);
	printf("\n");
	return 0;
}