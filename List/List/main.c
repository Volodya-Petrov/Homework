#include "List.h"

int main(void)
{
	List* list = createList();
	append(list, 6);
	append(list, 5);
	append(list, 7);
	int k = indexOf(list, 5);
	deleteElement(list, 0);
	int size = length(list);
	deleteList(&list);
}