#pragma once

#include <stdbool.h>

struct List;

struct List* createList();

int getLength(struct List* list);

bool append(struct List* list, char name[], char number[]);

bool deleteElement(struct List* list, int index);

bool getValue(struct List* list, int index, int indexInStruct, char string[]);

bool changeValue(struct List* list, int index, int indexInStruct, char string[]);

void deleteList(struct List** list);

struct List* copy(struct List* list, int beginIndex, int endIndex);