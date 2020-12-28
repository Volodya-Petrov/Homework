#include "Tree.h"
#include "readFromFile.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	int number;
	char symbol;
} Node;

typedef struct Tree
{
	Node* root;
} Tree;

bool isOperator(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

int convertToInt(const char* string, int* index)
{
	int beginIndex = *index;
	while (isdigit(string[*index]))
	{
		(*index)++;
	}
	int multiplier = 1;
	int number = 0;
	for (int i = *index - 1; i >= beginIndex; i--)
	{
		number += multiplier * (string[i] - 48);
		multiplier *= 10;
	}
	return number;
}

Node* addElement(const char* string, int* index)
{	
	int length = strlen(string);
	while (*index < length && !isdigit(string[*index]) && !isOperator(string[*index]))
	{
		(*index)++;
	}
	if (*index == length)
	{
		return NULL;
	}
	Node* newElement = calloc(1, sizeof(Node));
	if (newElement == NULL)
	{
		return NULL;
	}
	if (isdigit(string[*index]))
	{
		int number = convertToInt(string, index);
		newElement->number = number;
		return newElement;
	}
	if (string[*index] == '-' && isdigit(string[*index + 1]))
	{
		(*index)++;
		int number = -1 * convertToInt(string, index);
		newElement->number = number;
		return newElement;
	}
	newElement->symbol = string[*index];
	(*index)++;
	newElement->left = addElement(string, index);
	newElement->right = addElement(string, index);
	return newElement;
}

Tree* createTree(const char* fileName)
{
	Tree* tree = calloc(1, sizeof(Tree));
	if (tree == NULL)
	{
		return NULL;
	}
	char* string = readFromFile(fileName);
	int index = 0;
	tree->root = addElement(string, &index);
	free(string);
	return tree;
}

Tree