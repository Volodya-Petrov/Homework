#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct person
{
	int number;
	char name[20];
};

void writeInFile(char fileName[], struct person phoneBook[], int indexInPresent)
{
	FILE* fileOpen = fopen(fileName, "w");
	for (int i = 0; i < indexInPresent; i++)
	{
		fprintf(fileOpen, "%i %s\n", phoneBook[i].number, phoneBook[i].name);
	}
	fclose(fileOpen);
}

int numberSearching(int* indexInPresent, struct person phoneBook[], char* name)
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

int nameSearching(int* indexInPresent, struct person phoneBook[], int number)
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

void contactAddition(int *indexInPresent, struct person phoneBook[])
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
	(*indexInPresent)++;
}

int main(void)
{   
	setlocale(LC_ALL, "rus");
	struct person phonebook[100];
	FILE* fileOpen;
	if ((fileOpen = fopen("phoneBook.txt", "r")) == NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	int indexOfPhoneBook = 0;
	while ((fscanf(fileOpen, "%i %s\n", &phonebook[indexOfPhoneBook].number, &phonebook[indexOfPhoneBook].name)) != EOF)
	{
		if (indexOfPhoneBook < 99)
		{
			indexOfPhoneBook++;
		}
	};
	fclose(fileOpen);
	printf("Программа справочник\n");
	printf("0 - выйти\n");
	printf("1 - добавить запись(имя и телефон)\n");
	printf("2 - распечатать все имеющиеся записи\n");
	printf("3 - найти телефон по имени\n");
	printf("4 - найти имя по телефону\n");
	printf("5 - сохранить текущие данные в файл\n");
	int number = 1;
	printf("%i", indexOfPhoneBook);
	while (number != 0)
	{
		printf("Выберете номер команды: ");
		scanf("%i", &number);
		switch (number)
		{
		case 0:
			break;

		case 1:
			contactAddition(&indexOfPhoneBook, phonebook);
			break;

		case 2:
			for (int i = 0; i < indexOfPhoneBook; i++)
			{
				printf("%i - %s\n", phonebook[i].number, phonebook[i].name);
			}
			break;

		case 3:
		{
			char name[20];
			printf("Введите имя человека, чей телефон вы хотите узнать: ");
			scanf("%s", &name);
			if (numberSearching(&indexOfPhoneBook, phonebook, &name) == -1337)
			{
				printf("%s не зарегистрирован в телефонной книжке\n", name);
			}
			else
			{	
				int desiredNumber = numberSearching(&indexOfPhoneBook, phonebook, &name);
				printf("Номер по имени %s: %i\n", name, desiredNumber);
			}
			break;
		}

		case 4:
		{
			int desiredNumber = 0;
			printf("Введите номер: ");
			scanf("%i", &desiredNumber);

			if (nameSearching(&indexOfPhoneBook, phonebook, desiredNumber) == -1337)
			{
				printf("Нет зарегистрированного в телефонной книжке по такому номеру\n");
			}
			else
			{	
				int index = nameSearching(&indexOfPhoneBook, phonebook, desiredNumber);
				printf("Имя по номеру %i: %s\n", phonebook[index].number, phonebook[index].name);
			}
			break;
		}
		case 5:
			writeInFile("phoneBook.txt", phonebook, indexOfPhoneBook);
			break;

		default:
			number = 0;
			break;
		}
	}
}

