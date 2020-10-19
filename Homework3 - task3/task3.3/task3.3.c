#include <stdio.h>
#include "quickSort.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <locale.h>

// инициализация массива числами из файла
void arrayInitialization(int array[], const char fileName[])
{	
	FILE* fileOpen = fopen(fileName, "r");
	int numbers = 0;
	int size = 0;
	while ((fscanf(fileOpen, "%i", &numbers)) != EOF)
	{
		array[size] = numbers;
		size++;
	}
	fclose(fileOpen);
}

// функция, которая выдает количество чисел в файле
int countOfElements(const char fileName[])
{	
	FILE* fileOpen = fopen(fileName, "r");
	int size = 0;
	int trash = 0;
	while ((fscanf(fileOpen, "%i", &trash)) != EOF)
	{
		size++;
	}
	fclose(fileOpen);
	return size;
}

// поиск максимального элемента в массиве
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
	int array4[5] = { 0 };
	arrayInitialization(array4, "test.txt");
	if ((array4[0] == 1) && (array4[1] == 3) && (array4[2] == 4) && (array4[3] == 6) && (array4[4] == 5))
	{
		printf("Тест 4 пройден успешно\n");
	}
	else
	{
		printf("Тест 4 провален\n");
		counterMistakes++;
	}
	if (countOfElements("test.txt") == 5)
	{
		printf("Тест 5 пройден успешно\n");
	}
	else
	{
		printf("Тест 5 провален\n");
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
	const int size = countOfElements("array.txt");
	int* array = (int*)calloc(size, sizeof(int));
	arrayInitialization(array, "array.txt");
	quickSort(array, 0, size - 1);
	const number = maxFounder(array, size);
	printf("Максимальный элемент = %i", number);
	free(array);
}