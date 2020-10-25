#include "dynamicStringReader.h"
#include "isBalanced.h"
#include "testForTask.h"
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (testBrackets())
	{
		printf("Тесты на баланс скобок пройдены успешно\n");
	}
	else
	{
		return 1;
	}
	printf("Введите последовательность скобок:\n");
	int length = 0;
	char* string = stringReader(&length);
	if (isBalanced(string, length))
	{
		printf("Баланс скобок соблюден!\n");
	}
	else
	{
		printf("Баланс скобок нарушен!\n");
	}
	free(string);
}