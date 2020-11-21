#include "isBalanced.h"
#include <stdio.h>

bool testBrackets(void)
{	
	bool result = true;
	if (!isBalanced("()[]{}({})"))
	{
		printf("������ ���� ��������.\n");
		result = false;
	}
	if (isBalanced("{{{}})(){"))
	{
		printf("������ ���� ��������.\n");
		result = false;
	}
	if (isBalanced("[({})][][]{})"))
	{
		printf("������ ���� ��������.\n");
		result = false;
	}
	return result;
}