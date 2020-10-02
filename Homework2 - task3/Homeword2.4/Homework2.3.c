#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale.h>

#define SIZE_OF_ARRAY 100000

int checkForSorted(int array[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if ((array[i] > array[i + 1]))
		{
			return 1;
		}
	}
	return 0;
}

void arrayInitialization(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = (2000 * rand()) / RAND_MAX - 1000;
	}
}

void arrayInitializationOnlyPositive(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 1000;
	}
}

int sortByCounting(int array[], int arrayLength)
{
	if (arrayLength <= 0)
	{
		printf("Невозможная длина массива\n");
		return 1;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	int indexOfUnregistered = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	int* countOfNumbers = (int*)calloc(max - min + 1, sizeof(int));
	for (int i = 0; i < arrayLength; i++)
	{
		countOfNumbers[array[i] - min]++;
	}
	for (int i = 0; i < max - min + 1; i++)
	{
		while (countOfNumbers[i] != 0)
		{
			countOfNumbers[i]--;
			array[indexOfUnregistered] = i + min;
			indexOfUnregistered++;
		}
	}
	free(countOfNumbers);
	return 0;
}

int bubbleSort(int array[], int arrayLength)
{
	if (arrayLength <= 0)
	{
		printf("Невозможная длина массива\n");
		return 1;
	}
	for (int i = 0; i < arrayLength - 1; i++)
	{
		for (int j = arrayLength - 1; j > i; j--)
		{
			if (array[j - 1] > array[j])
			{
				const int helperOfPermutation = array[j - 1];
				array[j - 1] = array[j];
				array[j] = helperOfPermutation;
			}
		}
	}
	return 0;
}

int testCountingIncorrectCase()
{
	int array[1] = { 1 };
	if (!sortByCounting(array, 0))
	{
		printf("Тест c одним элементом провален\n");
		return 1;
	}
	return 0;
}

int testBubbleIncorrectCase()
{	
	int array[1] = {1};
	if (!bubbleSort(array, 0))
	{
		printf("Тест c одним элементом провален\n");
		return 1;
	}
	return 0;
}

int testBubbleWithNegativePositiveNums()
{
	int array[10];
	arrayInitialization(array, 10);
	if (bubbleSort(array, 10))
	{
		printf("Тест пузырька с числами разного знака провален\n");
		return 1;
	}
	if (checkForSorted(array, 10))
	{
		printf("Тест пузырька с числами разного знака провален\n");
		return 1;
	}
	return 0;
}

int testBubbleOnlyPositiveNums()
{
	int array[1000];
	arrayInitializationOnlyPositive(array, 1000);
	if (bubbleSort(array, 1000))
	{
		printf("Тест пузырька только положительных чисел провален\n");
		return 1;
	}
	if (checkForSorted(array, 1000))
	{
		printf("Тест пузырька только положительных чисел провален\n");
		return 1;
	}
	return 0;
}

int testBubbleAllTheSame()
{
	int array[1000];
	for (int i = 0; i < 1000; i++)
	{
		array[i] = 1;
	}
	if (bubbleSort(array, 1000))
	{
		printf("Тест пузырька одни и те же числа провален\n");
		return 1;
	}
	if (checkForSorted(array, 1000))
	{
		printf("Тест пузырька одни и те же числа провален\n");
		return 1;
	}
	return 0;
}

int testCountingSortWithNegativePositiveNums()
{
	int array[10000];
	arrayInitialization(array, 10000);
	if (sortByCounting(array, 10000))
	{
		printf("Тест подсчета числами разного знака провален\n");
		return 1;
	}
	if (checkForSorted(array, 10000))
	{
		printf("Тест подсчета числами разного знака провален\n");
		return 1;
	}
	return 0;
}

int testCountingOnlyPositiveNums()
{
	int array[10000];
	arrayInitializationOnlyPositive(array, 10000);
	if (sortByCounting(array, 10000))
	{
		printf("Тест подсчета с положительными числами провален\n");
		return 1;
	}
	if (checkForSorted(array, 10000))
	{
		printf("Тест подсчета с положительными числами провален\n");
		return 1;
	}
	return 0;
}

int testCountingAllTheSameNums()
{
	int array[10000];
	for (int i = 0; i < 10000; i++)
	{
		array[i] = 1;
	}
	if (sortByCounting(array, 10000))
	{
		printf("Тест подсчета одни и те же числа провален\n");
		return 1;
	}
	if (checkForSorted(array, 10000))
	{
		printf("Тест подсчета одни и те же числа провален\n");
		return 1;
	}
	return 0;
}

int checkTestsForFailure()
{
	int checkForMistakes = 0;
	if (testCountingIncorrectCase())
	{
		checkForMistakes++;
	}
	if (testBubbleIncorrectCase())
	{
		checkForMistakes++;
	}
	if (testBubbleWithNegativePositiveNums())
	{
		checkForMistakes++;
	}
	if (testBubbleOnlyPositiveNums())
	{
		checkForMistakes++;
	}
	if (testBubbleAllTheSame())
	{
		checkForMistakes++;
	}
	if (testCountingSortWithNegativePositiveNums())
	{
		checkForMistakes++;
	}
	if (testCountingOnlyPositiveNums())
	{
		checkForMistakes++;
	}
	if (testCountingAllTheSameNums())
	{
		checkForMistakes++;
	}
	return checkForMistakes;
}

int main(void)
{	
	setlocale(LC_ALL, "Rus");
	if (checkTestsForFailure())
	{
		return 1;
	}
	else
	{
		printf("Тесты пройдены успешно!\n");
	}
	int array[SIZE_OF_ARRAY]; 
	arrayInitialization(array, SIZE_OF_ARRAY);
	clock_t time = clock();
	sortByCounting(array, SIZE_OF_ARRAY);
	time = clock() - time;
	float timeInSecond = (float)time /  CLOCKS_PER_SEC;
	printf("Массив отсортирован подсчетом за %f", timeInSecond);
	printf("\n");
	printf("Подождите некторое время, пока не выдаст время сортировки пузырьком\n");
	time = clock();
	bubbleSort(array, SIZE_OF_ARRAY);
	time = clock() - time;
	timeInSecond = (float)time / CLOCKS_PER_SEC;
	printf("Массив отсортирован пузырьком за %f", timeInSecond);
}
