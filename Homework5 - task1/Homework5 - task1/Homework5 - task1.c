#include "dynamicStringReader.h"
#include "transformToResult.h"
#include <stdio.h>

int main(void)
{
	int length = 0;
	char* string = stringReader(&length);
	printf("%i", fromPostfixToInt(string, length));
	free(string);
}