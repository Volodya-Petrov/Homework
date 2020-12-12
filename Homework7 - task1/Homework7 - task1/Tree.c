#include "Tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
	int key;
	char* value;
	struct Node* left;
	struct Node* right;
};

struct Dictionary
{
	struct Node* root;
};

struct Dictionary* createDictionary(void)
{
	return calloc(1, sizeof(struct Dictionary));
}

struct Node* createNode(int key, char value[])
{
	struct Node* newNode = calloc(1, sizeof(struct Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	char* newValue = calloc(strlen(value) + 1, sizeof(char));
	if (newValue == NULL)
	{
		free(newNode);
		return NULL;
	}
	strcpy(newValue, value);
	newNode->value = newValue;
	newNode->key = key;
	return newNode;
}

struct Node* getNodeForParent(struct Dictionary* dict, struct Node* parent, int key)
{
	if (dict == NULL)
	{
		return NULL;
	}
	if (parent == NULL)
	{
		return dict->root;
	}
	return key > parent->key ? parent->right : parent->left;
}

struct Node* getParent(struct Dictionary* dict, int key)
{
	if (dict == NULL || dict->root == NULL || dict->root->key == key)
	{
		return NULL;
	}
	struct Node* parent = dict->root;
	struct Node* currentNode = NULL;
	if (parent->key < key)
	{
		currentNode = parent->right;
	}
	else
	{
		currentNode = parent->left;
	}
	while (true)
	{
		if (currentNode == NULL || currentNode->key == key)
		{
			return parent;
		}
		if (key > currentNode->key)
		{
			parent = currentNode;
			currentNode = currentNode->right;
			continue;
		}
		parent = currentNode;
		currentNode = currentNode->left;
	}
}

void addElement(struct Dictionary* dict, int key, char value[])
{
	if (dict == NULL)
	{
		return;
	}
	struct Node* parent = getParent(dict, key);
	struct Node* node = getNodeForParent(dict, parent, key);
	if (parent == NULL && node == NULL)
	{
		dict->root = createNode(key, value);
		return;
	}
	if (node == NULL)
	{
		if (key > parent->key)
		{
			parent->right = createNode(key, value);
			return;
		}
		parent->left = createNode(key, value);
		return;
	}
	char* newValue = calloc(strlen(value) + 1, sizeof(char));
	if (newValue == NULL)
	{
		return;
	}
	free(node->value);
	node->value = newValue;
}

char* getValue(struct Dictionary* dict, int key)
{	
	if (dict == NULL)
	{
		return NULL;
	}
	struct Node* parent = getParent(dict, key);
	struct Node* node = getNodeForParent(dict, parent, key);
	if (node == NULL)
	{
		return NULL;
	}
	return node->value;
}

bool keyExists(struct Dictionary* dict, int key)
{	
	if (dict == NULL)
	{
		return false;
	}
	return getValue(dict, key) != NULL;
}

struct Node* getMaxLeftNode(struct Node* parent)
{
	struct Node* parentMax = parent;
	struct Node* nodeMax = parent->left;
	if (nodeMax->right == NULL)
	{
		parent->left = nodeMax->left;
		nodeMax->left = NULL;
		return nodeMax;
	}
	while (true)
	{
		if (nodeMax->right == NULL)
		{
			parentMax->right = nodeMax->left;
			nodeMax->left = NULL;
			return nodeMax;
		}
		parentMax = nodeMax;
		nodeMax = nodeMax->right;
	}
}

void deleteNode(struct Node* node)
{	
	if (node == NULL)
	{
		return;
	}
	free(node->value);
	free(node);
}

void nodeRotation(struct Dictionary* dict, struct Node* parent, struct Node* oldNode, struct Node* newNode)
{
	if (parent == NULL)
	{
		dict->root = newNode;
		return;
	}
	if (parent->right == oldNode)
	{
		parent->right = newNode;
		return;
	}
	parent->left = newNode;
}

void deleteElement(struct Dictionary* dict, int key)
{	
	if (dict == NULL)
	{
		return;
	}
	struct Node* parent = getParent(dict, key);
	struct Node* currentElement = getNodeForParent(dict, parent, key);
	if (currentElement->left == NULL && currentElement->right == NULL)
	{	
		nodeRotation(dict, parent, currentElement, NULL);
		deleteNode(currentElement);
		return;
	}
	if (currentElement->left == NULL && currentElement->right != NULL)
	{	
		nodeRotation(dict, parent, currentElement, currentElement->right);
		deleteNode(currentElement);
		return;
	}
	if (currentElement->left != NULL && currentElement->right == NULL)
	{
		nodeRotation(dict, parent, currentElement, currentElement->left);
		deleteNode(currentElement);
		return;
	}
	struct Node* maxLeft = getMaxLeftNode(currentElement);
	maxLeft->right = currentElement->right;
	maxLeft->left = currentElement->left;
	nodeRotation(dict, parent, currentElement, maxLeft);
	deleteNode(currentElement);
}

void deleteDict(struct Dictionary** dict)
{	
	if (*dict == NULL)
	{
		return;
	}
	while ((*dict)->root != NULL)
	{
		deleteElement(*dict, (*dict)->root->key);
	}
	free(*dict);
	*dict = NULL;
}