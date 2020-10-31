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

void helperGetList(struct ListElement* element, int array[], int index)
{
	array[index] = element->value;
	if (element->next == NULL)
	{
		return;
	}
	helperGetList(element->next, array, index + 1);
}

void getList(struct List* list, int array[], int index)
{
	if (list->head == NULL)
	{
		return;
	}
	array[index] = list->head->value;
	if (list->head->next == NULL)
	{
		return;
	}
	helperGetList(list->head->next, array, index + 1);
}

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

int helperGetLength(struct ListElement* element)
{
	if (element->next == NULL)
	{
		return 1;
	}
	return 1 + helperGetLength(element->next);
}

int getLength(struct List* list)
{
	if (list->head == NULL)
	{
		return 0;
	}
	return helperGetLength(list->head);
}

bool helperForDelete(struct ListElement* element, int value)
{
	if (element->next == NULL)
	{
		return false;
	}
	if (element->next->value == value)
	{
		struct ListElement* oldElement = element->next;
		element->next = element->next->next;
		free(oldElement);
		return true;
	}
	return helperForDelete(element->next, value);
}

bool deleteElement(struct List* list, int value)
{
	if (list->head == NULL)
	{
		return false;
	}
	if (list->head->value == value)
	{
		struct ListElement* oldElement = list->head;
		list->head = list->head->next;
		free(oldElement);
		return true;
	}
	return helperForDelete(list->head, value);
}

void helperInsert(struct ListElement* element, int value)
{
	if (element->next == NULL)
	{
		struct ListElement* newElement = malloc(sizeof(struct ListElement));
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
		struct ListElement* newElement = malloc(sizeof(struct ListElement));
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
		struct ListElement* newElement = malloc(sizeof(struct ListElement));
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
