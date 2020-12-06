#include "buildCountries.h"
#include "testForList.h"
#include "testForTask.h"
#include "List.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!testForTask() || !testList())
	{	
		printf("Тесты провалены\n");
		return 1;
	}
	printf("Тесты пройдены успешно\n");
	int countOfCountries = 0;
	List** countries = getCountries("task.txt", &countOfCountries);
	for (int i = 0; i < countOfCountries; i++)
	{
		printf("Государство %i\n", i + 1);
		printf("Состав: ");
		for (int j = 0; j < length(countries[i]); j++)
		{	
			int city = 0;
			getValue(countries[i], j, &city);
			printf("%i ", city + 1);
		}
		printf("\n\n");
	}
	for (int i = 0; i < countOfCountries; i++)
	{
		deleteList(&countries[i]);
	}
	free(countries);
}