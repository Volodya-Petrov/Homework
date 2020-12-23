#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListElement
{
	int beginIndex;
	int endIndex;
	struct ListElement* next;
} ListElement;

typedef struct List
{	
	int length;
	ListElement* head;
	ListElement* tail;
} List;

List* createList()
{
	return calloc(1, sizeof(List));
}

int length(List* list)
{
	if (list->head == NULL || list->tail == NULL)
	{
		return 0;
	}
	return list->length;
}

bool append(List* list, int firstIndex, int secondIndex)
{
	ListElement* newElement = malloc(sizeof(ListElement));
	if (newElement == NULL)
	{
		return false;
	}
	list->length++;
	newElement->next = NULL;
	newElement->beginIndex = firstIndex;
	newElement->endIndex = secondIndex;
	if (list->head == NULL)
	{
		list->head = newElement;
		list->tail = newElement;
		return true;
	}
	list->tail->next = newElement;
	list->tail = newElement;
	return true;
}

bool getValue(List* list, int index, int *firstValue, int *secondValue)
{
	if (list == NULL || list->head == NULL)
	{
		return false;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		if (index == currentIndex)
		{
			*firstValue = currentElement->beginIndex;
			*secondValue = currentElement->endIndex;
			return true;
		}
		currentIndex++;
		currentElement = currentElement->next;
	}
	return false;
}

bool deleteElement(struct List* list, int index)
{
	if (index < 0 || index >= length(list))
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (index == 0)
	{
		ListElement* oldElement = list->head;
		if (length(list) == 1)
		{
			list->head = NULL;
			list->tail = NULL;
			list->length--;
			free(oldElement);
			return true;
		}
		list->head = list->head->next;
		list->length--;
		free(oldElement);
		return true;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (true)
	{
		if (index - currentIndex == 1)
		{
			ListElement* oldElement = currentElement->next;
			currentElement->next = currentElement->next->next;
			if (oldElement == list->tail)
			{
				list->tail = currentElement;
			}
			free(oldElement);
			list->length--;
			return true;
		}
		currentIndex++;
		currentElement = currentElement->next;
	}
}

void deleteList(List** list)
{
	while (length(*list) > 0)
	{
		deleteElement(*list, 0);
	}
	free(*list);
	*list = NULL;
}