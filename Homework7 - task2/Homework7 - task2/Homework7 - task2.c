#include "Tree.h"
#include "tests.h"
#include "readFromFile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (testResult())
	{
		printf("Тесты провалены!\n");
		return 1;
	}
	printf("Тесты пройдены успешно\n");
	char* string = readFromFile("task.txt");
	Tree* tree = createTree(string);
	char* newString = calloc(2 * strlen(string), sizeof(char));
	getPostfixForm(tree, newString);
	printf("%s\n", newString);
	float result = countTreeValue(tree);
	printf("Значение дерева: %f\n", result);
	deleteTree(&tree);
	free(string);
	free(newString);
}