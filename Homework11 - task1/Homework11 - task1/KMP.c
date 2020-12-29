#include "KMP.h"
#include <stdlib.h>
#include <string.h>

void prefixFunction(const char* substring, int prefixArray[])
{	
	if (substring == NULL || prefixArray == NULL)
	{
		return;
	}
	prefixArray[0] = 0;
	const int length = strlen(substring);
	for (int i = 1; i < length; i++)
	{
		int j = prefixArray[i - 1];
		while ((j > 0) && (substring[i] != substring[j]))
		{
			j = prefixArray[j - 1];
		}
		if (substring[i] == substring[j])
		{
			j++;
		}
		prefixArray[i] = j;
	}
}

int findSubstring(const char* string, const char* substring)
{	
	if (string == NULL || substring == NULL)
	{
		return -1;
	}
	int* prefixArray = calloc(strlen(substring), sizeof(int));
	if (prefixArray == NULL)
	{
		return -1;
	}
	prefixFunction(substring, prefixArray);
	int j = 0;
	const int length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		while ((j > 0) && (string[i] != substring[j]))
		{
			j = prefixArray[j - 1];
		}
		if (string[i] == substring[j])
		{
			j++;
		}
		if (j == strlen(substring))
		{	
			free(prefixArray);
			return i - j + 1;
		}
	}
	free(prefixArray);
	return -1;
}