#include "dynamicStringReader.h"
#include <stdio.h>
#include <stdlib.h>

char* stringReader(int* length)
{
	*length = 0;
	int capacity = 1;
	char* string = (char*)malloc(capacity * sizeof(char));
	char charInReal = getchar();
	while ( charInReal != '\n')
	{
		string[(*length)++] = charInReal;
		if (*length >= capacity)
		{
			capacity *= 2;
			string = (char*)realloc(string, capacity * sizeof(char));
		}
		charInReal = getchar();
	}
	string[*length] = '\0';
	return string;
}