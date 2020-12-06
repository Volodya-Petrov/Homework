#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListElement
{
	int value;
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
	List* newList = malloc(sizeof(List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->length = 0;
	newList->head = NULL;
	newList->tail = NULL;
	return newList;
}

int length(List* list)
{
	if (list->head == NULL || list->tail == NULL)
	{
		return 0;
	}
	return list->length;
}

bool append(List* list, int value)
{
	ListElement* newElement = malloc(sizeof(ListElement));
	if (newElement == NULL)
	{
		return false;
	}
	list->length++;
	newElement->next = NULL;
	newElement->value = value;
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

int indexOf(List* list, int value)
{
	if (list->head == NULL)
	{
		return -1;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		if (currentElement->value == value)
		{
			return currentIndex;
		}
		currentElement = currentElement->next;
		currentIndex++;
	}
	return -1;
}

bool getValue(List* list, int index, int *value)
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
			*value = currentElement->value;
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
		free(oldElement);
		list->length--;
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

