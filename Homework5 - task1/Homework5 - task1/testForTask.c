#include "transformToResult.h"
#include "testForTask.h"
#include <stdbool.h>
#include <stdio.h>

bool tests(void)
{	
	bool result = true;
	char test1[] = "9 6 - 1 2 + *";
	if (fromPostfixToInt(test1) != 9)
	{
		printf("Первый тест провален\n");
		result = false;
	}
	char test2[] = "7 3 4 - *";
	if (fromPostfixToInt(test2) != -7)
	{
		printf("Второй тест провален\n");
		result = false;
	}
	char test3[] = "1 1 1 -";
	if (fromPostfixToInt(test3) != 0)
	{
		printf("Третий тест провален\n");
		result = false;
	}
	char test4[] = "5 5 - -";
	if (fromPostfixToInt(test4) != 0)
	{
		printf("Четвертый тест провален\n");
		result = false;
	}
	return result;
}