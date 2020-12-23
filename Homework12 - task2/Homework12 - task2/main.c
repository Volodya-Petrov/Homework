#include "List.h"
#include "comments.h"
#include "readFromFile.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	char* string = readFromFile("task.txt");
	List* comments = getComments(string);
	printComments(comments, string);
}