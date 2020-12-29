#include "numbersLexer.h"
#include "dynamicStringReader.h"
#include "testsForTask.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!testResult())
	{
		printf("Тесты провалены\n");
		return 1;
	}
	printf("Тесты пройдены успешно!\n");
	printf("Введите строку: \n");
	char* string = readString();
	isNumber(string) ? printf("Данная строка является числом\n") : printf("Данная строка не является числом!\n");
}