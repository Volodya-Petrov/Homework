#include "dynamicStringReader.h"
#include "transformToResult.h"
#include "../../Stack/Stack/testForStack.h"
#include "testForTask.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (bigTest())
	{
		printf("Тесты для стека пройдены успешно!\n");
	}
	else
	{
		return 1;
	}
	if (tests())
	{
		printf("Тесты для задания пройдены успешно!\n");
	}
	else
	{
		return 1;
	}
	printf("Введите арифметическое выражение в постфиксной форме\n");
	char* string = readString();
	printf("%i", fromPostfixToInt(string));
	free(string);
}