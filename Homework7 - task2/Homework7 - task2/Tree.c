#include "Tree.h"
#include "readFromFile.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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

Node* addNode(const char* string, int* index)
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
	newElement->left = addNode(string, index);
	newElement->right = addNode(string, index);
	return newElement;
}

Tree* createTree(const char* string)
{
	Tree* tree = calloc(1, sizeof(Tree));
	if (tree == NULL)
	{
		return NULL;
	}
	int index = 0;
	tree->root = addNode(string, &index);
	return tree;
}

void recursivePostfix(Node* node, char string[])
{	
	if (node == NULL)
	{
		return;
	}
	if (node->symbol == '\0')
	{	
		sprintf(string + strlen(string), "%i ", node->number);
		return;
	}
	sprintf(string + strlen(string), "( ");
	sprintf(string + strlen(string), "%c ", node->symbol);
	recursivePostfix(node->left, string);
	recursivePostfix(node->right, string);
	sprintf(string + strlen(string), ") ");
	return;
}

void getPostfixForm(Tree* tree, char string[])
{
	recursivePostfix(tree->root, string);
}

float binaryOperation(char operator, float firstNumber, float secondNumber)
{
	switch (operator)
	{
	case '+':
		return firstNumber + secondNumber;
	case '-':
		return firstNumber - secondNumber;
	case '*':
		return firstNumber * secondNumber;
	case '/':
		return firstNumber / secondNumber;
	default:
		return 0;
	}
}

float recursiveCounting(Node* node)
{
	if (node == NULL)
	{
		return 0;
	}
	if (node->symbol == '\0')
	{
		return (float)node->number;
	}
	float firstNumber = recursiveCounting(node->left);
	float secondNumber = recursiveCounting(node->right);
	return binaryOperation(node->symbol, firstNumber, secondNumber);
}

float countTreeValue(Tree* tree)
{
	return recursiveCounting(tree->root);
}

void recursiveDelete(Node* node)
{	
	if (node == NULL)
	{
		return;
	}
	recursiveDelete(node->left);
	recursiveDelete(node->right);
	free(node);
}

void deleteTree(Tree** tree)
{
	recursiveDelete((*tree)->root);
	free(*tree);
	(*tree) = NULL;
}