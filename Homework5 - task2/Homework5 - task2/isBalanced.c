#include "..\..\Stack\Stack\Stack.h"
#include "isBalanced.h"
#include <stdlib.h>
#include <stdbool.h>

bool isBalanced(char string[], int length)
{	
	bool result = true;
	struct Stack* bracketStack = createStack();
	for (int i = 0; i < length; i++)
	{
		switch (string[i])
		{
		case '(':
			push(bracketStack, (int)'(');
			break;
		case ')':
			if (pop(bracketStack) != (int)'(')
			{
				result = false;
			}
			break;
		case '[':
			push(bracketStack, (int)'[');
			break;
		case ']':
			if (pop(bracketStack) != (int)'[')
			{
				result = false;
			}
			break;
		case '{':
			push(bracketStack, (int)'{');
			break;
		case '}':
			if (pop(bracketStack) != (int)'{')
			{
				result = false;
			}
			break;
		default:
			break;
		}
	}
	if (result && isEmpty(bracketStack))
	{
		deleteStack(&bracketStack);
		return true;
	}
	else
	{
		deleteStack(&bracketStack);
		return false;
	}
}