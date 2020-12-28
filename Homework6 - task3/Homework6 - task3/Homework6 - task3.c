#include "List.h"
#include "Tests.h"
#include "ListSort.h"
#include "fillingList.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define FAIL 1337

int main(void)
{	
	setlocale(LC_ALL, "rus");
/*	if (testsResult())
	{
		return 1;
	}
	else
	{
		printf("Тесты пройдены успешно!\n");
	}*/
	struct List* newList = createList();
	if (newList == NULL)
	{
		return 1;
	}
	readFromFile(newList, "data.txt");
	printf("Данные с файла: \n");
	printList(newList);
	int option = 0;
	bool exit = false;
	while (!exit)
	{
		printf("Ввведите 0 если хотите отсортировать список по имени\n");
		printf("Введите 1 если хотите отсортировать список по номеру телефона\n");
		if (scanf("%i", &option) == 0)
		{
			scanf("%*s");
			option = FAIL;
		}
		switch (option)
		{
		case 0:
			mergeSort(newList, 0, getLength(newList) - 1, NAME);
			exit = true;
			break;
		case 1:
			mergeSort(newList, 0, getLength(newList) - 1, NUMBER);
			exit = true;
		default:
			printf("Введены некорректные данные, повтори попытку\n");
		}
	}
	printf("Отсортированный список:\n");
	printList(newList);
	deleteList(&newList);
}