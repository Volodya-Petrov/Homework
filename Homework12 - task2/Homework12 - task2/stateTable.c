#include "stateTable.h"
#include <stdlib.h>
#include <stdio.h>

void readStateTable(const char* fileName, int stateTable[4][3])
{
	FILE* fileOpen = fopen(fileName, "r");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fscanf(fileOpen, "%i", &(stateTable[i][j]));
		}
	}
	fclose(fileOpen);
}