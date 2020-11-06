#include "List.h"
#include "Tests.h"
#include <stdio.h>

bool tests(void)
{	
	bool result = true;
	struct List* list = createList();
	append(list, 8);
	append(list, 5);
	append(list, 2);
	append(list, 1);
	if (getLength(list) != 4)
	{
		result = false;
		printf("Неверная длина 1\n");
	}
	if (indexOf(list, 2) != 2)
	{
		result = false;
		printf("Неверный индекс 1\n");
	}
	deleteElement(list, 0);
	if (getLength(list) != 3)
	{
		result = false;
		printf("Неверная длина 2\n");
	}
	if (indexOf(list, 5) != 0)
	{
		result = false;
		printf("Неверный индекс 2\n");
	}
	deleteList(&list);
	if (list != NULL)
	{
		result = false;
		printf("Ошибка удаление списка\n");
	}
	if (getPos(10, 8) != 1)
	{
		result = false;
		printf("Неверное получение позиции 1\n");
	}
	if (getPos(3, 123) != 2)
	{
		result = false;
		printf("Неверное получение позиции 2\n");
	}
	return result;
}