#include "List.h"

bool testList(void)
{	
	bool result = true;
	List* list = createList();
	append(list, 54);
	append(list, 8);
	append(list, 6);
	if (length(list) != 3)
	{
		result = false;
	}
	if (indexOf(list, 8) != 1)
	{
		result = false;
	}
	int value = 0;
	getValue(list, 0, &value);
	if (value != 54)
	{
		result = false;
	}
	deleteList(&list);
	return result;
}