#include <stdio.h>
#include <locale.h>

float helperForQuickPow(float number, int numbersDegree)
{
	if (numbersDegree == 0)
	{
		return 1;
	}
	if (numbersDegree == 1)
	{
		return number;
	}

	float functionValue = helperForQuickPow(number, numbersDegree / 2);
	if (numbersDegree % 2 == 1)
	{
		return number * functionValue * functionValue;
	}
	return functionValue * functionValue;
}

float quickPow(float number, int numbersDegree)
{
	if (numbersDegree < 0)
	{
		return 1 / helperForQuickPow(number, abs(numbersDegree));
	}
	return helperForQuickPow(number, numbersDegree);
}

float pow(float number, int numbersDegree)
{
	float result = 1;
	for (int i = 0; i < abs(numbersDegree); i++)
	{
		result *= number;
	}
	if (numbersDegree < 0)
	{
		return 1 / result;
	}
	return result;
}

int tests(void)
{	
	int checkForMistakes = 0;
	if ((quickPow(5, 0) == pow(5, 0)) && (pow(5, 0) == 1))
	{
		printf("Первый тест пройден успешно\n");
	}
	else
	{
		printf("Первый тест провален\n");
		checkForMistakes += 1;
	}
	if ((quickPow(2, 9) == pow(2, 9)) && (pow(2, 9) == 512))
	{
		printf("Второй тест пройден успешно\n");
	}
	else
	{
		printf("Второй тест провален\n");
		checkForMistakes++;
	}
	if ((quickPow(-2, 7) == pow(-2, 7)) && (pow(-2, 7) == -128))
	{
		printf("Третий тест пройден успешно\n");
	}
	else
	{
		printf("Третий тест провален\n");
		checkForMistakes++;
	}
	if ((quickPow(5, -2) == pow(5, -2)) && (pow(5, -2) == 0.04f))
	{
		printf("Четвертый тест пройден успешно\n");
	}
	else
	{
		checkForMistakes++;
	}
	return checkForMistakes;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	if (tests())
	{
		return 1;
	}
	double a = 0.04;
	float b = 0.04;
	printf("%f, %f", b, a);
	float number = 0;
	int numberDegrees = 0;
	printf("Введите число: ");
	scanf("%f", &number);
	printf("Введите степень числа: ");
	scanf("%i", &numberDegrees);
	printf("%f в степени %i = %f\n", number, numberDegrees, pow(number, numberDegrees));
	printf("%f в степени %i = %f", number, numberDegrees, quickPow(number, numberDegrees));
}