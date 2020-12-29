#include "stateTable.h"
#include "readStateTableTest.h"
#include <stdbool.h>

bool testReadStateTable(void)
{
	int stateTable[4][3] = { 0 };
	int stateTableTest[4][3] = { {1, 2, 3}, {3, 2, 1}, {5, 4, 1}, {2, 4, 7} };
	readStateTable("testStateTable.txt", stateTable);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (stateTable[i][j] != stateTableTest[i][j])
			{
				return false;
			}
		}
	}
	return true;
}