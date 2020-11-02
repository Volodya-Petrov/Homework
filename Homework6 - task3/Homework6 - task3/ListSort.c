#include "List.h"
#include "ListSort.h"
#include "string.h"

void mergeName(struct List* list, int beginIndex, int partition, int endIndex)
{
	struct List* firstPart = copy(list, beginIndex, partition);
	struct List* secondPart = copy(list, partition + 1, endIndex);
	int indexFirstList = 0;
	int indexSecondList = 0;
	for (int i = beginIndex; i <= endIndex; i++)
	{
		char nameFromFirst[20] = "\0";
		char numberFromFirst[20] = "\0";
		char nameFromSecond[20] = "\0";
		char numberFromSecond[20] = "\0";
		if (indexFirstList >= getLength(firstPart))
		{
			getValue(secondPart, indexSecondList, 0, nameFromSecond);
			getValue(secondPart, indexSecondList, 1, numberFromSecond);
			changeValue(list, i, 0, nameFromSecond);
			changeValue(list, i, 1, numberFromSecond);
			indexSecondList++;
			continue;
		}
		if (indexSecondList >= getLength(secondPart))
		{
			getValue(firstPart, indexFirstList, 0, nameFromFirst);
			getValue(firstPart, indexFirstList, 1, numberFromFirst);
			changeValue(list, i, 0, nameFromFirst);
			changeValue(list, i, 1, numberFromFirst);
			indexFirstList++;
			continue;
		}
		getValue(firstPart, indexFirstList, 0, nameFromFirst);
		getValue(firstPart, indexFirstList, 1, numberFromFirst);
		getValue(secondPart, indexSecondList, 0, nameFromSecond);
		getValue(secondPart, indexSecondList, 1, numberFromSecond);
		if (strcmp(nameFromFirst, nameFromSecond) <= 0)
		{
			changeValue(list, i, 0, nameFromFirst);
			changeValue(list, i, 1, numberFromFirst);
			indexFirstList++;
		}
		else
		{
			changeValue(list, i, 0, nameFromSecond);
			changeValue(list, i, 1, numberFromSecond);
			indexSecondList++;
		}
	}
	deleteList(&secondPart);
	deleteList(&firstPart);
}

void mergeSortName(struct List* list, int beginIndex, int endIndex)
{
	if (beginIndex >= endIndex)
	{
		return;
	}
	if (endIndex >= getLength(list) || beginIndex >= getLength(list))
	{
		return;
	}
	int partition = (endIndex + beginIndex) / 2;
	mergeSortName(list, beginIndex, partition);
	mergeSortName(list, partition + 1, endIndex);
	mergeName(list, beginIndex, partition, endIndex);
}

void mergeNumber(struct List* list, int beginIndex, int partition, int endIndex)
{
	struct List* firstPart = copy(list, beginIndex, partition);
	struct List* secondPart = copy(list, partition + 1, endIndex);
	int indexFirstList = 0;
	int indexSecondList = 0;
	for (int i = beginIndex; i <= endIndex; i++)
	{
		char nameFromFirst[20] = "\0";
		char numberFromFirst[20] = "\0";
		char nameFromSecond[20] = "\0";
		char numberFromSecond[20] = "\0";
		if (indexFirstList >= getLength(firstPart))
		{
			getValue(secondPart, indexSecondList, 0, nameFromSecond);
			getValue(secondPart, indexSecondList, 1, numberFromSecond);
			changeValue(list, i, 0, nameFromSecond);
			changeValue(list, i, 1, numberFromSecond);
			indexSecondList++;
			continue;
		}
		if (indexSecondList >= getLength(secondPart))
		{
			getValue(firstPart, indexFirstList, 0, nameFromFirst);
			getValue(firstPart, indexFirstList, 1, numberFromFirst);
			changeValue(list, i, 0, nameFromFirst);
			changeValue(list, i, 1, numberFromFirst);
			indexFirstList++;
			continue;
		}
		getValue(firstPart, indexFirstList, 0, nameFromFirst);
		getValue(firstPart, indexFirstList, 1, numberFromFirst);
		getValue(secondPart, indexSecondList, 0, nameFromSecond);
		getValue(secondPart, indexSecondList, 1, numberFromSecond);
		if (strcmp(numberFromFirst, numberFromSecond) <= 0)
		{
			changeValue(list, i, 0, nameFromFirst);
			changeValue(list, i, 1, numberFromFirst);
			indexFirstList++;
		}
		else
		{
			changeValue(list, i, 0, nameFromSecond);
			changeValue(list, i, 1, numberFromSecond);
			indexSecondList++;
		}
	}
	deleteList(&secondPart);
	deleteList(&firstPart);
}

void mergeSortNumber(struct List* list, int beginIndex, int endIndex)
{
	if (beginIndex >= endIndex)
	{
		return;
	}
	if (endIndex >= getLength(list) || beginIndex >= getLength(list))
	{
		return;
	}
	int partition = (endIndex + beginIndex) / 2;
	mergeSortNumber(list, beginIndex, partition);
	mergeSortNumber(list, partition + 1, endIndex);
	mergeNumber(list, beginIndex, partition, endIndex);
}