#pragma once

#include <stdbool.h>

// структура списка
typedef struct List List;

// создание списка
List* createList();

// получение длины списка
int length(List* list);

// добавление элемента в конец списка
bool append(List* list, int value);

// получение индекса элемента по значению
int indexOf(List* list, int value);

// удаление элемента из списка по индексу
bool deleteElement(struct List* list, int index);

// удаление списка
void deleteList(List** list);

// получение значение по индексу
bool getValue(List* list, int index, int* value);