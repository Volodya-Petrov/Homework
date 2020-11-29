#pragma once

#include <stdbool.h>

typedef struct List List;

List* createList();

int length(List* list);

int getCount(List* list, int index);

char* getValue(List* list, int index);

int indexOf(List* list, char* value);

bool append(List* list, char* value);

bool deleteElement(struct List* list, int index);

void deleteList(List** list);

