#include "Stack.h"
#include "testForStack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool bigTest(void)
{	
	bool result = true;
	struct Stack* stack = createStack();
	push(stack, 9);
	push(stack, 8);
	if (pop(stack) != 8)
	{
		printf("���� ��������, ��� ������� �� ��, ��� ���������\n");
		result = false;
	}
	if (isEmpty(stack))
	{
		printf("���� ��������, ���� �� ����\n");
		result = false;
	}
	if (pop(stack) != 9)
	{
		printf("���� ��������, ��� ������� �� ��, ��� ���������\n");
		result = false;
	}
	if (!isEmpty(stack))
	{
		printf("���� ��������, ���� ����");
	}
	deleteStack(&stack);
	if (stack != NULL)
	{
		printf("deleteStack �� ��������� ��������\n");
		result = false;
	}
	return result;
}