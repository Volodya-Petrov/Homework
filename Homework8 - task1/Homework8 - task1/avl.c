#include "avl.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{	
	int key;
	char* value;
	int height;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Tree
{
	Node* root;
}Tree;

char* createValue(char* value)
{
	char* newValue = malloc(strlen(value) + 1);
	if (newValue == NULL)
	{
		return NULL;
	}
	strcpy(newValue, value);
	return newValue;
}

Node* createNode(int key, char* value)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	newNode->key = key;
	newNode->value = createValue(value);
	return newNode;
}

Tree* createTree()
{
	Tree* newTree = calloc(1, sizeof(Tree));
	return newTree;
}

int height(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return node->height;
}

int balanceFactor(Node* node)
{
	return height(node->right) - height(node->left);
}

void overHeight(Node* node)
{
	int hleft = height(node->left);
	int hright = height(node->right);
	node->height = (hright > hleft ? hright : hleft) + 1;
}

Node* rightRotation(Node* node)
{
	Node* leftNode = node->left;
	node->left = leftNode->right;
	leftNode->right = node;
	overHeight(node);
	overHeight(leftNode);
	return leftNode;
}

Node* leftRotation(Node* node)
{
	Node* rightNode = node->right;
	node->right = rightNode->left;
	rightNode->left = node;
	overHeight(node);
	overHeight(rightNode);
	return rightNode;
}

Node* balance(Node* node)
{
	overHeight(node);
	if (balanceFactor(node) == 2)
	{
		if (balanceFactor(node->right) < 0)
		{
			node->right = rightRotation(node->right);
		}
		return leftRotation(node);
	}
	if (balanceFactor(node) == -2)
	{
		if (balanceFactor(node->left) > 0)
		{
			node->left = leftRotation(node->left);
		}
		return rightRotation(node);
	}
	return node;
}

Node* insertNode(Node* node, int key, char* value)
{
	if (node == NULL)
	{
		return createNode(key, value);
	}
	if (key < node->key)
	{
		node->left = insertNode(node->left, key, value);
	}
	if (key > node->key)
	{
		node->right = insertNode(node->right, key, value);
	}
	if (key == node->key)
	{
		char* newValue = createValue(value);
		if (newValue == NULL)
		{
			return balance(node);
		}
		free(node->value);
		node->value = newValue;
	}
	return balance(node);
}

void insert(Tree* tree, int key, char* value)
{
	if (tree == NULL)
	{
		return;
	}
	tree->root = insertNode(tree->root, key, value);
}

Node* searchMin(Node* node)
{
	if (node->left)
	{
		return searchMin(node->left);
	}
	else
	{
		return node;
	}
}

Node* deleteMin(Node* node)
{
	if (node->left == NULL)
	{
		return node->right;
	}
	node->left = deleteMin(node->left);
	return balance(node);
}

Node* deleteNode(Node* node, int key)
{
	if (node == NULL)
	{
		return 0;
	}
	if (key < node->key)
	{
		node->left = deleteNode(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = deleteNode(node->right, key);
	}
	else
	{
		Node* leftChild = node->left;
		Node* rightChild = node->right;
		free(node->value);
		free(node);
		if (rightChild == NULL)
		{
			return leftChild;
		}
		Node* min = searchMin(rightChild);
		min->right = deleteMin(rightChild);
		min->left = leftChild;
		return balance(min);
	}
	return balance(node);
}

void delete(Tree* tree, int key)
{
	tree->root = deleteNode(tree->root, key);
}

void deleteTree(Tree** tree)
{
	if (tree == NULL)
	{
		return;
	}
	while ((*tree)->root != NULL)
	{
		((*tree)->root) = deleteNode((*tree)->root, (*tree)->root->key);
	}
	free(*tree);
	*tree = NULL;
}

const char* getValue(Tree* tree, int key)
{	
	if (tree == NULL)
	{
		return NULL;
	}
	Node* currentNode = tree->root;
	while (true)
	{
		if (currentNode == NULL)
		{
			return NULL;
		}
		if (currentNode->key == key)
		{
			return currentNode->value;
		}
		if (currentNode->key > key)
		{
			currentNode = currentNode->left;
			continue;
		}
		if (currentNode->key < key)
		{
			currentNode = currentNode->right;
		}
	}
}

bool checkExist(Tree* tree, int key)
{
	if (getValue(tree, key) == NULL)
	{
		return false;
	}
	return true;
}