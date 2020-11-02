#include "List.h"
#include <stdlib.h>
#include <stdio.h>

void readFromFile(struct List* list, char fileName[])
{
	FILE* fileOpen = fopen(fileName, "r");
	char name[20] = "\0";
	char number[20] = "\0";
	while ((fscanf(fileOpen, "%s %s\n", name, number)) != EOF)
	{
		append(list, name, number);
	}
	fclose(fileOpen);
}