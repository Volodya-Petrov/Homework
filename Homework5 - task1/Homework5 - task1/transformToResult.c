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
	return fromCharToInt(symbol) != -1;
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
				int number1 = 0;
				int number2 = 0;
				if (!pop(stack, &number1))
				{	
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				if (!pop(stack, &number2))
				{	
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				int number = number1 + number2;
				push(stack, number);
				break;
			}
			case '-':
			{
				int number1 = 0;
				int number2 = 0;
				if (!pop(stack, &number1))
				{
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				if (!pop(stack, &number2))
				{
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				int number = number2 - number1;
				push(stack, number);
				break;
			}
			case '*':
			{
				int number1 = 0;
				int number2 = 0;
				if (!pop(stack, &number1))
				{
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				if (!pop(stack, &number2))
				{
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				int number = number1 * number2;
				push(stack, number);
				break;
			}
			case '/':
			{
				int number1 = 0;
				int number2 = 0;
				if (!pop(stack, &number1))
				{
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				if (!pop(stack, &number2))
				{
					printf("������, ����������� ��������\n");
					deleteStack(&stack);
					return 0;
				}
				int number = number2 / number1;
				push(stack, number);
				break;
			}
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
		printf("������������ ����������� ���\n");
		deleteStack(&stack);
		return 0;
	}
	deleteStack(&stack);
	return result;
}
