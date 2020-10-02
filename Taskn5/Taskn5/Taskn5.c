#include <stdio.h>
#include <locale.h>
#define SIZE_OF_STRING 100

int main(void)
{	
	setlocale(LC_ALL, "Rus");
	int counterSubstrings = 0;
	char string[SIZE_OF_STRING];
	char substring[SIZE_OF_STRING];
	printf("Введите строку: ");
	gets(string, SIZE_OF_STRING);
	printf("Введите подстроку: ");
	gets(substring, SIZE_OF_STRING);
	int lenOfSubstring = strlen(substring);
	int lenOfString = strlen(string);
	for (int i = 0; i <= lenOfString - lenOfSubstring; i++)
	{
		if (string[i] == substring[0])
		{	
			int matchСounter = 0;
			for (int j = 0; j < lenOfSubstring; j++)
			{
				if (substring[j] == string[j + i]) {
					matchСounter++;
				}
				else {
					break;
				}
			}
			if (matchСounter == lenOfSubstring) {
				counterSubstrings++;
			}
		}
	}
	printf("Количество вхождений подстроки в строку: ");
	printf("%d", counterSubstrings);
}