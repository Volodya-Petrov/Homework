#include "..\..\Stack\Stack\Stack.h"
#include "isBalanced.h"
#include <stdlib.h>
#include <stdbool.h>

bool isBalanced(char string[], int length)
{
	struct Stack* bracketStack = createStack();
	for (int i = 0; i < length; i++)
	{
		switch (string[i])
		{
		case '(':
			push(bracketStack, 1);
			break;
		case ')':
			if (pop(bracketStack) != 1)
			{
				return false;
			}
			break;
		case '[':
			push(bracketStack, 2);
			break;
		case ']':
			if (pop(bracketStack) != 2)
			{
				return false;
			}
			break;
		case '{':
			push(bracketStack, 3);
			break;
		case '}':
			if (pop(bracketStack) != 3)
			{
				return false;
			}
			break;
		default:
			break;
		}
	}
	bool result = isEmpty(bracketStack);
	deleteStack(&bracketStack);
	return result;
}