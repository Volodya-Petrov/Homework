#pragma once

#include <stdbool.h>

enum Contact
{
	NAME,
	NUMBER
};

// структура списка
struct List;

// создание списка
struct List* createList();

// получение длины списка
int getLength(struct List* list);

// добавление элемента в конец списка
bool append(struct List* list, char name[], char number[]);

// удаление элемента
bool deleteElement(struct List* list, int index);

// получение значения по индексу
bool getValue(struct List* list, int index, enum Contact indexInStruct, char destination[]);

// меняет значение элемента по индексу
bool changeValue(struct List* list, int index, enum Contact indexInStruct, char source[]);

// удаляет список
void deleteList(struct List** list);

// создает список в котором содержатся элементы "list" от индекса "beginIndex" до "endIndex"
struct List* copy(struct List* list, int beginIndex, int endIndex);

// выводит список на экран
void printList(struct List* list);