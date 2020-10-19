#include "operationsWithBinaryArrays.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool compareArraysForTests(int firstArray[], int secondArray[])
{
	for (int i = 0; i < SIZE; i++)
	{
		if (firstArray[i] != secondArray[i])
		{
			return false;
		}
	}
	return true;
}

bool testForIntToBinary(void)
{
	int testArrayForPositiveSix[SIZE] = { 0, 1, 1 };
	int arrayForSix[SIZE] = { 0 };
	fromIntToBinary(arrayForSix, 6);
	if (!compareArraysForTests(testArrayForPositiveSix, arrayForSix))
	{
		printf("Тест на перевод из десятиричной в двоичную провален. 1\n");
		return false;
	}
	int testArrayForNegative[SIZE] = {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int arrayForNegativeNums[SIZE] = { 0 };
	fromIntToBinary(arrayForNegativeNums, -13);
	if (!compareArraysForTests(testArrayForNegative, arrayForNegativeNums))
	{
		printf("Тест на перевод из десятиричной в двоичную провален. 2\n");
		return false;
	}
	return true;
}

bool testBinaryToInt(void)
{
	int binaryArray[SIZE] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (fromBinaryToInt(binaryArray) != 17)
	{
		printf("Тест на перевод из двоичной в десятичную провален.1\n");
		return false;
	}
	int binaryForNegative[SIZE] = { 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	if (fromBinaryToInt(binaryForNegative) != -13)
	{
		printf("Тест на перевод из двоичной в десятичную провален.2\n");
		return false;
	}
}

bool testForSumInBinary()
{
	int rightSum[SIZE] = { 0 };
	fromIntToBinary(rightSum, 25);
	int firstNumber[SIZE] = { 0 };
	int secondNumber[SIZE] = { 0 };
	fromIntToBinary(firstNumber, 60);
	fromIntToBinary(secondNumber, -35);
	int sum[SIZE] = { 0 };
	sumOfBinaryNums(firstNumber, secondNumber, sum);
	if (!compareArraysForTests(sum, rightSum))
	{
		printf("Тест на сумму провелен.\n");
		return false;
	}
	return true;
}

bool testResult(void)
{
	return !testBinaryToInt() + !testForIntToBinary() + !testForSumInBinary();
}

