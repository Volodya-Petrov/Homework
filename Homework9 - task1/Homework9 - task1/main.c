#include "hashTable.h"
#include "hashFilling.h"
#include "listTests.h"
#include "testHash.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

bool resultOfTests(void)
{
	return !(!testList() + !testHash() + !testReadFromFile());
}

int main(void)
{
	setlocale(LC_ALL, "rus");
	if (!resultOfTests())
	{
		return 1;
	}
	printf("Тесты успешно пройдены!\n");
	HashTable* table = createTable();
	fillTable(table, "text.txt");
	printf("FillFactor хэш таблицы: %f\n", getFillFactor(table));
	printf("Сегмент с максимальной длиной: %i\n", maxFilling(table));
	printf("Средння длина сегмента: %f\n", averageFilling(table));
	printTable(table);
	deleteTable(&table);
}