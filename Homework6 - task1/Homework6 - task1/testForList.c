#include "sortList.h"
#include "testForList.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

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
	int testArray1[2] = { 0 };
	int testArray1Compare[2] = { 5, 7 };
	int testArray2[4] = { 0 };
	int testArray2Compare[4] = { 2, 5, 7, 9 };
	int testArray3[3] = { 0 };
	int testArray3Compare[3] = { 2, 5, 9 };
	bool result = true;
	struct List* newList = createList();
	addElement(newList, 5);
	addElement(newList, 7);
	getList(newList, testArray1, 0);
	if (!arraysAreEqual(testArray1, testArray1Compare, 2))
	{
		printf("Тест на добавление элементов провален!\n");
		result = false;
	}
	addElement(newList, 2);
	addElement(newList, 9);
	getList(newList, testArray2, 0);
	if (!arraysAreEqual(testArray2, testArray2Compare, 4))
	{
		printf("Тест на проверку сортированности провален!\n");
		result = false;
	}
	if (!deleteElement(newList, 7))
	{
		printf("Первый тест на удаление элементов провален!\n");
		result = false;
	}
	getList(newList, testArray3, 0);
	if (!arraysAreEqual(testArray3, testArray3Compare, 3))
	{
		printf("Второй тест на удаление элементов провален!\n");
		result = false;
	}
	if (getLength(newList) != 3)
	{
		result = false;
	}
	deleteList(&newList);
	if (newList != NULL)
	{
		printf("Тест на удаление списка провален\n");
	}
	return result;
}