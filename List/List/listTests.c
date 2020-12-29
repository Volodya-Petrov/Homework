#include "listTests.h"
#include "../../List/List/List.h"
#include <stdio.h>
#include <string.h>

bool testList(void)
{	
	bool result = true;
	List* list = createList();
	append(list, "Bob");
	append(list, "Jack");
	append(list, "Steve");
	append(list, "Bob");
	if (indexOf(list, "Gordon") != -1)
	{	
		result = false;
		printf("������ ���� ��� ������ ��������\n");
	}
	if (length(list) != 3)
	{
		result = false;
		printf("������ ���� ��� ������ ��������\n");
	}
	if (strcmp(getValue(list, 0), "Bob") != 0)
	{
		result = false;
		printf("������ ���� ��� ������ ��������\n");
	}
	if (getCount(list, 0) != 2)
	{
		result = false;
		printf("��������� ���� ��� ������ ��������\n");
	}
	deleteElement(list, 0);
	if (length(list) != 2)
	{
		result = false;
		printf("����� ���� ��� ������ ��������\n");
	}
	deleteList(&list);
	return result;
}
