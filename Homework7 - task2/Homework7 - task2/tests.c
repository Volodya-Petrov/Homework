#include "tests.h"
#include "Tree.h"
#include "readFromFile.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool testReadFromFile(void)
{	
	bool result = true;
	char testString[] = "( / ( + 5 ( * 3 ( + -1 16 ) ) ) ( * 2 -5 ) ) ";
	char* string = readFromFile("test.txt");
	if (strcmp(testString, string))
	{
		result = false;
	}
	free(string);
	return result;
}

bool getPostfixFormTest(void)
{	
	bool result = true;
	char* string = readFromFile("test.txt");
	Tree* tree = createTree(string);
	char* testString = calloc(strlen(string) * 2, sizeof(char));
	if (testString == NULL)
	{
		free(string);
		return false;
	}
	getPostfixForm(tree, testString);
	if (strcmp(string, testString))
	{
		result = false;
	}
	free(string);
	free(testString);
	deleteTree(&tree);
	return result;
}

bool countTreeValueTest(void)
{
	bool result = true;
	char* string = readFromFile("test.txt");
	Tree* tree = createTree(string);
	float value = countTreeValue(tree);
	if (value != -5.0f)
	{
		result = false;
	}
	free(string);
	deleteTree(&tree);
	return result;
}

bool testResult(void)
{
	return !countTreeValueTest() + !getPostfixFormTest() + !testReadFromFile();
}