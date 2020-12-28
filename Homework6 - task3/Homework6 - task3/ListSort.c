#include "List.h"
#include "ListSort.h"
#include "string.h"

void merge(struct List* list, int beginIndex, int partition, int endIndex, enum Contact sortType)
{
	struct List* firstPart = copy(list, beginIndex, partition);
	if (firstPart == NULL)
	{
		return;
	}
	struct List* secondPart = copy(list, partition + 1, endIndex);
	{
		if (secondPart == NULL)
		{
			deleteList(&firstPart);
			return;
		}
	}
	int indexFirstList = 0;
	int indexSecondList = 0;
	for (int i = beginIndex; i <= endIndex; i++)
	{
		char nameFromFirst[20] = "";
		char numberFromFirst[20] = "";
		char nameFromSecond[20] = "";
		char numberFromSecond[20] = "";
		getValue(firstPart, indexFirstList, NAME, nameFromFirst);
		getValue(firstPart, indexFirstList,	NUMBER, numberFromFirst);
		getValue(secondPart, indexSecondList, NAME, nameFromSecond);
		getValue(secondPart, indexSecondList, NUMBER, numberFromSecond);
		if (indexFirstList >= getLength(firstPart))
		{
			changeValue(list, i, NAME, nameFromSecond);
			changeValue(list, i, NUMBER, numberFromSecond);
			indexSecondList++;
			continue;
		}
		if (indexSecondList >= getLength(secondPart))
		{
			changeValue(list, i, NAME, nameFromFirst);
			changeValue(list, i, NUMBER, numberFromFirst);
			indexFirstList++;
			continue;
		}
		int result = 0;
		if (sortType == NAME)
		{
			result = strcmp(nameFromFirst, nameFromSecond);
		}
		else
		{
			result = strcmp(numberFromFirst, numberFromSecond);
		}
		if (result <= 0)
		{
			changeValue(list, i, NAME, nameFromFirst);
			changeValue(list, i, NUMBER, numberFromFirst);
			indexFirstList++;
		}
		else
		{
			changeValue(list, i, NAME, nameFromSecond);
			changeValue(list, i, NUMBER, numberFromSecond);
			indexSecondList++;
		}
	}
	deleteList(&secondPart);
	deleteList(&firstPart);
}

void mergeSort(struct List* list, int beginIndex, int endIndex, enum Contact sortType)
{
	if (beginIndex >= endIndex)
	{
		return;
	}
	if (endIndex >= getLength(list) || beginIndex >= getLength(list))
	{
		return;
	}
	const int partition = (endIndex + beginIndex) / 2;
	mergeSort(list, beginIndex, partition, sortType);
	mergeSort(list, partition + 1, endIndex, sortType);
	merge(list, beginIndex, partition, endIndex, sortType);
}