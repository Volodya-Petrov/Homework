#include <stdio.h>
#include <math.h>
#include <locale.h>

int isPrimeNum(int number)
{
	int root = sqrt(number);
	for (int i = 2; i < root + 1; i++)
	{
		if (number % i == 0)
			return 0;
	}
	return 1;
}

int main()
{	
	setlocale(LC_ALL, "Rus");
	int number = 0;
	printf("Введите число: ");
	scanf("%i", &number);
	for (int i = 2; i <= number; i++)
	{
		if (isPrimeNum(i))
		{
			printf("%i\n", i);
		}
	}
}