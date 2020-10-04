#include "quickSort.h"

int partition(int array[], int begin, int end)
{
	int indexOfBoardForBigNumbers = begin;
	for (int i = begin; i < end; i++)
	{
		if (array[i] < array[end])
		{
			int const variableSwap = array[indexOfBoardForBigNumbers];
			array[indexOfBoardForBigNumbers] = array[i];
			array[i] = variableSwap;
			indexOfBoardForBigNumbers++;
		}
	}
	const int helperSwap = array[end];
	array[end] = array[indexOfBoardForBigNumbers];
	array[indexOfBoardForBigNumbers] = helperSwap;
	return indexOfBoardForBigNumbers;
}

int quickSort(int array[], int begin, int end)
{
	if (end - begin <= 0)
	{
		return 0;
	}
	else
	{
		const int partitionIndex = partition(array, begin, end);
		quickSort(array, begin, partitionIndex - 1);
		quickSort(array, partitionIndex + 1, end);
	}
	return 0;
}