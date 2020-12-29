#pragma once

#include <stdbool.h>

// ��������� ������
struct List;

// �������� ������
struct List* createList();

// ��������� ����� ������
int length(struct List* list);

// ���������� ������� ���������� �����
int* fillArray(struct List* list);

// �������� �������� �� ������ �� ��������
bool delElement(struct List* list, int value);

// ���������� �������� � ������ �� ��������
void add(struct List* list, int value);

// �������� ������
void deleteList(struct List** list);