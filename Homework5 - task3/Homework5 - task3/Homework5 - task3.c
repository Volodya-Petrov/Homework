#include "transformToPostfixForm.h"
#include "dynamicStringReader.h"
#include "testForTask.h"
#include "../../Stack/Stack/testForStack.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (tests())
	{
		printf("Тесты для задания пройдены успешно!\n");
	}
	else
	{
		return 1;
	}
	if (bigTest())
	{
		printf("Тесты для стека пройдены успешно\n");
	}
	else
	{
		return 1;
	}
	printf("Введите выражение в инфиксной форме\n");
	char* infixForm = readString();
	char* postfixForm = infixToPostfix(infixForm);
	printf("Выражение в постфиксном виде:\n");
	printf("%s", postfixForm);
	free(infixForm);
	free(postfixForm);
}