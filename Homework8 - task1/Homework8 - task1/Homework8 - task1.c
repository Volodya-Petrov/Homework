﻿#include "avl.h"
#include "testForTask.h"
#include <stdio.h>
#include <locale.h>

#define WRONG_OPTION -1

int main(void)
{
	setlocale(LC_ALL, "rus");
	if (!tests())
	{
		printf("Тесты провалены!\n");
		return 1;
	}
	printf("Тесты пройдены успешно\n");
	printf("Набор команд:\n");
	printf("0 - Выход\n");
	printf("1 - добавить значение по ключу\n");
	printf("2 - получить значение по ключу\n");
	printf("3 - проверить наличие заданного ключа в словаре\n");
	printf("4 - удаление заданного ключа и его значения\n");
	int option = -1;
	Tree* tree = createTree();
	while (option != 0)
	{
		printf("Введите номер команды: ");
		if (scanf("%i", &option) == 0)
		{
			scanf("%*s");
			option = WRONG_OPTION;
		}
		switch (option)
		{
		case 0:
			break;
		case 1:
		{
			printf("Введите ключ: ");
			char key[20] = "";
			scanf("%s", key);
			char value[20] = "";
			printf("Введите значение: ");
			scanf("%s", value);
			insert(tree, key, value);
			break;
		}
		case 2:
		{	
			printf("Введите ключ: ");
			char key[20] = "";
			scanf("%s", key);
			const char* value = getValue(tree, key);
			if (value == NULL)
			{
				printf("Значение по заданному ключу не обнаружено\n");
				break;
			}
			printf("Значение по заданному ключу: %s\n", value);
			break;
		}
		case 3:
		{
			printf("Введите ключ: ");
			char key[20] = "";
			scanf("%s", key);
			if (checkExist(tree, key))
			{
				printf("Заданный ключ существует\n");
			}
			else
			{
				printf("Заданного ключа не обнаружено в словаре\n");
			}
			break;
		}
		case 4:
		{
			printf("Введите ключ: ");
			char key[20] = "";
			scanf("%s", key);
			delete(tree, key);
			printf("Элемент удален\n");
			break;
		}
		default:
			printf("Введен неправильный номер команды\n");
			break;
		}
	}
	deleteTree(&tree);
}