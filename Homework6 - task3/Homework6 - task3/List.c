#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListElement
{	
	char name[20];
	char number[20];
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

bool helperAppend(struct ListElement* element, char name[], char number[])
{
	if (element->next == NULL)
	{
		struct ListElement* newElement = malloc(sizeof(struct ListElement));
		if (newElement == NULL)
		{
			return false;
		}
		strcpy(newElement->name, name);
		strcpy(newElement->number, number);
		newElement->next = NULL;
		element->next = newElement;
		return true;
	}
	return helperAppend(element->next, name, number);
}

bool append(struct List* list, char name[], char number[])
{
	if (list->head == NULL)
	{
		struct ListElement* newElement = malloc(sizeof(struct ListElement));
		if (newElement == NULL)
		{
			return false;
		}
		strcpy(newElement->name, name);
		strcpy(newElement->number, number);
		newElement->next = NULL;
		list->head = newElement;
		return true;
	}
	return helperAppend(list->head, name, number);
}

bool helperDelete(struct ListElement* element, int indexToDelete, int currentIndex)
{
	if (element->next == NULL)
	{
		return false;
	}
	if (indexToDelete - currentIndex == 1)
	{
		struct ListElement* oldElement = element->next;
		element->next = element->next->next;
		free(oldElement);
		return true;
	}
	return helperDelete(element->next, indexToDelete, currentIndex + 1);
}

bool deleteElement(struct List* list, int index)
{	
	if (index < 0)
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
		list->head = list->head->next;
		free(oldElement);
		return true;
	}
	return helperDelete(list->head, index, 1);
}

bool helperGetValue(struct ListElement* element, int index, int indexInStruct, char string[], int currentIndex)
{
	if (currentIndex == index)
	{
		if (indexInStruct == 0)
		{
			strcpy(string, element->name);
		}
		else
		{
			strcpy(string, element->number);
		}
		return true;
	}
	if (element->next == NULL)
	{
		return false;
	}
	return helperGetValue(element->next, index, indexInStruct, string, currentIndex + 1);
}

bool getValue(struct List* list, int index, int indexInStruct, char string[])
{	
	if (index < 0)
	{
		return false;
	}
	if (indexInStruct != 0 && indexInStruct != 1)
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (index == 0)
	{
		if (indexInStruct == 0)
		{
			strcpy(string, list->head->name);
		}
		else
		{
			strcpy(string, list->head->number);
		}
		return true;
	}
	return helperGetValue(list->head->next, index, indexInStruct, string, 1);
}

bool helperChangeValue(struct ListElement* element, int index, int indexInStruct, char string[], int currentIndex)
{
	if (currentIndex == index)
	{
		if (indexInStruct == 0)
		{
			strcpy(element->name, string);
		}
		else
		{
			strcpy(element->number, string);
		}
		return true;
	}
	if (element->next == NULL)
	{
		return false;
	}
	return helperChangeValue(element->next, index, indexInStruct, string, currentIndex + 1);
}

bool changeValue(struct List* list, int index, int indexInStruct, char string[])
{
	if (index < 0)
	{
		return false;
	}
	if (indexInStruct != 0 && indexInStruct != 1)
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (index == 0)
	{
		if (indexInStruct == 0)
		{
			strcpy(list->head->name, string);
		}
		else
		{
			strcpy(list->head->number, string);
		}
		return true;
	}
	return helperChangeValue(list->head->next, index, indexInStruct, string, 1);
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