#include <stdio.h>
#include <locale.h>

int fibonacciRecursive(int number)
{
	if (number <= 0)
	{
		printf("Ввод некорректных данных\n");
		return -1337;
	}
	if (number <= 2)
	{
		return 1;
	}
	else
	{
		return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
	}
}

int fibonacciIterative(int number)
{
	if (number <= 0)
	{
		printf("Ввод некорректных данных\n");
		return -1337;
	}
	int lastNumber = 1;
	int penultimateNumber = 1;
	int desiredNumber = 1;
	for (int i = 2; i < number; i++)
	{
		desiredNumber = lastNumber + penultimateNumber;
		penultimateNumber = lastNumber;
		lastNumber = desiredNumber;
	}
	return desiredNumber;
}

int test()
{	
	const int number1 = 1;
	const int number2 = 7;
	const int number3 = 31;
	const int number4 = -5;
	const int result1 = 1;
	const int result2 = 13;
	const int result3 = 1346269;
	const int result4 = -1337;
	int checkForMistakes = 0;
	if ((fibonacciIterative(number1) == fibonacciRecursive(number1)) && (fibonacciIterative(number1) == result1))
	{
		printf("Первый тест пройден успешно\n");
	}
	else
	{
		printf("Первый тест провален");
		checkForMistakes += 1;
	}
	if ((fibonacciIterative(number2) == fibonacciRecursive(number2)) && (fibonacciIterative(number2) == result2))
	{
		printf("Второй тест пройден успешно\n");
	}
	else
	{
		printf("Второй тест провален");
		checkForMistakes += 1;
	}
	if ((fibonacciIterative(number3) == fibonacciRecursive(number3)) && (fibonacciIterative(number3) == result3))
	{
		printf("Третий тест пройден успешно\n");
	}
	else
	{
		printf("Третий тест провален");
		checkForMistakes += 1;
	}
	if ((fibonacciIterative(number4) == fibonacciRecursive(number4)) && (fibonacciIterative(number4) == result4))
	{
		printf("Четвертый тест пройден успешно\n");
	}
	else
	{
		printf("Четвертый тест провален");
		checkForMistakes += 1;
	}
	return checkForMistakes;
}

int main(void)
{	
	setlocale(LC_ALL, "Rus");
	if(test())
	{
		return 1;
	}
	int number = 0;
	printf("Ввведите номер числа фибоначчи: ");
	scanf("%i", &number);
	int fibonacciNumber = fibonacciRecursive(number);
	printf("число фибоначчи по заданному номеру = %i\n", fibonacciNumber);
	fibonacciNumber = fibonacciIterative(number);
	printf("число фибоначчи по заданному номеру = %i", fibonacciNumber);
}
// c 37 номера числа фибоначчи уже заметно что итеративный алгоритм работает быстрее, на 40 числе рекурсивный думает секунд 10 - 15, 
//когда итеративный мнгновенно выдает ответ
