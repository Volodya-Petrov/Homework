#include <stdio.h>
#include <locale.h>

void showArray(int array[], int size)
{	
	printf("Теперь массив имеет следующий вид: \n");
	for (int i = 0; i < size; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");
}

int sortByChoice(int array[], int size)
{	
	for (int i = 0; i < size; i++)
	{	
		int indexOfMin = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[indexOfMin])
			{
				indexOfMin = j;
			}
		}
		int helperOfSwap = array[i];
		array[i] = array[indexOfMin];
		array[indexOfMin] = helperOfSwap;
	}
}

int main(void)
{	
	setlocale(LC_ALL, "rus");
	int array[10];
	printf("Вввод массива:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Введите %i элемент: ", i + 1);
		scanf("%i", &array[i]);
	}
	showArray(array, 10);
	sortByChoice(array, 10);
	showArray(array, 10);
}