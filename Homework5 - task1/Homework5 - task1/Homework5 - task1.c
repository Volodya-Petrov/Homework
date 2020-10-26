#include "dynamicStringReader.h"
#include "transformToResult.h"
#include "../../Stack/Stack/testForStack.h"
#include "testForTask.h"
#include <stdio.h>
#include <locale.h>

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
	int length = 0;
	char* string = stringReader(&length);
	printf("%i", fromPostfixToInt(string, length));
	free(string);
}