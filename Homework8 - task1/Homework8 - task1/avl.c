#include "avl.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{	
	char* key;
	char* value;
	int height;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct Tree
{
	Node* root;
} Tree;

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

Node* createNode(char* key, char* value)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	newNode->key = createValue(key);
	newNode->value = createValue(value);
	return newNode;
}

Tree* createTree(void)
{
	return calloc(1, sizeof(Tree));
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

void updateHeight(Node* node)
{
	int heightLeft = height(node->left);
	int heightRight = height(node->right);
	node->height = (heightRight > heightLeft ? heightRight : heightLeft) + 1;
}

Node* rightRotation(Node* node)
{
	Node* leftNode = node->left;
	node->left = leftNode->right;
	leftNode->right = node;
	updateHeight(node);
	updateHeight(leftNode);
	return leftNode;
}

Node* leftRotation(Node* node)
{
	Node* rightNode = node->right;
	node->right = rightNode->left;
	rightNode->left = node;
	updateHeight(node);
	updateHeight(rightNode);
	return rightNode;
}

Node* balance(Node* node)
{
	updateHeight(node);
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

Node* insertNode(Node* node, char* key, char* value)
{
	if (node == NULL)
	{
		return createNode(key, value);
	}
	if (strcmp(key, node->key) < 0)
	{
		node->left = insertNode(node->left, key, value);
	}
	if (strcmp(key, node->key) > 0)
	{
		node->right = insertNode(node->right, key, value);
	}
	if (strcmp(key, node->key) == 0)
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

void insert(Tree* tree, char* key, char* value)
{
	if (tree == NULL)
	{
		return;
	}
	tree->root = insertNode(tree->root, key, value);
}

Node* searchMin(Node* node)
{
	return node->left == NULL ? node : searchMin(node->left);
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

Node* deleteNode(Node* node, char* key)
{
	if (node == NULL)
	{
		return 0;
	}
	if (strcmp(key, node->key) < 0)
	{
		node->left = deleteNode(node->left, key);
	}
	else if (strcmp(key, node->key) > 0)
	{
		node->right = deleteNode(node->right, key);
	}
	else
	{
		Node* leftChild = node->left;
		Node* rightChild = node->right;
		free(node->key);
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

const char* getValue(Tree* tree, char* key)
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
		if (strcmp(key, currentNode->key) == 0)
		{
			return currentNode->value;
		}
		if (strcmp(key, currentNode->key) < 0)
		{
			currentNode = currentNode->left;
			continue;
		}
		if (strcmp(key, currentNode->key) > 0)
		{
			currentNode = currentNode->right;
		}
	}
}

bool checkExist(Tree* tree, char* key)
{
	return !(getValue(tree, key) == NULL);
}