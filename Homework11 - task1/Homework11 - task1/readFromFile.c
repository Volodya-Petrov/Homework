#include "readFromFile.h"
#include <stdio.h>
#include <stdlib.h>

char* readFromFile(char fileName[])
{
	int index = 0;
	int capacity = 1;
	char* string = (char*)malloc(capacity * sizeof(char));
	if (string == NULL)
	{
		return NULL;
	}
	FILE* fileOpen = fopen(fileName, "r");
	char charInReal = fgetc(fileOpen);
	while (charInReal != EOF)
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
				fclose(fileOpen);
				return NULL;
			}
			string = temp;
		}
		charInReal = fgetc(fileOpen);
	}
	string[index] = '\0';
	fclose(fileOpen);
	return string;
}