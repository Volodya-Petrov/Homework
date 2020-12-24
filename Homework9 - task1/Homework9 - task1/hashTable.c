#include "../../List/List/List.h"
#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE_OF_TABLE 5

typedef struct HashTable
{	
	int length;
	List** hashTable;
	float fillFactor;
} HashTable;

HashTable* createTable(void)
{
	HashTable* newTable = malloc(sizeof(HashTable));
	if (newTable == NULL)
	{
		return NULL;
	}
	newTable->fillFactor = 0.0f;
	newTable->length = SIZE_OF_TABLE;
	newTable->hashTable = malloc(SIZE_OF_TABLE * sizeof(List*));
	if (newTable->hashTable == NULL)
	{
		free(newTable);
		return NULL;
	}
	for (int i = 0; i < SIZE_OF_TABLE; i++)
	{
		newTable->hashTable[i] = createList();
		if (newTable->hashTable[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				deleteList(&(newTable->hashTable[j]));
			}
			free(newTable->hashTable);
			free(newTable);
			return NULL;
		}
	}
	return newTable;
}

int hashFunction(char* string, int tableSize)
{	
	int hashResult = 0;
	int mutuallyPrime = tableSize + 1;
	for (int i = 0; i < strlen(string); i++)
	{
		hashResult = (mutuallyPrime * hashResult + string[i]) % tableSize;
	}
	hashResult = (2 * hashResult + 1) % tableSize;
	return hashResult;
}

bool rehash(HashTable* hashTable)
{	
	int newLength = hashTable->length * 2;
	List** newHashTable = malloc(newLength * sizeof(List*));
	if (newHashTable == NULL)
	{
		return false;
	}
	for (int i = 0; i < newLength; i++)
	{
		newHashTable[i] = createList();
		if (newHashTable[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				deleteList(&newHashTable[j]);
			}
			free(newHashTable);
			return false;
		}
	}
	for (int i = 0; i < hashTable->length; i++)
	{	
		int lenOfPart = length(hashTable->hashTable[i]);
		for (int j = 0; j < lenOfPart; j++)
		{	
			const char* value = getValue(hashTable->hashTable[i], 0);
			const int key = hashFunction(value, newLength);
			for (int k = 0; k < getCount(hashTable->hashTable[i], 0); k++)
			{
				append(newHashTable[key], value);
			}
			deleteElement(hashTable->hashTable[i], 0);
		}
		deleteList(&(hashTable->hashTable[i]));
	}
	hashTable->length *= 2;
	hashTable->fillFactor /= 2;
	free(hashTable->hashTable);
	hashTable->hashTable = newHashTable;
	return true;
}

void add(HashTable* hashTable, char* value)
{	
	if (hashTable == NULL)
	{
		return;
	}
	int key = hashFunction(value, hashTable->length);
	int oldLength = length(hashTable->hashTable[key]);
	append(hashTable->hashTable[key], value);
	if (oldLength != length(hashTable->hashTable[key]))
	{
		hashTable->fillFactor += 1.0f / hashTable->length;
	}
	if (hashTable->fillFactor > 0.75f)
	{
		rehash(hashTable);
	}
}

float getFillFactor(HashTable* table)
{	
	if (table == NULL)
	{
		return 0;
	}
	return table->fillFactor;
}

float averageFilling(HashTable* table)
{	
	if (table == NULL)
	{
		return 0;
	}
	float result = 0.0f;
	for (int i = 0; i < table->length; i++)
	{
		result += (float) length(table->hashTable[i]);
	}
	result /= (float) table->length;
	return result;
}

int maxFilling(HashTable* table)
{	
	if (table == NULL)
	{
		return 0;
	}
	int maxResult = length(table->hashTable[0]);
	for (int i = 1; i < table->length; i++)
	{
		int len = length(table->hashTable[i]);
		if (len > maxResult)
		{
			maxResult = len;
		}
	}
	return maxResult;
}

void printTable(HashTable* table)
{	
	if (table == NULL)
	{
		return;
	}
	for (int i = 0; i < table->length; i++)
	{
		for (int j = 0; j < length(table->hashTable[i]); j++)
		{
			printf("%s - %i\n", getValue(table->hashTable[i], j), getCount(table->hashTable[i], j));
		}
	}
}

void deleteTable(HashTable** table)
{	
	if (*table == NULL)
	{
		return;
	}
	for (int i = 0; i < (*table)->length; i++)
	{
		deleteList(&((*table)->hashTable[i]));
	}
	free((*table)->hashTable);
	free(*table);
	*table = NULL;
}

bool valueExist(HashTable* table, char* value)
{	
	if (table == NULL)
	{
		return false;
	}
	int key = hashFunction(value, table->length);
	return indexOf(table->hashTable[key], value) != -1;
}

int tableSize(HashTable* table)
{	
	if (table == NULL)
	{
		return 0;
	}
	return table->length;
}