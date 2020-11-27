#pragma once

#include <stdbool.h>

typedef struct List List;

List* createList();

int length(List* list);

bool append(List* list, int value);

int indexOf(List* list, int value);

bool deleteElement(struct List* list, int index);

void deleteList(List** list);

