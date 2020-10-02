#include <stdio.h>
#include <locale.h>

int main()
{	
	setlocale(LC_ALL, "Rus");
	int countOfSums[28];
	int countOfLuckyTickets = 0;
	for (int i = 0; i < 28; i++)
	{
		countOfSums[i] = 0;
	}
	for (int i = 0; i < 1000; i++)
	{
		int sumOfDigits = 0;
		sumOfDigits += i % 10;
		sumOfDigits += i / 100;
		sumOfDigits += i / 10 - (i / 100) * 10;
		countOfSums[sumOfDigits] += 1;
	}
	for (int i = 0; i < 28; i++)
	{
		countOfLuckyTickets += countOfSums[i] * countOfSums[i];
	}
	printf("Количество счастливых билетов: %d", countOfLuckyTickets);
}