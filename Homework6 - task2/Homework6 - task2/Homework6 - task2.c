#include "List.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	printf("Введите количество воинов: ");
	int count = 0;
	scanf("%i", &count);
	printf("Ввведите период смерти: ");
	int period = 0;
	scanf("%i", &period);
	printf("Выживет воин на месте %i", getPos(count, period));
}