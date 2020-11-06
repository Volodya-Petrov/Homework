#include "List.h"
#include "Tests.h"
#include <stdio.h>

bool tests(void)
{	
	bool result = true;
	struct List* list = createList();
	append(list, 8);
	append(list, 5);
	append(list, 2);
	append(list, 1);
	if (getLength(list) != 4)
	{
		result = false;
		printf("�������� ����� 1\n");
	}
	if (indexOf(list, 2) != 2)
	{
		result = false;
		printf("�������� ������ 1\n");
	}
	deleteElement(list, 0);
	if (getLength(list) != 3)
	{
		result = false;
		printf("�������� ����� 2\n");
	}
	if (indexOf(list, 5) != 0)
	{
		result = false;
		printf("�������� ������ 2\n");
	}
	deleteList(&list);
	if (list != NULL)
	{
		result = false;
		printf("������ �������� ������\n");
	}
	if (getPos(10, 8) != 1)
	{
		result = false;
		printf("�������� ��������� ������� 1\n");
	}
	if (getPos(3, 123) != 2)
	{
		result = false;
		printf("�������� ��������� ������� 2\n");
	}
	return result;
}