#include "Tree.h"
#include <stdio.h>
#include <locale.h>

#define WRONG_OPTION -1

int correctInput()
{
	int key = 0;
	while (scanf("%i", &key) == 0)
	{
		printf("Некорректный ввод данных\nПовторите попытку\n");
		printf("Введите ключ: ");
		scanf("%*s");
	}
	return key;
}

int main(void)
{
	setlocale(LC_ALL, "rus");
	printf("Набор команд:\n");
	printf("1 - добавить значение по ключу\n");
	printf("2 - получить значение по ключу\n");
	printf("3 - проверить наличие заданного ключа в словаре\n");
	printf("4 - удаление заданного ключа и его значения\n");
	int option = -1;
	struct Dictionary* dict = createDictionary();
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
			int key = correctInput();
			char value[20] = "";
			printf("Введите значение ключа: ");
			scanf("%s", value);
			addElement(dict, key, value);
			break;
		}
		case 2:
		{
			printf("Введите ключ: ");
			int key = correctInput();
			char* value = getValue(dict, key);
			if (value == NULL)
			{
				printf("Значение по заданному ключу не обнаружено\n");
				break;
			}
			printf("Значение по заданному ключе: %s\n", value);
			break;
		}
		case 3:
		{
			printf("Введите ключ: ");
			int key = correctInput();
			if (keyExists(dict, key))
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
			int key = correctInput();
			deleteElement(dict, key);
			printf("Элемент удален\n");
			break;
		}
		default:
			printf("Введен неправильный номер команды\n");
			break;
		}
	}
	deleteDict(&dict);
}