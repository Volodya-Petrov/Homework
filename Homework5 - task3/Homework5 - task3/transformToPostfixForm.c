#include "transformToPostfixForm.h"
#include "../../Stack/Stack/Stack.h"
#include <stdlib.h>
#include <stdbool.h>

bool isOperator(char symbol)
{
	switch (symbol)
	{
	case '(':
	case ')':
	case '-':
	case '+':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}

int getPriority(char symbol)
{
	switch (symbol)
	{
	case '(':
		return 1;
	case ')':
		return 2;
	case '+':
		return 3;
	case '-':
		return 4;
	case '*':
		return 5;
	case '/':
		return 5;
	default:
		return 0;
	}
}

bool isDigit(char symbol)
{
	switch (symbol)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}

char* infixToPostfix(char* string, int length)
{	
	struct Stack* stackForOper = createStack();
	char* postFixForm = calloc(length * 2, sizeof(char));
	if (postFixForm == NULL)
	{
		return NULL;
	}
	int indexInReal = 0;
	for (int i = 0; i < length; i++)
	{
		if (isDigit(string[i]))
		{
			while (isDigit(string[i]))
			{
				postFixForm[indexInReal] = string[i];
				indexInReal++;
				i++;
			}
			postFixForm[indexInReal] = ' ';
			indexInReal++;
		}
		if (isOperator(string[i]))
		{
			if (string[i] == '(')
			{
				push(stackForOper, (int)'(');
			}
			else if (string[i] == ')')
			{
				int operator = pop(stackForOper);
				while (operator != (int)'(')
				{
					postFixForm[indexInReal] = (char)operator;
					indexInReal++;
					postFixForm[indexInReal] = ' ';
					indexInReal++;
					operator = pop(stackForOper);
				}
			}
			else
			{
				if (!isEmpty(stackForOper))
				{	
					char operOnHead = (char)pop(stackForOper);
					if (getPriority(string[i]) <= getPriority(operOnHead))
					{
						postFixForm[indexInReal] = operOnHead;
						indexInReal++;
						postFixForm[indexInReal] = ' ';
						indexInReal++;
					}
					else
					{
						push(stackForOper, (int)operOnHead);
					}
				}
				push(stackForOper, (int)string[i]);
			}
		}
	}
	while (!isEmpty(stackForOper))
	{
		postFixForm[indexInReal] = (char)pop(stackForOper);
		indexInReal++;
		if (!isEmpty(stackForOper))
		{
			postFixForm[indexInReal] = ' ';
			indexInReal++;
		}
	}
	deleteStack(&stackForOper);
	return postFixForm;
}