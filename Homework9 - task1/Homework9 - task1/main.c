#include "hashTable.h"
#include "hashFilling.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "rus");
	HashTable* table = createTable();
	fillTable(table, "text.txt");
	printf("FillFactor хэш таблицы: %f\n", getFillFactor(table));
	printf("Сегмент с максимальной длиной: %i\n", maxFilling(table));
	printf("Средння длина сегмента: %f\n", averageFilling(table));
	printTable(table);
	deleteTable(&table);
}