#include "getPosition.h"
#include "List.h"
#include <stdlib.h>

int getPos(int count, int period)
{
	if (count <= 0 || period <= 0)
	{
		return -1;
	}
	struct List* list = createList();
	if (list == NULL)
	{
		return -1;
	}
	for (int i = 1; i < count + 1; i++)
	{
		if (!append(list, i))
		{
			deleteList(&list);
			return -1;
		}
	}
	int step = 1;
	int index = 0;
	while (getLength(list) != 1)
	{
		if (index == getLength(list))
		{
			index = 0;
		}
		if (step == period)
		{
			step = 1;
			deleteElement(list, index);
			continue;
		}
		index++;
		step++;
	}
	int result = getValue(list, 0);
	deleteList(&list);
	return result;
}