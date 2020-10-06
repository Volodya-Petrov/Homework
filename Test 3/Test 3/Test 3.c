#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "rus");
	int countOfSymbols[256];
	for (int i = 0; i < 256; i++)
	{
		countOfSymbols[i] = 0;
	}
	char symbols[256];
	for (int i = 0; i < 256; i++)
	{
		symbols[i] = "";
	}
	char charInReal = "";
	FILE* fileOpen = fopen("test.txt", "r");
	while ((charInReal = fgetc(fileOpen)) != EOF)
	{
		int checkForFound = 0;
		for (int i = 0; i < 256; i++)
		{
			if (charInReal == symbols[i])
			{
				checkForFound = 1;
				countOfSymbols[i]++;
			}
		}
		if (checkForFound == 0)
		{
			for (int i = 0; i < 256; i++)
			{
				if (countOfSymbols[i] == 0)
				{
					countOfSymbols[i]++;
					symbols[i] = charInReal;
					break;
				}
			}
		}
	}
	fclose(fileOpen);
	int max = 5;
	for (int i = 0; i < 256; i++)
	{
		if (countOfSymbols[i] > countOfSymbols[max])
		{
			max = i;
		}
	}
	if (countOfSymbols[max] == 0)
	{
		printf("Файл пуст");
	}
	else
	{
		printf("Самый часто встречаемый символ в файле : %c ", symbols[max]);
	}
}