#include <stdio.h>
#include "testForStack.h"
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (bigTest())
	{
		printf("����� �������� �������!\n");
	}
	else
	{
		return 1;
	}
}