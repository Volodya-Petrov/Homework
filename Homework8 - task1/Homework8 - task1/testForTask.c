#include "avl.h"
#include <string.h>
#include <stdbool.h>

bool tests(void)
{	
	bool result = true;
	Tree* tree = createTree();
	insert(tree, "Bob", "Lol");
	insert(tree, "Plamya", "Havaet");
	insert(tree, "Moi", "Scank");
	if (strcmp("Lol", getValue(tree, "Bob")) != 0)
	{
		printf("Первый тест провален\n");
		result = false;
	}
	insert(tree, "Bob", "XD");
	if (strcmp("XD", getValue(tree, "Bob")) != 0)
	{
		printf("Второй тест провален\n");
		result = false;
	}
	if (!checkExist(tree, "Plamya"))
	{
		printf("Третий тест провален\n");
		result = false;
	}
	delete(tree, "Bob");
	if (checkExist(tree, "Bob"))
	{
		printf("Четвертый тест провален\n");
		result = false;
	}
	deleteTree(&tree);
	return result;
}