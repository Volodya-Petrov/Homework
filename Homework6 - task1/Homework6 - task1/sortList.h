#pragma once

#include <stdbool.h>

struct ListElement;

int getLength(struct List* list);

void getList(struct List* list, int array[], int index);

bool deleteElement(struct List* list, int value);

struct List;

struct List* createList();

void addElement(struct List* list, int value);

void deleteList(struct List** list);