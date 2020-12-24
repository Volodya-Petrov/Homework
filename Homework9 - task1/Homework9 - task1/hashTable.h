#pragma once

#include <stdbool.h>

// ��������� ��� �������
typedef struct HashTable HashTable;

// �������� ��� �������
HashTable* createTable(void);

// ���������� �������� � ��� �������/ ��������� �������� ����������� "value"
void add(HashTable* hashTable, char* value);

// ��������� ���� �������
float getFillFactor(HashTable* table);

// ������ ������� ����� ������ � �������� �������
float averageFilling(HashTable* table);

// ������ ������������ ����� ������ � �������� �������
int maxFilling(HashTable* table);

// ������� � ������� �������� ������� � �� ����������
void printTable(HashTable* table);

// �������� ��� �������
void deleteTable(HashTable** table);

// �������� �� ������������� �������� � �������/ ��������� �������� ����������� "value"
bool valueExist(HashTable* table, char* value);

// ���������� ���������� ����� � �������
int tableSize(HashTable* table);