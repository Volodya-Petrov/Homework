#pragma once

#include <stdbool.h>

struct List;

struct List* createList();

int getLength(struct List* list);

bool append(struct List* list, int value);

bool deleteElement(struct List* list, int index);

void deleteList(struct List** list);

int getPos(int count, int period);