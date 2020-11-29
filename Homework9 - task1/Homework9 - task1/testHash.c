#include "testHash.h"
#include "hashTable.h"
#include "hashFilling.h"
#include <stdio.h>

bool testHash(void)
{	
	bool result = true;
	HashTable* table = createTable();
	add(table, "Sam");
	add(table, "Pam");
	add(table, "Jam");
	add(table, "Sam");
	if (tableSize(table) != 5)
	{
		printf("Первый тест на хэштаблицы провален\n");
		result = false;
	}
	if (!valueExist(table, "Sam"))
	{
		printf("Второй тест на хэштаблицы провален\n");
		result = false;
	}
	if (getFillFactor(table) != 0.6f)
	{
		printf("Третий тест на хэштаблицы провален\n");
		result = false;
	}
	add(table, "Tom");
	if (tableSize(table) != 10)
	{
		printf("Четвертый тест на хэштаблицы провален\n");
		result = false;
	}
	if (getFillFactor(table) != 0.4f)
	{
		printf("Пятый тест на хэштаблицы провален\n");
		result = false;
	}
	deleteTable(&table);
	return result;
}

bool testReadFromFile(void)
{	
	bool result = true;
	HashTable* table = createTable();
	fillTable(table, "test.txt");
	if (tableSize(table) != 10)
	{
		result = false;
	}
	if (getFillFactor(table) != 0.5f)
	{
		result = false;
	}
	char word1[] = "lol";
	char word2[] = "xd";
	char word3[] = "idk";
	char word4[] = ":)";
	char word5[] = "lmao";
	if (!valueExist(table, word1) || !valueExist(table, word2) || !valueExist(table, word3) || !valueExist(table, word4) || !valueExist(table, word5))
	{
		result = false;
	}
	deleteTable(&table);
	return result;
}