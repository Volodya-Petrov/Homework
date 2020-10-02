#include <stdio.h>
#include <locale.h>
#define SIZE_OF_ARRAY 100 

void reverse(int fromindex, int toIndex, int array[] )
{
	const numberOfReplacement = (toIndex - fromindex + 1)/2;
	for (int i = 0; i < numberOfReplacement; i++)
	{
		int helperReplacement = array[fromindex + i];
		array[fromindex + i] = array[toIndex - i];
		array[toIndex - i] = helperReplacement;
	}
}

void rearrangingPartsOfArray(int lengthFirstPart, int lengthSecondPart, int array[])
{
	reverse(0, lengthFirstPart - 1, array);
	reverse(lengthFirstPart, lengthFirstPart + lengthSecondPart - 1, array);
	reverse(0, lengthFirstPart + lengthSecondPart - 1, array);
}

int main(void)
{	
	setlocale(LC_ALL, "Rus");
	int array[SIZE_OF_ARRAY];
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		array[i] = i;
	}
	int n = 0;
	int m = 0;
	printf("Ввведите первую границу массива: ");
	scanf("%i", &m);
	printf("Введите вторую границу массива: ");
	scanf("%i", &n);
	rearrangingPartsOfArray(m, n, array);
	for (int i = 0; i < m + n; i++) {
		printf("%i ", array[i]);
	}
}