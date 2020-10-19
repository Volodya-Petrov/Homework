#include "operationsWithBinaryArrays.h"
#include "tests.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (testResult())
	{
		return 1;
	}
	else
	{
		printf("Тесты пройдены успешно!\n");
	}
	int firstBinaryNumber[SIZE] = { 0 };
	int secondBinaryNumber[SIZE] = { 0 };
	int resultBinaryNumber[SIZE] = { 0 };
	int firstNumber = 0;
	int secondNumber = 0;
	printf("Введите первое число: ");
	scanf("%i", &firstNumber);
	printf("Двоичное представление первого числа:\n");
	fromIntToBinary(firstBinaryNumber, firstNumber);
	showBinaryNumber(firstBinaryNumber);
	printf("Введите второе число: ");
	scanf("%i", &secondNumber);
	printf("Двоичное представление второго числа:\n");
	fromIntToBinary(secondBinaryNumber, secondNumber);
	showBinaryNumber(secondBinaryNumber);
	printf("Двоичное представление суммы двух введенных чисел:\n");
	sumOfBinaryNums(firstBinaryNumber, secondBinaryNumber, resultBinaryNumber);
	showBinaryNumber(resultBinaryNumber);
	printf("Десятичное представление этой суммы = %i", fromBinaryToInt(resultBinaryNumber));
}