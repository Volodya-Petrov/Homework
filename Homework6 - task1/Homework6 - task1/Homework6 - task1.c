#include "sortList.h"
#include "testForList.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define WRONG_COMMAND 1337;

int correctInput(void)
{
	int value = 0;
	while (!scanf("%i", &value))
	{
		scanf("%*s");
		printf("Введенное значение не является корректным!\n");
		printf("Повторите попытку\n");
		printf("Введите значение, которое хотите добавить: ");
	}
	return value;
}

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (tests())
	{
		printf("Тесты пройдены успешно!\n");
	}
	else
	{
		return 1;
	}
	struct List* newList = createList();
	printf("0 – выйти\n");
	printf("1 – добавить значение в сортированный список\n");
	printf("2 – удалить значение из списка\n");
	printf("3 – распечатать список\n");
	int numberOfCommand = 1;
	while (numberOfCommand != 0)
	{	
		printf("Выберете номер команды: ");
		if (scanf("%i", &numberOfCommand) == 0)
		{
			scanf("%*s");
			numberOfCommand = WRONG_COMMAND;
		}
		switch (numberOfCommand)
		{
		case 0:
			break;
		case 1:
		{
			printf("Введите значение, которое хотите добавить: ");
			int value = correctInput();
			add(newList, value);
			break;
		}
		case 2:
		{
			printf("Введите значение, которое хотите удалить: ");
			int value = correctInput();
			if (delElement(newList, value))
			{
				printf("Элемент с данным значением удален из списка!\n");
			}
			else
			{
				printf("В списке нет элементов с данным значением!\n");
			}
			break;
		}
		case 3:
		{
			int* array = fillArray(newList);
			if (array == NULL)
			{
				break;
			}
			for (int i = 0; i < length(newList); i++)
			{
				printf("%i ", array[i]);
			}
			printf("\n");
			free(array);
			array = NULL;
			break;
		}
		default:
			printf("Введенной команды нет в списке,\nповторите попытку.\n");
			break;
		}
	}
	deleteList(&newList);
}