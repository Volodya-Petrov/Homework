#pragma once

#include <stdbool.h>

// структура хэш таблицы
typedef struct HashTable HashTable;

// создание хэш таблицы
HashTable* createTable(void);

// добавление элемента в хэш таблицу/ властелин остаетс€ властелином "value"
void add(HashTable* hashTable, char* value);

// получение филл фактора
float getFillFactor(HashTable* table);

// выдает среднюю длину списка в сегменте таблицы
float averageFilling(HashTable* table);

// выдает максимальную длину списка в сегменте таблицы
int maxFilling(HashTable* table);

// выводит в консоли элементы таблицы и их количество
void printTable(HashTable* table);

// удаление хэш таблицы
void deleteTable(HashTable** table);

// проверка на существование элемента в таблице/ властелин остаетс€ властелином "value"
bool valueExist(HashTable* table, char* value);

// возвращает количество €чеек в таблице
int tableSize(HashTable* table);