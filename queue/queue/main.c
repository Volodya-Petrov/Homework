#include "queueTest.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "rus");
	if (queueTest())
	{
		printf("Тесты пройдены успешно\n");
	}
	else
	{
		printf("Тесты провалены\n");
		return 1;
	}
}