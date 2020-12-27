#pragma once

#include <stdbool.h>

// структура списка
struct List;

// создание списка
struct List* createList();

// получение длины списка
int getLength(struct List* list);

// получение индекса элемента по значению
int indexOf(struct List* list, int value);

// добавляет элемент в конец списка
bool append(struct List* list, int value);

// удаление элемента по индексу
bool deleteElement(struct List* list, int index);

// удаление списка
void deleteList(struct List** list);

// получение значение элемента по индексу
int getValue(struct List* list, int index);