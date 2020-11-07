#include "Tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Leaf
{
	int key;
	char* value;
	struct Leaf* left;
	struct Leaf* right;
};

struct Dictionary
{
	struct Leaf* root;
};

struct Dictionary* createDictionary(void)
{
	struct Dictionary* newDict = calloc(1, sizeof(struct Dictionary));
	return newDict;
}

void addElement(struct Dictionary* dict, int key, char value[])
{
	if (dict->root == NULL)
	{
		struct Leaf* newElement = malloc(sizeof(struct Leaf));
		if (newElement == NULL)
		{
			return;
		}
		char* newValue = malloc(sizeof(char) * strlen(value));
		if (newValue == NULL)
		{
			free(newElement);
			return;
		}
		strcpy(newValue, value);
		newElement->key = key;
		newElement->value = newValue;
		newElement->left = NULL;
		newElement->right = NULL;
		dict->root = newElement;
		return;
	}
	struct Leaf* currentRoot = dict->root;
	while (true)
	{	
		if (key == currentRoot->key)
		{
			char* newValue = malloc(sizeof(char) * strlen(value));
			if (newValue == NULL)
			{
				return;
			}
			strcpy(newValue, value);
			currentRoot->value = newValue;
			return;
		}
		if (key > currentRoot->key)
		{
			if (currentRoot->right == NULL)
			{
				struct Leaf* newElement = malloc(sizeof(struct Leaf));
				if (newElement == NULL)
				{
					return;
				}
				char* newValue = malloc(sizeof(char) * strlen(value));
				if (newValue == NULL)
				{
					free(newElement);
					return;
				}
				newElement->key = key;
				strcpy(newValue, value);
				newElement->value = newValue;
				newElement->left = NULL;
				newElement->right = NULL;
				currentRoot->right = newElement;
				return;
			}
			currentRoot = currentRoot->right;
			continue;
		}
		if (key < currentRoot->key)
		{
			if (currentRoot->left == NULL)
			{
				struct Leaf* newElement = malloc(sizeof(struct Leaf));
				if (newElement == NULL)
				{
					return;
				}
				char* newValue = malloc(sizeof(char) * strlen(value));
				if (newValue == NULL)
				{
					free(newElement);
					return;
				}
				newElement->key = key;
				strcpy(newValue, value);
				newElement->value = newValue;
				newElement->left = NULL;
				newElement->right = NULL;
				currentRoot->left = newElement;
				return;
			}
			currentRoot = currentRoot->left;
		}
	}
}

char* getValue(struct Dictionary* dict, int key)
{
	struct Leaf* currentElement = dict->root;
	while (true)
	{
		if (currentElement == NULL)
		{
			return NULL;
		}
		if (key == currentElement->key)
		{
			return currentElement->value;
		}
		if (key > currentElement->key)
		{
			currentElement = currentElement->right;
			continue;
		}
		currentElement = currentElement->left;
	}
}

bool keyExists(struct Dictionary* dict, int key)
{
	return !(getValue(dict, key) == NULL);
}

void deleteElement(struct Dictionary* dict, int key)
{
	struct Leaf* parent = NULL;
	struct Leaf* currentElement = dict->root;
	bool found = false;
	while (!found)
	{	
		if (currentElement == NULL)
		{
			return;
		}
		if (currentElement->key == key)
		{
			found = true;
		}
		if (currentElement->key > key)
		{
			parent = currentElement;
			currentElement = currentElement->left;
		}
		if (currentElement->key < key)
		{
			parent = currentElement;
			currentElement = currentElement->right;
		}
	}
	if (currentElement->left == NULL && currentElement->right == NULL)
	{	
		if (parent == NULL)
		{
			dict->root = NULL;
			free(currentElement->value);
			free(currentElement);
			return;
		}
		if (parent->right == currentElement)
		{
			parent->right = NULL;
		}
		else
		{
			parent->left = NULL;
		}
		free(currentElement->value);
		free(currentElement);
		return;
	}
	if (currentElement->left == NULL && currentElement->right != NULL)
	{	
		if (parent == NULL)
		{
			dict->root = currentElement->right;
			free(currentElement->value);
			free(currentElement);
			return;
		}
		if (parent->left == currentElement)
		{
			parent->left = currentElement->right;
		}
		else
		{
			parent->right = currentElement->right;
		}
		free(currentElement->value);
		free(currentElement);
		return;
	}
	if (currentElement->left != NULL && currentElement->right == NULL)
	{
		if (parent == NULL)
		{
			dict->root = currentElement->left;
			free(currentElement->value);
			free(currentElement);
			return;
		}
		if (parent->left == currentElement)
		{
			parent->left = currentElement->left;
		}
		else
		{
			parent->right = currentElement->left;
		}
		free(currentElement->value);
		free(currentElement);
		return;
	}
	struct Leaf* maxLeftPar = currentElement;
	struct Leaf* maxLeft = currentElement->left;
	found = false;
	while (!found)
	{
		if (maxLeft->right == NULL)
		{
			found = true;
		}
		else
		{
			maxLeftPar = maxLeft;
			maxLeft = maxLeft->right;
		}
	}
	currentElement->key = maxLeft->key;
	strcpy(currentElement->value, maxLeft->value);
	if (maxLeft->left == NULL)
	{	
		if (maxLeftPar == currentElement)
		{
			maxLeftPar->left = NULL;
		}
		else
		{
			maxLeftPar->right = NULL;
		}
		free(maxLeft->value);
		free(maxLeft);
		return;
	}
	if (maxLeftPar == currentElement)
	{
		maxLeftPar->left = maxLeft->left;
	}
	else
	{
		maxLeftPar->right = maxLeft->left;
	}
	free(maxLeft->value);
	free(maxLeft);
	return;
}

void deleteDict(struct Dictionary** dict)
{
	while ((*dict)->root != NULL)
	{
		deleteElement(*dict, (*dict)->root->key);
	}
	free(*dict);
	*dict = NULL;
}