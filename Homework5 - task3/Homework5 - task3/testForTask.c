#include "testForTask.h"
#include "transformToPostfixForm.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool tests(void)
{	
	bool result = true;
	char test1Infix[] = "(1 + 1) * 2";
	char test1Postfix[] = "1 1 + 2 *";
	char* stringForCompare = infixToPostfix(test1Infix);
	if (strcmp(stringForCompare, test1Postfix))
	{
		printf("Первый тест провален!\n");
		result = false;
	}
	free(stringForCompare);
	char test2Infix[] = "1 + 2 + 3 * 2 + 3";
	char test2Postfix[] = "1 2 + 3 2 * 3 + +";
	stringForCompare = infixToPostfix(test2Infix);
	if (strcmp(stringForCompare, test2Postfix))
	{
		printf("Второй тест провален!\n");
		result = false;
	}
	free(stringForCompare);
	char test3Infix[] = "2 + 2*(3 + 5* (6 + 1))";
	char test3Postfix[] = "2 2 3 5 6 1 + * + * +";
	stringForCompare = infixToPostfix(test3Infix);
	if (strcmp(stringForCompare, test3Postfix))
	{
		printf("Третий тест провален!\n");
		result = false;
	}
	free(stringForCompare);
	return result;
}