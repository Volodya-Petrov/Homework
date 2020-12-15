#include "testForTask.h"
#include "KMP.h"
#include "readFromFile.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool test(void)
{	
	bool result = true;
	char* string = readFromFile("test.txt");
	char testString[] = "abcabeabcabcabd";
	if (strcmp(string, testString) != 0)
	{
		result = false;
		printf("���� �� ������ � ����� ��������\n");
	}
	char substring[] = "abcabd";
	int array[6] = { 0 };
	int testArray[6] = { 0, 0, 0, 1, 2, 0 };
	prefixFunction(substring, array);
	for (int i = 0; i < 6; i++)
	{
		if (array[i] != testArray[i])
		{
			result = false;
			printf("���� �� ���������� ������� ��������\n");
			break;
		}
	}
	if (findSubstring(string, substring, array) != 9)
	{
		result = false;
		printf("����� ������� ��������\n");
	}
	free(string);
	return result;
}