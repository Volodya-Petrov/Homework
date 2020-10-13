#include "terehovJokes.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define FAIL_IN_FUNCTION -1337
#define LIMIT_INDEX 99

// структура контакта, которая имеет два поля: номер и имя
struct Person
{
	int number;
	char name[20];
};

// проверяет эквивалентность двух массивов структур до i элемента
bool structCompare(struct Person array1[], struct Person array2[], int index)
{
	for (int i = 0; i < index; i++)
	{
		if (array1[i].number != array2[i].number)
		{
			return false;
		}
		if (strcmp(array1[i].name, array2[i].name) != 0)
		{
			return false;
		}
	}
	return true;
}

// читает данные из файла и заносит их в массив
void readFromFile(const char fileName[], struct Person array[], int *indexOfArray)
{
	FILE* fileOpen = fopen(fileName, "r");
	int index = *indexOfArray;
	while ((fscanf(fileOpen, "%i %s\n", &array[index].number, &array[index].name)) != EOF)
	{	
		index++;
		if (index > 99)
		{
			break;
		}
	};
	*indexOfArray = index;
	fclose(fileOpen);
}

// функция для записи данных с массива структур в файл
void writeInFile(const char fileName[], struct Person phoneBook[], int indexInPresent)
{
	FILE* fileOpen = fopen(fileName, "w");
	for (int i = 0; i < indexInPresent; i++)
	{
		fprintf(fileOpen, "%i %s\n", phoneBook[i].number, phoneBook[i].name);
	}
	fclose(fileOpen);
}

// поиск телефонного номера по имени в массиве структур
int numberSearching(int indexInPresent, struct Person phoneBook[], char* name)
{
	for (int i = 0; i < indexInPresent; i++)
	{
		if (strcmp(phoneBook[i].name, name) == 0)
		{
			return phoneBook[i].number;
		}
	}
	return FAIL_IN_FUNCTION;
}

// поиск имени по телефонному номеру в массиве структур
int nameSearching(int indexInPresent, struct Person phoneBook[], int number)
{
	for (int i = 0; i < indexInPresent; i++)
	{
		if (phoneBook[i].number == number)
		{
			return i;
		}
	}
	return FAIL_IN_FUNCTION;
}

// добавление в массив структуру нового контакта
void contactAddition(int* indexInPresent, struct Person phoneBook[])
{
	if (*indexInPresent >= LIMIT_INDEX)
	{
		printf("Телефонный справочник полностью забит\n");
		printf("Нет места для нового контакта\n");
		return;
	}
	printf("Введите имя пользователя: ");
	scanf("%s", &phoneBook[*indexInPresent].name);
	printf("Ввведите мобильный номер %s's: ", phoneBook[*indexInPresent].name);
	scanf("%i", &phoneBook[*indexInPresent].number);
	if (nameSearching(*indexInPresent, phoneBook, phoneBook[*indexInPresent].number) != FAIL_IN_FUNCTION)
	{
		printf("Данный номер уже существует.\nОтказано в исполнении\n");
		return;
	}
	(*indexInPresent)++;
}

bool testNameSearch()
{
	struct Person persons[] = { {123, "Jon"}, {5555, "Teddy"}, {666, "Joker"} };
	int indexReal = 3;
	if (nameSearching(indexReal, persons, 5555) != 1)
	{
		printf("Тест на поиск имени провален\n");
		return false;
	}
	return true;
}

bool testNumberSearch()
{
	struct Person persons[] = { {123, "Jon"}, {5555, "Teddy"}, {666, "Joker"} };
	int indexReal = 3;
	if (numberSearching(indexReal, persons, "Jon") != 123)
	{	
		printf("Тест на поиск имени провале\n");
		return false;
	}
	return true;
}

bool testReadFromFile()
{	
	int indexReal = 0;
	struct Person personsTest[] = { {123, "Jon"}, {5555, "Teddy"}, {666, "Joker"} };
	struct Person persons[100];
	readFromFile("testReadFromFile.txt", persons, &indexReal);
	if (indexReal != 3)
	{
		printf("Тест на чтения данных с файла провален\n");
		return false;
	}
	if (!structCompare(persons, personsTest, indexReal))
	{
		printf("Тест на чтения данных с файла провален\n");
		return false;
	}
	return true;
}

