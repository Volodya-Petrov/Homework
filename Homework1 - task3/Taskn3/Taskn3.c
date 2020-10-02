#include <stdio.h>
#include <locale.h>

void isBracketsBalanced(char string[])
{	
	int countOfOpenerBrackets = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '(')
		{
			countOfOpenerBrackets++;
		}
		if (string[i] == ')')
		{
			if (countOfOpenerBrackets <= 0) {
				printf("Баланс скобок нарушен");
				return;
			}
			else
			{
				countOfOpenerBrackets--;
			}
		}
		++i;
	}
	printf("Баланс скобок %s", (countOfOpenerBrackets == 0) ? "не нарушен" : "нарушен");
	return;
}

int main()
{	
	setlocale(LC_ALL, "Rus");
	printf("Ввведите строку скобок: ");
	char string[100];
	fgets(string, 100, stdin);
	isBracketsBalanced(string);
}
