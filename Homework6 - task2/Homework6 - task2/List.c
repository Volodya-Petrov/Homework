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

int helperGetLength(struct List* list, struct ListElement* element)
{
	if (element->next == list->head)
	{
		return 1;
	}
	return 1 + helperGetLength(list, element->next);
}

int getLength(struct List* list)
{
	if (list->head == NULL)
	{
		return 0;
	}
	return helperGetLength(list, list->head);
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

int helperIndexOf(struct List* list, struct ListElement* element, int value, int currentIndex)
{
	if (element == list->head)
	{
		return -1;
	}
	if (element->value == value)
	{
		return currentIndex;
	}
	return helperIndexOf(list, element->next, value, currentIndex + 1);
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
	return helperIndexOf(list, list->head->next, value, 1);
}

bool helperDelete(struct List* list, struct ListElement* element, int indexToDelete, int currentIndex)
{
	if (indexToDelete - currentIndex == 1)
	{				
		struct ListElement* oldElement = element->next;
		element->next = element->next->next;
		if (oldElement == list->tail)
		{
			list->tail = element;
		}
		free(oldElement);
		return true;
	}
	return helperDelete(list, element->next, indexToDelete, currentIndex + 1);
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
	return helperDelete(list, list->head, index, 0);
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

int getPosHelper(struct List* list, struct ListElement* element, int period, int currentStep)
{
	if (getLength(list) == 1)
	{
		return element->value;
	}
	if (currentStep == period)
	{	
		currentStep = 0;
		struct ListElement* next = element->next;
		deleteElement(list, indexOf(list, element->value));
		return getPosHelper(list, next, period, currentStep + 1);
	}
	return getPosHelper(list, element->next, period, currentStep + 1);
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
	int result = getPosHelper(list, list->head, period, 1);
	deleteList(&list);
	return result;
}