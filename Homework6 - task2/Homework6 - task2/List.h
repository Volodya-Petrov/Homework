#pragma once

#include <stdbool.h>

// ��������� ������
struct List;

// �������� ������
struct List* createList();

// ��������� ����� ������
int getLength(struct List* list);

// ��������� ������� �������� �� ��������
int indexOf(struct List* list, int value);

// ��������� ������� � ����� ������
bool append(struct List* list, int value);

// �������� �������� �� �������
bool deleteElement(struct List* list, int index);

// �������� ������
void deleteList(struct List** list);

// ��������� �������� �������� �� �������
int getValue(struct List* list, int index);