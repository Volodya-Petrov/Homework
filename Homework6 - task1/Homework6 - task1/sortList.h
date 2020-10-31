#pragma once

struct List;

struct List* createList();

void addElement(struct List* list, int value);

void deleteList(struct List** list);