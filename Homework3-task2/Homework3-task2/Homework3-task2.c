#include <stdio.h>
#include "quickSort.h"
#include <stdlib.h>
#include <locale.h>

int binarySearch(int array[], int begin, int end, int number)
{
	if (begin > end)
	{
		return 0;
	}
	const int middle = (end + begin) / 2;
	if (array[middle] == number)
	{
		return 1;
	}
	if (array[middle] > number)
	{
		return binarySearch(array, begin, middle - 1, number);
	}
	else
	{
		return binarySearch(array, middle + 1, end, number);
	}
}

int tests()
{
	int counterMistakes = 0;
	int array1[6] = { 1, 5, 3, 5, 1, 5 };
	quickSort(array1, 0, 5);
	int number = binarySearch(array1, 0, 5, 1);
	if (number == 1)
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
	number = binarySearch(array2, 0, 0, 5);
	if (number == 1)
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
	number = binarySearch(array3, 0, 4, 5);
	if (number == 0)
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


int main()
{	
	setlocale(LC_ALL, "rus");
	if (tests())
	{
		return 1;
	}
	else
	{
		printf("Тесты пройдены успешно\n");
	}
	int n = 0;
	printf("Введите число n: ");
	scanf("%i", &n);
	int k = 0;
	printf("Введите число k: ");
	scanf("%i", &k);
	int* array = (int*) calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		array[i] = 2000 * rand() / RAND_MAX - 1000;
	}
	quickSort(array, 0, n - 1);
	for (int i = 0; i < k; i++)
	{
		int number = 2000 * rand() / RAND_MAX - 1000;
		binarySearch(array, 0, n - 1, number) ? printf("%i найден в массиве\n", number) : printf("%i не найден в массиве\n", number);
	}
	free(array);
}