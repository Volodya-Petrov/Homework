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
		printf("Тест зафейлен, поп вернула не то, что ожидалось\n");
		result = false;
	}
	if (isEmpty(stack))
	{
		printf("Тест зафейлен, стек не пуст\n");
		result = false;
	}
	if (pop(stack) != 9)
	{
		printf("Тест зафейлен, поп вернула не то, что ожидалось\n");
		result = false;
	}
	if (!isEmpty(stack))
	{
		printf("Тест зафейлен, стек пуст");
	}
	deleteStack(&stack);
	if (stack != NULL)
	{
		printf("deleteStack не правильно работает\n");
		result = false;
	}
	return result;
}