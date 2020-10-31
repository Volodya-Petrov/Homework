#include "sortList.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{	
	struct List* newList = createList();
	addElement(newList, 7);
	addElement(newList, 5);
	//printf("Длина списка = %i\n", getLength(newList));
	addElement(newList, 9);
	int* array = calloc(getLength(newList), sizeof(int));
	getList(newList, array, 0);
	for (int i = 0; i < getLength(newList); i++)
	{
		printf("%i ", array[i]);
	}
	free(array);
	printf("\n");
	addElement(newList, 2);
	//printf("Длина списка = %i\n", getLength(newList));
	deleteElement(newList, 7);
	array = calloc(getLength(newList), sizeof(int));
	getList(newList, array, 0);
	for (int i = 0; i < getLength(newList); i++)
	{
		printf("%i ", array[i]);
	}
	free(array);
	//printf("Длина списка = %i\n", getLength(newList));
	deleteList(&newList);
}