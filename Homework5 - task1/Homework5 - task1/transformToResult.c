#include "transformToResult.h"
#include "..\..\Stack\Stack\Stack.h"
#include <stdio.h>

int fromCharToInt(char symbol)
{
	switch (symbol)
	{
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case '0':
		return 0;
	default:
		return -1;
	}
}

int isDigit(char symbol)
{
	return symbol != -1;
}

int convertStrToInt(char string[], int beginIndex, int endIndex)
{
	int multiplier = 1;
	int number = 0;
	for (int i = endIndex - 1; i >= beginIndex; i--)
	{
		number += fromCharToInt(string[i]) * multiplier;
		multiplier *= 10;
	}
	return number;
}

int fromPostfixToInt(char string[], int size)
{	
	struct Stack* stack = createStack();
	for (int i = 0; i < size; i++)
	{	
		if (isDigit(string[i]))
		{	
			int beginOfNum = i;
			while (isDigit(string[i]) && i < size)
			{
				i++;
			}
			push(stack, convertStrToInt(string, beginOfNum, i));
		}
		else
		{
			switch (string[i])
			{
			case '+':
			{
				if (isEmpty(stack))
				{	
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				int number = pop(stack);
				if (isEmpty(stack))
				{	
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				number += pop(stack);
				push(stack, number);
				break;
			}
			case '-':
			{
				if (isEmpty(stack))
				{
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				int number = pop(stack);
				if (isEmpty(stack))
				{
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				number -= pop(stack);
				number *= -1;
				push(stack, number);
				break;
			}
			case '*':
			{
				if (isEmpty(stack))
				{
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				int number = pop(stack);
				if (isEmpty(stack))
				{
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				number *= pop(stack);
				push(stack, number);
				break;
				}
			case '/':
			{
				if (isEmpty(stack))
				{
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				int number = pop(stack);
				if (isEmpty(stack))
				{
					printf("Ошибка, невозможная операция\n");
					return 0;
				}
				number += pop(stack);
				push(stack, number);
				break;
			}
			}
		}
	}
	if (isEmpty(stack))
	{
		return 0;
	}
	int result = pop(stack);
	deleteStack(&stack);
	return result;
}
