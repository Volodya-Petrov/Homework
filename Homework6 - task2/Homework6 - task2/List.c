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
};

struct List* createList()
{
	struct List* newList = malloc(sizeof(struct List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->head = NULL;
	newList->tail = NULL;
	return newList;
}

int getLength(struct List* list)
{
	if (list->head == NULL)
	{
		return 0;
	}
	int result = 1;
	struct ListElement* currentElement = list->head->next;
	while (currentElement != list->head)
	{
		result++;
		currentElement = currentElement->next;
	}
	return result;
}

bool append(struct List* list, int value)
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return false;
	}
	newElement->value = value;
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
			break;
		}
		currentElement = currentElement->next;
		currentIndex++;
	}
	if (currentElement == list->head)
	{
		return -1;
	}
	return currentIndex;
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
			return true;
		}
		list->head = list->head->next;
		list->tail->next = list->head;
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

int getPos(int count, int period)
{
	struct List* list = createList();
	if (list == NULL)
	{
		return -1;
	}
	for (int i = 1; i < count + 1; i++)
	{
		if (!append(list, i))
		{
			return -1;
		}
	}
	int step = 1;
	struct ListElement* currentElement = list->head;
	while (getLength(list) != 1)
	{
		if (step == period)
		{
			step = 1;
			struct ListElement* oldElement = currentElement;
			currentElement = currentElement->next;
			deleteElement(list, indexOf(list, oldElement->value));
			continue;
		}
		currentElement = currentElement->next;
		step++;
	}
	int result = currentElement->value;
	deleteList(&list);
	return result;
}