#include "transformToResult.h"
#include "..\..\Stack\Stack\Stack.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int fromCharToInt(char symbol)
{
	if (isdigit(symbol) == 0)
	{
		return -1;
	}
	return symbol - '0';
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

int fromPostfixToInt(char string[])
{	
	struct Stack* stack = createStack();
	for (int i = 0; i < strlen(string); i++)
	{	
		if (isdigit(string[i]))
		{	
			int beginOfNum = i;
			while (isdigit(string[i]) && i < strlen(string))
			{
				i++;
			}
			push(stack, convertStrToInt(string, beginOfNum, i));
		}
		else if (string[i] == ' ')
		{
			continue;
		}
		else
		{	
			int number1 = 0;
			int number2 = 0;
			if (!pop(stack, &number1))
			{
				printf("Ошибка, невозможная операция\n");
				deleteStack(&stack);
				return 0;
			}
			if (!pop(stack, &number2))
			{
				printf("Ошибка, невозможная операция\n");
				deleteStack(&stack);
				return 0;
			}
			switch (string[i])
			{
			case '+':
				push(stack, number1 + number2);
				break;
			case '-':
				push(stack, number2 - number1);
				break;
			case '*':
				push(stack, number1 * number2);
				break;
			case '/':
				push(stack, number2 / number1);
				break;
			}
		}
	}
	int result = 0;
	if (!pop(stack, &result))
	{
		deleteStack(&stack);
		return 0;
	}
	if (!isEmpty(stack))
	{	
		printf("Некорректный постфиксный вид\n");
		deleteStack(&stack);
		return 0;
	}
	deleteStack(&stack);
	return result;
}
