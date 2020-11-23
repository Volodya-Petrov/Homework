#pragma once

#include <stdbool.h>

// структура списка
struct List;

// создание списка
struct List* createList();

// получение длины списка
int length(struct List* list);

// заполнение массива элементами листа
int* fillArray(struct List* list);

// удаление элемента из списка по значению
bool delElement(struct List* list, int value);

// добавление элемента в список по значению
void add(struct List* list, int value);

// удаление списка
void deleteList(struct List** list);