int testWriteInFile()
{
	struct Person personsTest[] = { {123, "Jon"}, {5555, "Teddy"}, {666, "Joker"} };
	writeInFile("writeInFileTest.txt", personsTest, 3);
	struct Person persons[100];
	int indexReal = 0;
	readFromFile("writeInFileTest.txt", persons, &indexReal);
	if (!structCompare(personsTest, persons, indexReal))
	{
		printf("Тест на запись провален.\n");
		return false;
	}
	return true;
}

int resultOfTests()
{
	return !testWriteInFile() + !testReadFromFile() + !testNumberSearch() + !testNameSearch();
}

int main(void)
{   
	setlocale(LC_ALL, "rus");
	if (resultOfTests())
	{
		return 1;
	}
	else
	{
		printf("Тесты пройдены успешно\n");
	}
	struct Person phoneBook[100];
	int indexOfPhoneBook = 0;
	readFromFile("phoneBook.txt", phoneBook, &indexOfPhoneBook);
	printf("Программа справочник\n");
	printf("0 - выйти\n");
	printf("1 - добавить запись(имя и телефон)\n");
	printf("2 - распечатать все имеющиеся записи\n");
	printf("3 - найти телефон по имени\n");
	printf("4 - найти имя по телефону\n");
	printf("5 - сохранить текущие данные в файл\n");
	int number = 2;
	while (number != 0)
	{
		printf("Выберете номер команды: ");
		if (scanf("%i", &number) == 0)
		{
			scanf("%*s");
			number = 1488;
		}
		switch (number)
		{
		case 0:
			break;
		case 1:
			contactAddition(&indexOfPhoneBook, phoneBook);
			break;
		case 2:
			for (int i = 0; i < indexOfPhoneBook; i++)
			{
				printf("%i - %s\n", phoneBook[i].number, phoneBook[i].name);
			}
			break;
		case 3:
		{
			char name[20];
			printf("Введите имя человека, чей телефон вы хотите узнать: ");
			scanf("%s", &name);
			if (numberSearching(indexOfPhoneBook, phoneBook, name) == FAIL_IN_FUNCTION)
			{
				printf("%s не зарегистрирован в телефонной книжке\n", name);
			}
			else
			{	
				int desiredNumber = numberSearching(indexOfPhoneBook, phoneBook, name);
				printf("Номер по имени %s: %i\n", name, desiredNumber);
			}
			break;
		}
		case 4:
		{
			int desiredNumber = 0;
			printf("Введите номер: ");
			while (scanf("%i", &desiredNumber) == 0)
			{
				printf("Не корректный ввод данных, повторите попытку\n");
				printf("Введите номер: ");
				scanf("%*s");
			}
			if (nameSearching(indexOfPhoneBook, phoneBook, desiredNumber) == FAIL_IN_FUNCTION)
			{
				printf("Нет зарегистрированного контакта в телефонной книжке по такому номеру\n");
			}
			else
			{	
				int index = nameSearching(indexOfPhoneBook, phoneBook, desiredNumber);
				printf("Имя по номеру %i: %s\n", phoneBook[index].number, phoneBook[index].name);
			}
			break;
		}
		case 5:
			writeInFile("phoneBook.txt", phoneBook, indexOfPhoneBook);
			break;
		case 6:
		{
			int desiredNumber = 1;
			printf("Введите номер юморески Терехова, которую хотите услышать (1 - 11): ");
			while (scanf("%i", &desiredNumber) == 0)
			{
				printf("Не корректный ввод данных, повторите попытку\n");
				printf("Введите номер: ");
				scanf("%*s");
			}
			jokesAndIntrestingStories(desiredNumber);
			break;
		}
		default:
			printf("Введенной команды нет в списке,\nповторите попытку.\n");
			break;
		}
	}
}