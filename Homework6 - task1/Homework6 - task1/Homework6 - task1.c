#include "sortList.h"
#include <stdlib.h>

int main(void)
{	
	struct List* newList = createList();
	addElement(newList, 7);
	addElement(newList, 5);
	addElement(newList, 9);
	addElement(newList, 2);
	deleteList(&newList);
}