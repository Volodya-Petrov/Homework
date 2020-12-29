#include "readFromFile.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool readFileTest(void)
{	
	char stringTest[] = "gfdgorgrtgrt gtrkogrkotgro/****gfgdgdfgfdg******/\nhgfhgfh//*fff*f/*/gregreg/*ffff*/";
	char* string = readFromFile("test1.txt");
	if (strcmp(string, stringTest) != 0)
	{
		free(string);
		return false;
	}
	free(string);
	return true;
}