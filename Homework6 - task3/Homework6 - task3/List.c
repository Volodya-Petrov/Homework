#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct ListElement
{
	char name[20];
	char number[20];
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

bool append(struct List* list, char name[], char number[])
{
	struct ListElement* newElement = malloc(sizeof(struct ListElement));
	if (newElement == NULL)
	{
		return false;
	}
	list->length++;
	newElement->next = NULL;
	strcpy(newElement->name, name);
	strcpy(newElement->number, number);
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

struct ListElement* getParentOfElement(struct List* list, int index)
{	
	if (index == 0)
	{
		return NULL;
	}
	int currentIndex = 0;
	struct ListElement* currentElement = list->head;
	while (true)
	{
		if (index - 1 == currentIndex)
		{
			return currentElement;
		}
		currentElement->next;
		currentIndex++;
	}
}

bool getValue(struct List* list, int index, enum Contact indexInStruct, char destination[])
{
	if (index < 0 || index >= getLength(list))
	{
		return false;
	}
	if (indexInStruct != 1 && indexInStruct != 0)
	{
		return false;
	}
	struct ListElement* parent = getParentOfElement(list, index);
	struct ListElement* needElement = list->head;
	if (parent != NULL)
	{
		needElement = parent->next;
	}
	if (indexInStruct == NAME)
	{
		strcpy(destination, needElement->name);
	}
	else
	{
		strcpy(destination, needElement->number);
	}
	return true;
}

bool deleteElement(struct List* list, int index)
{
	if (index < 0 || index >= getLength(list))
	{
		return false;
	}
	list->length--;
	struct ListElement* parent = getParentOfElement(list, index);
	if (parent == NULL)
	{
		struct ListElement* oldElement = list->head;
		list->head = oldElement->next;
		if (list->head == NULL)
		{
			list->tail = NULL;
		}
		free(oldElement);
		return true;
	}
	struct ListElement* oldElement = parent->next;
	parent->next = oldElement->next;
	if (list->tail == oldElement)
	{
		list->tail = parent;
	}
	free(oldElement);
	return true;
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

bool changeValue(struct List* list, int index, enum Contact indexInStruct, char source[])
{
	if (index < 0 || index >= getLength(list))
	{
		return false;
	}
	if (indexInStruct != 1 && indexInStruct != 0)
	{
		return false;
	}
	struct ListElement* parent = getParentOfElement(list, index);
	struct ListElement* needElement = list->head;
	if (parent != NULL)
	{
		needElement = parent->next;
	}
	if (indexInStruct == NAME)
	{
		strcpy(needElement->name, source);
	}
	else
	{
		strcpy(needElement->number, source);
	}
	return true;
}

void copyElement(struct List* sourceList, struct List* destinitionList, int beginIndex, int endIndex)
{
	int currentIndex = beginIndex;
	struct ListElement* parent = getParentOfElement(sourceList, beginIndex);
	struct ListElement* currentElement = sourceList->head;
	if (parent != NULL)
	{
		currentElement = parent->next;
	}
	while (beginIndex <= currentIndex && currentIndex <= endIndex)
	{
		append(destinitionList, currentElement->name, currentElement->number);
		currentIndex++;
		currentElement = currentElement->next;
	}
}


struct List* copy(struct List* list, int beginIndex, int endIndex)
{
	if (endIndex - beginIndex < 0)
	{
		return NULL;
	}
	if (endIndex >= getLength(list) || beginIndex >= getLength(list))
	{
		return NULL;
	}
	struct List* newList = createList();
	if (newList == NULL)
	{
		return NULL;
	}
	copyElement(list, newList, beginIndex, endIndex);
	return newList;
}


void printList(struct List* list)
{
	struct ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		printf("%s - %s\n", currentElement->name, currentElement->number);
		currentElement = currentElement->next;
	}
}

