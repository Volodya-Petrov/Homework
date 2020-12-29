#include "List.h"
#include "ListTests.h"
#include <stdbool.h>

bool listTest(void)
{	
	bool result = true;
	List* list = createList();
	append(list, 0, 5);
	append(list, 3, 5);
	append(list, 2, 6);
	append(list, 7, 3);
	if (length(list) != 4)
	{
		result = false;
	}
	int firstNum = 0;
	int secondNum = 0;
	getValue(list, 2, &firstNum, &secondNum);
	if (firstNum != 2 || secondNum != 6)
	{
		result = false;
	}
	deleteElement(list, 0);
	getValue(list, 0, &firstNum, &secondNum);
	if (firstNum != 3 || secondNum != 5)
	{
		result = false;
	}
	if (length(list) != 3)
	{
		result = false;
	}
	deleteList(&list);
	return result;
}