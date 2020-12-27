#include "testForTask.h"
#include "KMP.h"
#include "readFromFile.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	if (findSubstring(string, substring) != 9)
	{
		result = false;
		printf("����� ������� ��������\n");
	}
	free(string);
	return result;
}