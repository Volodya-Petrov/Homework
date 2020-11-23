#include "sortList.h"
#include "testForList.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void delAll(struct List* list, int* array)
{
	deleteList(&list);
	free(array);
}

bool arraysAreEqual(int array1[], int array2[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (array1[i] != array2[i])
		{
			return false;
		}
	}
	return true;
}

bool tests(void)
{	
	setlocale(LC_ALL, "rus");
	int testArray1Compare[2] = { 5, 7 };
	int testArray2Compare[4] = { 2, 5, 7, 9 };
	int testArray3Compare[3] = { 2, 5, 9 };
	bool result = true;
	struct List* newList = createList();
	if (newList == NULL)
	{
		return false;
	}
	add(newList, 5);
	add(newList, 7);
	int* testArray = fillArray(newList);
	if (testArray == NULL)
	{
		delAll(newList, testArray);
		return false;
	}
	if (!arraysAreEqual(testArray, testArray1Compare, 2))
	{	
		delAll(newList, testArray);
		printf("Тест на добавление элементов провален!\n");
		result = false;
	}
	free(testArray);
	add(newList, 2);
	add(newList, 9);
	testArray = fillArray(newList);
	if (testArray == NULL)
	{
		delAll(newList, testArray);
		return false;
	}
	if (!arraysAreEqual(testArray, testArray2Compare, 4))
	{
		printf("Тест на проверку сортированности провален!\n");
		result = false;
	}
	if (!delElement(newList, 7))
	{
		printf("Первый тест на удаление элементов провален!\n");
		result = false;
	}
	free(testArray);
	testArray = fillArray(newList);
	if (testArray == NULL)
	{
		delAll(newList, testArray);
		return false;
	}
	if (!arraysAreEqual(testArray, testArray3Compare, 3))
	{
		printf("Второй тест на удаление элементов провален!\n");
		result = false;
	}
	if (length(newList) != 3)
	{
		result = false;
	}
	delAll(newList, testArray);
	return result;
}