#include <stdio.h>
#include "testForStack.h"
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (bigTest())
	{
		printf("Тесты пройдены успешно!\n");
	}
	else
	{
		return 1;
	}
}