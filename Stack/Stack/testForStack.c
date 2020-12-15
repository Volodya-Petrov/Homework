#include "Stack.h"
#include "testForStack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool bigTest(void)
{	
	int valueForTest = 0;
	bool result = true;
	struct Stack* stack = createStack();
	push(stack, 9);
	push(stack, 8);
	pop(stack, &valueForTest);
	if (valueForTest != 8 )
	{
		printf("���� ��������, ��� ������� �� ��, ��� ���������\n");
		result = false;
	}
	if (isEmpty(stack))
	{
		printf("���� ��������, ���� �� ����\n");
		result = false;
	}
	pop(stack, &valueForTest);
	if (valueForTest != 9)
	{
		printf("���� ��������, ��� ������� �� ��, ��� ���������\n");
		result = false;
	}
	if (pop(stack, &valueForTest))
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