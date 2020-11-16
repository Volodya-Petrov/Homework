#include <stdlib.h>

typedef struct Node
{	
	int key;
	int height;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct Tree
{
	Node* root;
}Tree;

Node* createNode(int key)
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
	return newNode;
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
	/*if (tree->root == node)
	{
		tree->root = leftNode;
	}*/
	overHeight(node);
	overHeight(leftNode);
	return leftNode;
}

Node* leftRotation(Node* node)
{
	Node* rightNode = node->right;
	node->right = rightNode->left;
	rightNode->left = node;
	overHeight(rightNode);
	overHeight(node);
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

Node* insert(Node* node, int key)
{
	if (node == NULL)
	{
		return createNode(key);
	}
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	return balance(node);
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

Node* delete(Node* node, int key)
{
	if (node == NULL)
	{
		return 0;
	}
	if (key < node->key)
	{
		node->left = delete(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = delete(node->right, key);
	}
	else
	{
		Node* leftChild = node->left;
		Node* rightChild = node->right;
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