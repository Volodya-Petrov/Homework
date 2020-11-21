#include "..\..\Stack\Stack\Stack.h"
#include "isBalanced.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isBalanced(char string[])
{	
	bool result = true;
	struct Stack* bracketStack = createStack();
	if (bracketStack == NULL)
	{
		return false;
	}
	for (int i = 0; i < strlen(string); i++)
	{
		switch (string[i])
		{
		case '(':
		case '{':
		case '[':
			push(bracketStack, string[i]);
			break;
		case ')':
		{	
			int getElement = 0;
			if (!pop(bracketStack, &getElement) || getElement != (int)'(')
			{
				result = false;
			}
			break;
		}
		case ']':
		{
			int getElement = 0;
			if (!pop(bracketStack, &getElement) || getElement != (int)'[')
			{
				result = false;
			}
			break;
		}
		case '}':
		{
			int getElement = 0;
			if (!pop(bracketStack, &getElement) || getElement != (int)'{')
			{
				result = false;
			}
			break;
		}
		default:
			break;
		}
	}
	if (result && isEmpty(bracketStack))
	{
		deleteStack(&bracketStack);
		return true;
	}
	deleteStack(&bracketStack);
	return false;
}