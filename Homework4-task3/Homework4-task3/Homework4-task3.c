#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "terehovjokes.h"

struct person // структура котакта, которая имеет два поля: номер и имя
{
	int number;
	char name[20];
};

int structCompare(struct person array1[], struct person array2[], int index) // проверяет эквивалентность двух массивов структур до i элемента
{
	for (int i = 0; i < index; i++)
	{
		if (array1[i].number != array2[i].number)
		{
			return 1;
		}
		if (strcmp(&array1[i].name, &array2[i].name) != 0)
		{
			return 1;
		}
	}
	return 0;
}

void readFromFile(char fileName[] , struct person array[], int *indexOfArray) // функция для считывания данных с файла в массив структур
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

void writeInFile(char fileName[], struct person phoneBook[], int indexInPresent) // функция для записи данных с массива структур в файл
{
	FILE* fileOpen = fopen(fileName, "w");
	for (int i = 0; i < indexInPresent; i++)
	{
		fprintf(fileOpen, "%i %s\n", phoneBook[i].number, phoneBook[i].name);
	}
	fclose(fileOpen);
}

int numberSearching(int* indexInPresent, struct person phoneBook[], char* name) // поиск телефонного номера по имени в массиве структур
{
	for (int i = 0; i < *indexInPresent; i++)
	{
		if (strcmp(&phoneBook[i].name, name) == 0)
		{
			return phoneBook[i].number;
		}
	}
	return -1337;
}

int nameSearching(int* indexInPresent, struct person phoneBook[], int number) // поиск имени по телефонному номеру в массиве структур
{
	int index = -1337;
	for (int i = 0; i < *indexInPresent; i++)
	{
		if (phoneBook[i].number == number)
		{
			return i;
		}
	}
	return index;
}

void contactAddition(int* indexInPresent, struct person phoneBook[]) // добавление в массив стурктур нового контакта
{
	if (*indexInPresent >= 99)
	{
		printf("Телефонный справочник полностью забит\n");
		printf("Нет места для нового контакта\n");
		return;
	}
	printf("Введите имя пользователя: ");
	scanf("%s", &phoneBook[*indexInPresent].name);
	printf("Ввведите мобильный номер %s's: ", phoneBook[*indexInPresent].name);
	scanf("%i", &phoneBook[*indexInPresent].number);
	if (nameSearching(indexInPresent, phoneBook, phoneBook[*indexInPresent].number) != -1337)
	{
		printf("Данный номер уже существует.\nОтказано в исполнении\n");
		return;
	}
	(*indexInPresent)++;
}

int testNameSearch()
{
	struct person persons[] = { 123, "Jon", 5555, "Teddy", 666, "Joker" };
	int indexReal = 3;
	if (nameSearching(&indexReal, persons, 5555) != 1)
	{
		printf("Тест на поиск имени провален\n");
		return 1;
	}
	return 0;
}

int testNumberSearch()
{
	struct person persons[] = { 123, "Jon", 5555, "Teddy", 666, "Joker" };
	int indexReal = 3;
	if (numberSearching(&indexReal, persons, "Jon") != 123)
	{	
		printf("Тест на поиск имени провале\n");
		return 1;
	}
	return 0;
}

int testReadFromFile()
{	
	int indexReal = 0;
	struct person personsTest[] = { 123, "Jon", 5555, "Teddy", 666, "Joker" };
	struct person persons[100];
	readFromFile("testReadFromFile.txt", persons, &indexReal);
	if (indexReal != 3)
	{
		printf("Тест на чтения данных с файла провален\n");
		return 1;
	}
	if (structCompare(persons, personsTest, indexReal))
	{
		printf("Тест на чтения данных с файла провален\n");
		return 1;
	}
	return 0;
}

int testWriteInFile()
{
	struct person personsTest[] = { 123, "Jon", 5555, "Teddy", 666, "Joker" };
	writeInFile("writeInFileTest.txt", personsTest, 3);
	struct person persons[100];
	int indexReal = 0;
	readFromFile("writeInFileTest.txt", persons, &indexReal);
	if (structCompare(personsTest, persons, indexReal))
	{
		printf("Тест на запись провален.\n");
		return 1;
	}
	return 0;
}

int resultOfTests()
{
	int checkForMistakes = 0;
	checkForMistakes = testWriteInFile() + testReadFromFile() + testNumberSearch() + testNameSearch();
	return checkForMistakes;
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
	struct person phoneBook[100];
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
			if (numberSearching(&indexOfPhoneBook, phoneBook, &name) == -1337)
			{
				printf("%s не зарегистрирован в телефонной книжке\n", name);
			}
			else
			{	
				int desiredNumber = numberSearching(&indexOfPhoneBook, phoneBook, &name);
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
			if (nameSearching(&indexOfPhoneBook, phoneBook, desiredNumber) == -1337)
			{
				printf("Нет зарегистрированного контакта в телефонной книжке по такому номеру\n");
			}
			else
			{	
				int index = nameSearching(&indexOfPhoneBook, phoneBook, desiredNumber);
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
			printf("Введите номер юморски Терехова, которую хотите услышать (1 - 11): ");
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

