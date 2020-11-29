#pragma once

#include <stdbool.h>

typedef struct HashTable HashTable;

HashTable* createTable(void);

void add(HashTable* hashTable, char* value);

float getFillFactor(HashTable* table);

float averageFilling(HashTable* table);

int maxFilling(HashTable* table);

void printTable(HashTable* table);

void deleteTable(HashTable** table);