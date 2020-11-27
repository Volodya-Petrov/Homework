#include "../../List/List/List.h"
#include <stdlib.h>
#include <string.h>

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
	newTable->fillFactor = 0;
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
	}
	return newTable;
}

int hashTableSize(HashTable* hashTable)
{
	if (hashTable == NULL)
	{
		return 0;
	}
	return hashTable->length;
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
	List** newHashTable = malloc(hashTable->length * 2 * sizeof(List*));
	if (newHashTable == NULL)
	{
		return false;
	}

	hashTable->length *= 2;
	hashTable->fillFactor /= 2;
}

bool add(HashTable* hashTable, char* value)
{	
	if (hashTable == NULL)
	{
		return false;
	}
	int key = hashFunction(value, hashTableSize(hashTable));
	int oldLength = length(hashTable->hashTable[key]);
	append(hashTable->hashTable[key], value);
	if (oldLength != length(hashTable->hashTable[key]))
	{
		hashTable->fillFactor += 1 / hashTableSize(hashTable);
	}
	if (hashTable->fillFactor > 0.75f)
	{
		
	}
}