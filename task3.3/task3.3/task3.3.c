#include <stdio.h>
#include "quickSort.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale.h>

int maxFounder(int array[], int size)
{
	int number = 0;
	int max = 1;
	int counter = 1;
	if (size == 1)
	{
		return array[0];
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			counter++;
		}
		else
		{
			if (counter > max)
			{
				max = counter;
				number = array[i];
			}
			counter = 1;
		}
	}
	if (counter > max)
	{
		number = array[size - 2];
	}
	return number;
}

int tests()
{	
	int counterMistakes = 0;
	int array1[6] = { 1, 5, 3, 5, 1, 5 };
	quickSort(array1, 0, 5);
	int number = maxFounder(array1, 6);
	if (number == 5)
	{
		printf("Тест 1 пройден успешно\n");
	}
	else
	{
		printf("Тест 1 провален\n");
		counterMistakes++;
	}
	int array2[1] = { 5 };
	quickSort(array2, 0, 0);
	number = maxFounder(array2, 1);
	if (number == 5)
	{
		printf("Тест 2 пройден успешно\n");
	}
	else
	{
		printf("Тест 2 провален\n");
		counterMistakes++;
	}
	int array3[5] = { 1, 1, 1, 1, 1 };
	quickSort(array3, 0, 4);
	number = maxFounder(array3, 5);
	if (number == 1)
	{
		printf("Тест 3 пройден успешно\n");
	}
	else
	{
		printf("Тест 3 провален\n");
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
	FILE* arrayfile;
	arrayfile = fopen("array.txt", "r");
	if (arrayfile == NULL)
	{
		printf("Не удалось найти файл\n");
		return 1;
	}
	int size = 0;
	int numbers = 0;
	while ((fscanf(arrayfile, "%i", &numbers)) != EOF)
	{
		size++;
	}
	rewind(arrayfile);
	int* array = (int*)calloc(size, sizeof(int));
	size = 0;
	while ((fscanf(arrayfile, "%i", &numbers)) != EOF)
	{
		array[size] = numbers;
		size++;
	}
	fclose(arrayfile);
	quickSort(array, 0, size - 1);
	const number = maxFounder(array, size);
	printf("%i", number);
	free(array);
}