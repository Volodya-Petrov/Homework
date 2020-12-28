#include "readFromFile.h"
#include "List.h"
#include "comments.h"
#include <stdbool.h>
#include <stdlib.h>

bool testForTask(void)
{
	bool result = true;
	char* string = readFromFile("test1.txt");
	List* comments = getComments(string);
	int firstIndex = 0;
	int secondIndex = 0;
	if (length(comments) != 3)
	{
		result = false;
	}
	getValue(comments, 0, &firstIndex, &secondIndex);
	if (firstIndex != 26 || secondIndex != 48)
	{
		result = false;
	}
	getValue(comments, 1, &firstIndex, &secondIndex);
	if (firstIndex != 58 || secondIndex != 67)
	{
		result = false;
	}
	getValue(comments, 2, &firstIndex, &secondIndex);
	if (firstIndex != 75 || secondIndex != 82)
	{
		result = false;
	}
	free(string);
	deleteList(&comments);
	return result;
}