#include "List.h"
#include "comments.h"
#include "readFromFile.h"
#include "ListTests.h"
#include "readFromFileTest.h"
#include "testForTask.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!listTest() || !readFileTest() || !testForTask())
	{
		printf("Тесты провалены\n");
		return 1;
	}
	printf("Тесты пройдены успешно!\n");
	char* string = readFromFile("task.txt");
	List* comments = getComments(string);
	printComments(comments, string);
	free(string);
	deleteList(&comments);
}