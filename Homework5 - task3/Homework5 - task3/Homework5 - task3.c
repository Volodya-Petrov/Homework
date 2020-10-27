﻿#include "transformToPostfixForm.h"
#include "dynamicStringReader.h"
#include "../../Stack/Stack/testForStack.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
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