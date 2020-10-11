#include <stdio.h>
#include "quickSort.h"
#include <locale.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY 10

float arithmeticMean(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	return (float)sum / (float)size;
}

void showArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");
}

void reverse(int fromindex, int toIndex, int array[])
{
	const numberOfReplacement = (toIndex - fromindex + 1) / 2;
	for (int i = 0; i < numberOfReplacement; i++)
	{
		int helperReplacement = array[fromindex + i];
		array[fromindex + i] = array[toIndex - i];
		array[toIndex - i] = helperReplacement;
	}
}

void randArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = (200 * rand()) / RAND_MAX - 100;
	}
}

int main(void)
{	
	setlocale(LC_ALL, "rus");
	int array[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		array[i] = 0;
	}
	printf("Список доступных команд:\n");
	printf("0 – выйти \n");
	printf("1 – заполнить массив чисел случайными значениями\n");
	printf("2 – отсортировать массив\n");
	printf("3 – развернуть массив \n");
	printf("4 – посчитать среднее арифметическое элементов массива\n");
	int command = -1;
	while (command != 0)
	{
		printf("Введите номер команды: ");
		scanf("%i", &command);
		switch (command)
		{
		case 0:
			break;

		case 1:
			randArray(array, SIZE_OF_ARRAY);
			printf("Теперь данный массив имеет вид:\n");
			showArray(array, SIZE_OF_ARRAY);
			break;
		case 2:
			quickSort(array, 0, SIZE_OF_ARRAY - 1);
			printf("Теперь данный массив имеет вид:\n");
			showArray(array, SIZE_OF_ARRAY);
			break;
		case 3:
			reverse(0, SIZE_OF_ARRAY - 1, array);
			printf("Теперь данный массив имеет вид:\n");
			showArray(array, SIZE_OF_ARRAY);
			break;
		case 4:
			printf("Среднее арифмитическое всех чисел = %f \n", arithmeticMean(array, SIZE_OF_ARRAY));
			break;
		default:
			command = 0;
			break;
		}

	}
}
