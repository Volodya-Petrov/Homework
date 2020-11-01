#include "List.h"

void merge(struct List* list, int beginIndex, int partition, int endIndex)
{
	struct List* firstPart = copy(list, beginIndex, partition);
	struct List* secondPart = copy(list, partition + 1, endIndex);
	int indexFirstList = 0;
	int indexSecondList = 0;
	for (int i = beginIndex; i <= endIndex; i++)
	{
		char name[20] = "\0";
		char number[20] = "\0";
		if (indexFirstList >= getLength(firstPart))
		{
			getValue(secondPart, indexSecondList, 0, name);
			getValue(secondPart, indexSecondList, 1, number);
			changeValue(list, i, 0, name);
			changeValue(list, i, 1, number);
			indexSecondList++;
		}
		if (indexSecondList >= getLength(secondPart))
		{
			getValue(firstPart, indexFirstList, 0, name);
			getValue(firstPart, indexFirstList, 1, number);
			changeValue(list, i, 0, name);
			changeValue(list, i, 1, number);
			indexFirstList++;
		}
	}
}

void mergeSort(struct List* list, int beginIndex, int endIndex)
{
	if (beginIndex >= endIndex)
	{
		return;
	}
	int partition = (endIndex + beginIndex) / 2;
	mergeSort(list, beginIndex, partition);
	mergeSort(list, partition + 1, endIndex);

}