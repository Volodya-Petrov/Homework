#include "buildCountries.h";
#include "List.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	List** countries = getCountries("task.txt");
	int countOfCountries = 2;
	for (int i = 0; i < countOfCountries; i++)
	{
		printf("Государство %i", i + 1);
		printf("\n");
		int city = 0;
		getValue(countries[i], 0, &city);
		printf("Cтолица: %i", city + 1);
		printf("\n");
		printf("Состав: ");
		for (int j = 0; j < length(countries[i]); j++)
		{	
			getValue(countries[i], j, &city);
			printf("%i ", city + 1);
		}
		printf("\n");
		printf("\n");
	}
	for (int i = 0; i < countOfCountries; i++)
	{
		deleteList(&countries[i]);
	}
	free(countries);
}