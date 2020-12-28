#include "List.h"
#include "comments.h"
#include "stateTable.h"
#include <stdio.h>
#include <string.h>

int getIndex(char symbol)
{
	switch (symbol)
	{
	case '/':
		return 0;
	case '*':
		return 1;
	default:
		return 2;
	}
}

List* getComments(const char* string)
{	
	if (string == NULL)
	{
		return NULL;
	}
	List* comments = createList();
	if (comments == NULL)
	{
		return NULL;
	}
	int stateTable[4][3] = { 0 };
	readStateTable("stateTable.txt", stateTable);
	int state = 0;
	int index = 0;
	int beginIndex = 0;
	int endIndex = 0;
	char currentChar = '\0';
	while (index != strlen(string))
	{	
		currentChar = string[index];
		int indexOfChar = getIndex(currentChar);
		int oldState = state;
		state = stateTable[state][indexOfChar];
		if (oldState == 1 && state == 2)
		{
			beginIndex = index - 1;
		}
		if (oldState == 3 && state == 0)
		{
			endIndex = index;
			append(comments, beginIndex, endIndex);
		}
		index++;
	}
	return comments;
}

void printComments(List* comments, const char* string)
{
	for (int i = 0; i < length(comments); i++)
	{
		int begin = 0;
		int end = 0;
		getValue(comments, i, &begin, &end);
		for (int j = begin; j <= end; j++)
		{
			printf("%c", string[j]);
		}
		printf("\n");
	}
}