#include "dynamicStringReader.h"
#include "..\..\Stack\Stack\testForStack.h"
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
	if (bigTest())
	{
		printf("Тесты стека пройдены успешно!\n");
	}
	else
	{
		return 1;
	}
	printf("Введите последовательность скобок:\n");
	char* string = readString();
	if (isBalanced(string))
	{
		printf("Баланс скобок соблюден!\n");
	}
	else
	{
		printf("Баланс скобок нарушен!\n");
	}
	free(string);
}