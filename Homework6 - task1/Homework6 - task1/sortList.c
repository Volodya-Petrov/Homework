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
	struct ListElement* head;
};

struct List* createList()
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->head = NULL;
	return newList;
}

void helperInsert(struct ListElement* element, int value)
{
	if (element->next == NULL)
	{
		struct ListElement* newElement = malloc(sizeof(newElement));
		if (newElement != NULL)
		{
			newElement->value = value;
			newElement->next = NULL;
		}
		element->next = newElement;
		return;
	}
	if (element->next->value >= value)
	{
		struct ListElement* newElement = malloc(sizeof(newElement));
		if (newElement == NULL)
		{
			return;
		}
		newElement->value = value;
		newElement->next = element->next;
		element->next = newElement;
		return;
	}
	helperInsert(element->next, value);
}

void addElement(struct List* list, int value)
{	
	if (list->head == NULL || list->head->value >= value)
	{
		struct ListElement* newElement = malloc(sizeof(newElement));
		if (newElement == NULL)
		{
			return;
		}
		newElement->value = value;
		newElement->next = list->head;
		list->head = newElement;
		return;
	}
	helperInsert(list->head, value);
}

bool getLastElement(struct List* list, int* value)
{
	if (list->head == NULL)
	{
		return false;
	}
	*value = list->head->value;
	struct ListElement* oldElement = list->head;
	list->head = list->head->next;
	free(oldElement);
	return true;
}

void deleteList(struct List** list)
{
	int value = 0;
	while (getLastElement(*list, &value))
	{

	}
	free(*list);
	*list = NULL;
}
