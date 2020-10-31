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
	int length = 0;
	char* infixForm = stringReader(&length);
	char* postfixForm = infixToPostfix(infixForm, length);
	printf("Выражение в постфиксном виде:\n");
	printf("%s", postfixForm);
	free(infixForm);
	free(postfixForm);
}