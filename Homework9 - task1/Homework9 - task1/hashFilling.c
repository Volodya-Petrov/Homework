#include "hashFilling.h"
#include "hashTable.h"
#include <stdio.h>

void fillTable(HashTable* table, char fileName[])
{	
	char value[20] = "";
	FILE* fileOpen = fopen(fileName, "r");
	while (fscanf(fileOpen, "%s", value) != EOF)
	{
		add(table, value);
	}
	fclose(fileOpen);
}