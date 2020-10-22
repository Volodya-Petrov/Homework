#include "operationsWithBinaryArrays.h"
#include <stdio.h>
#include <math.h>

void sumOfBinaryNums(int firstNumber[], int secondNumber[], int resultNumber[])
{
	int helperInSum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		resultNumber[i] = (firstNumber[i] + secondNumber[i] + helperInSum) % 2;
		helperInSum = (firstNumber[i] + secondNumber[i] + helperInSum) / 2;
	}
}

void fromIntToBinary(int array[], int number)
{
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = abs(number % 2);
		number = number >> 1;
	}
}

int fromBinaryToInt(int array[])
{	
	int multiplier = 1;
	int number = 0;
	for (int i = 0; i < SIZE; i++)
	{
		number += array[i] * multiplier;
		multiplier *= 2;
	}
	return number;
}

void showBinaryNumber(int array[])
{
	for (int i = SIZE - 1; i >= 0; i--)
	{
		printf("%i", array[i]);
	}
	printf("\n");
}