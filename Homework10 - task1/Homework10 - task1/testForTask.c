#include "testForTask.h"
#include "List.h"
#include "buildCountries.h"
#include <stdlib.h>
#include <stdio.h>

List** initArrayOfLists(int count)
{
	List** list = calloc(count, sizeof(List*));
	if (!list)
	{
		return NULL;
	}
	for (int i = 0; i < count; i++)
	{
		list[i] = createList();
	}
	return list;
}

bool compareArrays(List** array1, List** array2, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (length(array1[i]) != length(array2[i]))
		{
			return false;
		}
		for (int j = 0; j < length(array1[i]); j++)
		{
			int value1 = 0;
			int value2 = 0;
			getValue(array1[i], j, &value1);
			getValue(array2[i], j, &value2);
			if (value1 != value2)
			{
				return false;
			}
		}
	}
	return true;
}

bool boundaryTest(void)
{	
	bool result = true;
	List** countries = initArrayOfLists(1);
	append(countries[0], 0);
	int size = 0;
	List** countriesTest = getCountries("test1.txt", &size);
	if (size != 1)
	{
		printf("Неправильное чтение кол-ва столиц\n");
		result = false;
	}
	if (!compareArrays(countries, countriesTest, size))
	{
		result = false;
	}
	for (int i = 0; i < size; i++)
	{	
		deleteList(&countriesTest[i]);
		deleteList(&countries[i]);
	}
	free(countries);
	free(countriesTest);
	return result;
}

bool bigInputDataTest()
{
	bool result = true;
	List** countries = initArrayOfLists(2);
	append(countries[0], 0);
	append(countries[0], 1);
	append(countries[0], 2);
	append(countries[1], 4);
	append(countries[1], 3);
	int size = 0;
	List** countriesTest = getCountries("test2.txt", &size);
	if (size != 2)
	{
		printf("Неправильное чтение кол-ва столиц\n");
		result = false;
	}
	if (!compareArrays(countries, countriesTest, size))
	{
		result = false;
	}
	for (int i = 0; i < size; i++)
	{
		deleteList(&countriesTest[i]);
		deleteList(&countries[i]);
	}
	free(countries);
	free(countriesTest);
	return result;
}

bool testForTask(void)
{
	return !(!boundaryTest() + !bigInputDataTest());
}