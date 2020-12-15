#include "KMP.h"
#include <stdlib.h>
#include <string.h>

void prefixFunction(char* substring, int prefixArray[])
{	
	if (substring == NULL || prefixArray == NULL)
	{
		return;
	}
	prefixArray[0] = 0;
	int length = strlen(substring);
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

int findSubstring(char* string, char* substring, int prefixArray[])
{	
	if (string == NULL || substring == NULL || prefixArray == NULL)
	{
		return -1;
	}
	int j = 0;
	int length = strlen(string);
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
			return i - j + 1;
		}
	}
	return -1;
}