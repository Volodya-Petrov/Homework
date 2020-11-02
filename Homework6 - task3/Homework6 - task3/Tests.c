#include "List.h"
#include "Tests.h"
#include "ListSort.h"
#include "fillingList.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

bool testAppend(void)
{	
	setlocale(LC_ALL, "rus");
	bool result = true;
	struct List* newList = createList();
	append(newList, "abc", "cde");
	append(newList, "ddd", "fff");
	char testName[20] = "\0";
	char testNumber[20] = "\0";
	if (getLength(newList) != 2)
	{
		printf("Тест на добавление элемента провален, неверная длина\n");
		result = false;
	}
	getValue(newList, 1, 0, testName);
	getValue(newList, 1, 1, testNumber);
	if (strcmp(testName, "ddd") || strcmp(testNumber, "fff"))
	{
		printf("Проблема с добавлением или с получением элемента\n");
		result = false;
	}
	deleteList(&newList);
	return result;
}

bool testDelete(void)
{	
	bool result = true;
	struct List* newList = createList();
	append(newList, "abc", "cde");
	append(newList, "dead", "feq");
	char testName[20] = "\0";
	char testNumber[20] = "\0";
	deleteElement(newList, 0);
	if (getLength(newList) != 1)
	{
		printf("Тест на удаление провален, неверная длина\n");
		result = false;
	}
	getValue(newList, 0, 0, testName);
	getValue(newList, 0, 1, testNumber);
	if (strcmp(testName, "dead") || strcmp(testNumber, "feq"))
	{
		printf("Неверные значение элемента, тест на удаление провален\n");
		result = false;
	}
	deleteList(&newList);
	return result;
}

bool testChangeValue(void)
{
	bool result = true;
	struct List* newList = createList();
	append(newList, "abc", "cde");
	append(newList, "dead", "feq");
	char testName[20] = "\0";
	char testNumber[20] = "\0";
	changeValue(newList, 1, 0, "fffa");
	changeValue(newList, 1, 1, "ssa");
	getValue(newList, 1, 0, testName);
	getValue(newList, 1, 1, testNumber);
	if (strcmp(testName, "fffa") || strcmp(testNumber, "ssa"))
	{
		printf("Неверные значение элемента, тест на изменение значений провален\n");
		result = false;
	}
	deleteList(&newList);
	return result;
}

bool testDeleteList(void)
{
	struct List* newList = createList();
	append(newList, "abc", "cde");
	append(newList, "dead", "feq");
	deleteList(&newList);
	return newList == NULL;
}

bool testCopy(void)
{	
	bool result = true;
	struct List* newList = createList();
	append(newList, "abc", "cde");
	append(newList, "dead", "feq");
	append(newList, "test", "xd");
	struct List* testList = copy(newList, 1, 2);
	char testName[20] = "\0";
	char testNumber[20] = "\0";
	if (getLength(testList) != 2)
	{
		printf("Тест на копирование провален, неверная длина списка\n");
		result = false;
	}
	getValue(testList, 0, 0, testName);
	getValue(testList, 0, 1, testNumber);
	if (strcmp(testName, "dead") || strcmp(testNumber, "feq"))
	{
		printf("Тест на копирование провален, неверное значение элемента\n");
		result = false;
	}
	getValue(testList, 1, 0, testName);
	getValue(testList, 1, 1, testNumber);
	if (strcmp(testName, "test") || strcmp(testNumber, "xd"))
	{
		printf("Тест на копирование провален, неверное значение элемента\n");
		result = false;
	}
	deleteList(&newList);
	deleteList(&testList);
	return result;
}

bool testReadFromFile(void)
{
	bool result = true;
	struct List* testList = createList();
	readFromFile(testList, "test.txt");
	char testName[20] = "\0";
	char testNumber[20] = "\0";
	if (getLength(testList) != 2)
	{
		printf("Тест чтение с файла провален, неверная длина списка\n");
		result = false;
	}
	getValue(testList, 0, 0, testName);
	getValue(testList, 0, 1, testNumber);
	if (strcmp(testName, "dead") || strcmp(testNumber, "feq"))
	{
		printf("Тест на чтение с файла провален, неверное значение элемента\n");
		result = false;
	}
	getValue(testList, 1, 0, testName);
	getValue(testList, 1, 1, testNumber);
	if (strcmp(testName, "test") || strcmp(testNumber, "xd"))
	{
		printf("Тест на чтение с файла провален, неверное значение элемента\n");
		result = false;
	}
	deleteList(&testList);
	return result;
}

bool testSort(void)
{
	bool result = true;
	struct List* testList = createList();
	append(testList, "Barak", "21444");
	append(testList, "Frank", "1337");
	append(testList, "Abu", "1235");
	mergeSortName(testList, 0, 2);
	char testName[20] = "\0";
	char testNumber[20] = "\0";
	getValue(testList, 0, 0, testName);
	getValue(testList, 0, 1, testNumber);
	if (strcmp(testName, "Abu") || strcmp(testNumber, "1235"))
	{
		printf("Тест провален, неверное значение\n");
		result = false;
	}
	getValue(testList, 1, 0, testName);
	getValue(testList, 1, 1, testNumber);
	if (strcmp(testName, "Barak") || strcmp(testNumber, "21444"))
	{
		printf("Тест провален, неверное значение\n");
		result = false;
	}

	getValue(testList, 2, 0, testName);
	getValue(testList, 2, 1, testNumber);
	if (strcmp(testName, "Frank") || strcmp(testNumber, "1337"))
	{
		printf("Тест провален, неверное значение\n");
		result = false;
	}
	deleteList(&testList);
	return result;
}

bool testsResult(void)
{
	return !testAppend() + !testDelete + !testCopy + !testChangeValue + !testDeleteList + !testSort + !testReadFromFile;
}