#pragma once

#include <stdbool.h>

enum Contact
{
	NAME,
	NUMBER
};

// ��������� ������
struct List;

// �������� ������
struct List* createList();

// ��������� ����� ������
int getLength(struct List* list);

// ���������� �������� � ����� ������
bool append(struct List* list, char name[], char number[]);

// �������� ��������
bool deleteElement(struct List* list, int index);

// ��������� �������� �� �������
bool getValue(struct List* list, int index, enum Contact indexInStruct, char destination[]);

// ������ �������� �������� �� �������
bool changeValue(struct List* list, int index, enum Contact indexInStruct, char source[]);

// ������� ������
void deleteList(struct List** list);

// ������� ������ � ������� ���������� �������� "list" �� ������� "beginIndex" �� "endIndex"
struct List* copy(struct List* list, int beginIndex, int endIndex);

// ������� ������ �� �����
void printList(struct List* list);