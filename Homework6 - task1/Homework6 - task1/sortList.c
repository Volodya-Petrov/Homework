#include "sortList.h"
#include <stdlib.h>
#include <stdbool.h>

struct ListElement
{
	int value;
	struct ListElement* next;
};

struct List
{	
	int length;
	struct ListElement* head;
};

int length(struct List* list)
{
	if (list == NULL)
	{
		return 0;
	}
	return list->length;
}

int* fillArray(struct List* list)
{
	if (list->head == NULL)
	{
		return NULL;
	}
	int* array = calloc(length(list), sizeof(int));
	if (array == NULL)
	{
		return NULL;
	}
	int index = 0;
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		array[index] = currentElement->value;
		currentElement = currentElement->next;
		index++;
	}
	return array;
}

struct List* createList()
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->head = NULL;
	newList->length = 0;
	return newList;
}

bool delElement(struct List* list, int value)
{	
	if (list == NULL)
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (list->head->value == value)
	{
		struct ListElement* oldElement = list->head;
		list->head = list->head->next;
		free(oldElement);
		list->length--;
		return true;
	}
	struct ListElement* currentElement = list->head;
	while (currentElement->next != NULL && currentElement->next->value < value)
	{
		currentElement = currentElement->next;
	}
	if (currentElement->next == NULL || currentElement->next->value != value)
	{
		return false;
	}
	struct ListElement* oldElement = currentElement->next;
	currentElement->next = currentElement->next->next;
	free(oldElement);
	list->length--;
	return true;
}

void add(struct List* list, int value)
{	
	if (list == NULL)
	{
		return;
	}
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	list->length++;
	if (list->head == NULL || value <= list->head->value)
	{
		newElement->next = list->head;
		list->head = newElement;
		return;
	}
	struct ListElement* currentElement = list->head;
	while (currentElement->next != NULL && currentElement->next->value < value)
	{
		currentElement = currentElement->next;
	}
	newElement->next = currentElement->next;
	currentElement->next = newElement;
	return;
}

void deleteList(struct List** list)
{	
	if (list == NULL)
	{
		return;
	}
	while ((*list)->head != NULL)
	{
		struct ListElement* oldElement = (*list)->head;
		(*list)->head = (*list)->head->next;
		free(oldElement);
	}
	free(*list);
	*list = NULL;
}
