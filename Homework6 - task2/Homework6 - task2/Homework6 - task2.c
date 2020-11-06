#include "List.h"
#include "Tests.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "rus");
	if (tests())
	{
		printf("Тесты пройдены успешно\n");
	}
	else
	{
		return 1;
	}
	printf("Введите количество воинов: ");
	int count = 0;
	scanf("%i", &count);
	printf("Ввведите период смерти: ");
	int period = 0;
	scanf("%i", &period);
	printf("Выживет воин на месте %i", getPos(count, period));
}