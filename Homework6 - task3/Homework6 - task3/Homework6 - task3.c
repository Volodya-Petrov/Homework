#include "List.h"
#include <stdio.h>

int main(void)
{
	struct List* newList = createList();
	append(newList, "Bob", "228");
	append(newList, "John", "1488");
	append(newList, "Garry", "1337");
	append(newList, "Lean", "2002");
	char name[20] = "\0";
	getValue(newList, 2, 0, name);
	changeValue(newList, 3, 1, "5555");
	deleteElement(newList, 0);
	deleteList(&newList);
}