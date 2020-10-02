#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale.h>

void arrayInitializationOnlyPositive(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
}

void arrayInitialization(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = (2000 * rand()) / RAND_MAX - 1000;
	}
}

void insertionSort(int array[], int begin, int end)
{
	for (int i = begin + 1; i <= end; i++)
	{
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

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
	if (end - begin + 1 <= 10)
	{
		insertionSort(array, begin, end);
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

int main(void)
{
	int array[20];
	arrayInitializationOnlyPositive(array, 20);
	quickSort(array, 0, 19);
	for (int i = 0; i < 20; i++)
	{
		printf("%i ", array[i]);
	}
}