#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct person
{
	int number;
	char name[20];
};



void contactAddition(int *indexInPresent, struct person* phoneBook)
{
	if (*indexInPresent >= 99)
	{
		printf("Телефонный справочник полностью забит\n");
		printf("Нет места для нового контакта\n");
		return;
	}
	printf("Введите имя пользователя: ");
	scanf("%s", phoneBook[*indexInPresent].name);
	printf("Ввведите мобильный номер %s's: ", *phoneBook[*indexInPresent].name);
	scanf("%i", phoneBook[*indexInPresent].number);
	*indexInPresent++;
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
	while (number != 0)
	{
		printf("Выберете номер команды: ");
		scanf("%i", &number);
		switch (number)
		{
		case 0:
			break;
		case 1:
			contactAddition(&indexOfPhoneBook, &phonebook);
			break;
		case 2:
			for (int i = 0; i < indexOfPhoneBook; i++)
			{
				printf("%i - %s\n", phonebook[i].number, phonebook[i].name);
			}
			break;
		default:
			number = 0;
			break;
		}
	}
}

