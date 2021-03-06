﻿#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

struct StackElement
{
	int number;
	struct StackElement* next;
};

struct Stack
{
	struct StackElement* head;
};

bool isEmpty(struct Stack* stack)
{
	return stack->head == NULL;
}

struct Stack* createStack(void)
{
	struct Stack* newStack = malloc(sizeof(struct Stack));
	if (newStack == NULL)
	{
		return NULL;
	}
	newStack->head = NULL;
	return newStack;
}

bool pop(struct Stack* stack, int* value)
{
	if (stack->head == NULL)
	{
		return false;
	}
	*value = stack->head->number;
	struct StackElement* oldElement = stack->head;
	stack->head = stack->head->next;
	free(oldElement);
	return true;
}

void push(struct Stack* stack, int value)
{
	struct StackElement* newElement = malloc(sizeof(struct StackElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->number = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

void deleteStack(struct Stack** stack)
{	
	int value = 0;
	while (pop(*stack, &value))
	{

	}
	free(*stack);
	*stack = NULL;
}