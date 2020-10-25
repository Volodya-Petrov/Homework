#include "isBalanced.h"

bool testBrackets(void)
{	
	bool result = true;
	if (!isBalanced("()[]{}({})", 11))
	{
		printf("������ ���� ��������.\n");
		result = false;
	}
	if (isBalanced("{{{}})(){", 10))
	{
		printf("������ ���� ��������.\n");
		result = false;
	}
	if (isBalanced("[({})][][]{})", 14))
	{
		printf("������ ���� ��������.\n");
		result = false;
	}
	return result;
}