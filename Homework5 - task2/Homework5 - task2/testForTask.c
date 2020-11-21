#include "isBalanced.h"
#include <stdio.h>

bool testBrackets(void)
{	
	bool result = true;
	if (!isBalanced("()[]{}({})"))
	{
		printf("Первый тест провален.\n");
		result = false;
	}
	if (isBalanced("{{{}})(){"))
	{
		printf("Второй тест провален.\n");
		result = false;
	}
	if (isBalanced("[({})][][]{})"))
	{
		printf("Второй тест провален.\n");
		result = false;
	}
	return result;
}