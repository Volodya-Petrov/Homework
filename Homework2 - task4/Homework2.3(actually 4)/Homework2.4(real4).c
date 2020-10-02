#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE_OF_ARRAY 10

int partition(int array[], int size)
{
	if (size < 1)
	{
		printf("Неверный размер массива\n");
		return 1;
	}
	int const helperSwap = array[0];
	array[0] = array[size - 1];
	array[size - 1] = helperSwap;
	int indexOfBoardForBigNumbers = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] < array[size - 1])
		{
			int const variableSwap = array[indexOfBoardForBigNumbers];
			array[indexOfBoardForBigNumbers] = array[i];
			array[i] = variableSwap;
			indexOfBoardForBigNumbers++;
		}
	}
	array[size - 1] = array[indexOfBoardForBigNumbers];
	array[indexOfBoardForBigNumbers] = helperSwap;
	return 0;
}

int arrayInitialization(int array[], int size)
{
	if (size < 1)
	{
		printf("Некорректный ввод данных\n");
		return 1;
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 1000;
	}
	return 0;
}

int checkPartitonForMistakes(int array[], int size, int referenceNumber)
{
	if (size <= 0)
	{
		printf("Неверный размер массива");
		return 1;
	}
	int indexOfReference = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == referenceNumber)
		{
			indexOfReference = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (array[i] < referenceNumber)
		{
			if (i > indexOfReference)
			{
				printf("Разбито неверно\n");
				return 1;
			}
		}
		else
		{
			if (i < indexOfReference)
			{
				printf("Разбито неверно\n");
				return 1;
			}
		}
	}
	return 0;
}

int tests()
{	
	int counterMistakes = 0;
	int array1[5] = { 4, 3, 5, 1, 2 };
	if (!partition(array1, 0))
	{
		printf("Функция partition неправильно читает данные");
		counterMistakes++;
	}
	partition(array1, 5);
	if (checkPartitonForMistakes(array1, 5, 4))
	{
		counterMistakes++;
	}
	int array2[1000];
	arrayInitialization(array2, 1000);
	const int reference = array2[0];
	partition(array2, 1000);
	if (checkPartitonForMistakes(array2, 1000, reference))
	{
		counterMistakes++;
	}
	return counterMistakes;
}

int main(void)
{	
	setlocale(LC_ALL, "Rus");
	if (tests())
	{
		return 1;
	}
	else
	{
		printf("Тесты пройдены успешно\n");
	}
	int array[SIZE_OF_ARRAY];
	arrayInitialization(array, SIZE_OF_ARRAY);
	int const reference = array[0];
	partition(array, SIZE_OF_ARRAY);
	printf("Опорный элемент = %i\n", reference);
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		printf("%i ", array[i]);
	}
}