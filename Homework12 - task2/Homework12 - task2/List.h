#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// �������� ������
List* createList();

// ��������� ����� ������
int length(List* list);

// ���������� �������� � ����� ������
bool append(List* list, int firstIndex, int secondIndex);

// �������� �������� �� ������ �� �������
bool deleteElement(struct List* list, int index);

// �������� ������
void deleteList(List** list);

// ��������� �������� �� �������
bool getValue(List* list, int index, int* firstValue, int* secondValue);