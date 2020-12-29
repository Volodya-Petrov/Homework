#include "Tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool test(void)
{
	bool result = true;
	struct Dictionary* dict = createDictionary();
	addElement(dict, 15, "Bob");
	addElement(dict, 13, "Lol");
	addElement(dict, 14, "Head");
	addElement(dict, 20, "Warwar");
	addElement(dict, 25, "Molodoy");
	if (!keyExists(dict, 14))
	{
		printf("Первый тест провален\n");
		result = false;
	}
	if (strcmp(getValue(dict, 15), "Bob") != 0)
	{
		printf("Второй тест провален\n");
		result = false;
	}
	deleteElement(dict, 15);
	if (!keyExists(dict, 13) || !keyExists(dict, 14) || !keyExists(dict, 20) || !keyExists(dict, 25) || keyExists(dict, 15))
	{
		printf("Третий тест провален\n");
		result = false;
	}
	deleteElement(dict, 20);
	if (!keyExists(dict, 13) || !keyExists(dict, 14) || keyExists(dict, 20) || !keyExists(dict, 25))
	{
		printf("Четвертый тест провален\n");
		result = false;
	}
	deleteDict(&dict);
	return result;
}