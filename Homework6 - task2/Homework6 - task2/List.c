#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListElement
{	
	int value;
	struct ListElement* next;
};

struct List
{
	struct ListElement* head;
	struct ListElement* tail;
	int length;
};

struct List* createList()
{
	return calloc(1, sizeof(struct List));
}

int getLength(struct List* list)
{
	return list->length;
}

bool append(struct List* list, int value)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return false;
	}
	newElement->value = value;
	list->length++;
	if (list->head == NULL)
	{
		newElement->next = newElement;
		list->head = newElement;
		list->tail = newElement;
		return true;
	}
	list->tail->next = newElement;
	newElement->next = list->head;
	list->tail = newElement;
	return true;
}

int indexOf(struct List* list, int value)
{
	if (list->head == NULL)
	{
		return -1;
	}
	if (list->head->value == value)
	{
		return 0;
	}
	int currentIndex = 1;
	struct ListElement* currentElement = list->head->next;
	while (currentElement != list->head)
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

int getValue(struct List* list, int index)
{
	if (index >= getLength(list) || index < 0)
	{
		return 0;
	}
	struct ListElement* currentElement = list->head;
	int currentIndex = 0;
	while (true)
	{
		if (currentIndex == index)
		{
			return currentElement->value;
		}
		currentIndex++;
		currentElement = currentElement->next;
	}
}

bool deleteElement(struct List* list, int index)
{	
	if (index < 0 || index >= getLength(list))
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (index == 0)
	{	
		struct ListElement* oldElement = list->head;
		if (getLength(list) == 1)
		{
			list->head = NULL;
			list->tail = NULL;
			free(oldElement);
			list->length--;
			return true;
		}
		list->head = list->head->next;
		list->tail->next = list->head;
		list->length--;
		free(oldElement);
		return true;
	}
	int currentIndex = 0;
	struct ListElement* currentElement = list->head;
	while (true)
	{
		if (index - currentIndex == 1)
		{
			struct ListElement* oldElement = currentElement->next;
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

void deleteList(struct List** list)
{
	while (getLength(*list) > 0)
	{
		deleteElement(*list, 0);
	}
	free(*list);
	*list = NULL;
}