#include "isBalanced.h"

bool testBrackets(void)
{	
	bool result = true;
	if (!isBalanced("()[]{}({})", 11))
	{
		printf("Первый тест провален.\n");
		result = false;
	}
	if (isBalanced("{{{}})(){", 10))
	{
		printf("Второй тест провален.\n");
		result = false;
	}
	if (isBalanced("[({})][][]{})", 14))
	{
		printf("Второй тест провален.\n");
		result = false;
	}
	return result;
}