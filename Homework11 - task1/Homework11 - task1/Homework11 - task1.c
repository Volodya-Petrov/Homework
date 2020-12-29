#include "KMP.h"
#include "readFromFile.h"
#include "dynamicStringReader.h"
#include "testForTask.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!test())
	{
		return 1;
	}
	printf("Тесты пройдены успешно!\n");
	char* string = readFromFile("task.txt");
	printf("Введите подстроку:\n");
	char* substring = readString();
	int position = findSubstring(string, substring);
	position == -1 ? printf("Образец в строке не найден\n") : printf("Позиция образца в строке - %i", position);
	free(string);
	free(substring);
}