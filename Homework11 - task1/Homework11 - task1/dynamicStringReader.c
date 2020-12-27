#include "dynamicStringReader.h"
#include <stdio.h>
#include <stdlib.h>

char* readString(void)
{
	int index = 0;
	int capacity = 1;
	char* string = (char*)malloc(capacity * sizeof(char));
	if (string == NULL)
	{
		return NULL;
	}
	char charInReal = getchar();
	while (charInReal != '\n')
	{
		string[index] = charInReal;
		index++;
		if (index >= capacity)
		{
			capacity *= 2;
			char* temp = (char*)realloc(string, capacity * sizeof(char));
			if (temp == NULL)
			{
				free(string);
				return NULL;
			}
			string = temp;
		}
		charInReal = getchar();
	}
	string[index] = '\0';
	return string;
}