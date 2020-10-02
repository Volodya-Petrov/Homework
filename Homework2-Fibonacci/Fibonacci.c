#include <stdio.h>
#include <locale.h>

void test()
{	
	const int number1 = 1;
	const int number2 = 7;
	const int number3 = 31;
	const int result1 = 1;
	const int result2 = 13;
	const int result3 = 1346269;
	if ((fibonacciIterative(number1) == fibonacciRecursive(number1)) && (fibonacciIterative(number1) == result1))
	{
		printf("Первый тест пройден успешно\n");
	}
	else
	{
		printf("Первый тест провален");
	}
	if ((fibonacciIterative(number2) == fibonacciRecursive(number2)) && (fibonacciIterative(number2) == result2))
	{
		printf("Второй тест пройден успешно\n");
	}
	else
	{
		printf("Второй тест провален");
	}
	if ((fibonacciIterative(number3) == fibonacciRecursive(number3)) && (fibonacciIterative(number3) == result3))
	{
		printf("Третий тест пройден успешно\n");
	}
	else
	{
		printf("Третий тест провален");
	}
}

int fibonacciRecursive(int number)
{
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

int main(void)
{	
	setlocale(LC_ALL, "Rus");
	test();
	int number = 0;
	int fibonacciNumber = 0;
	printf("Ввведите номер числа фибоначчи: ");
	scanf("%i", &number);
	fibonacciNumber = fibonacciRecursive(number);
	//fibonacciNumber = fibonacciIterative(number);
	printf("число фибоначии по заданному номеру = %i", fibonacciNumber);
}
// c 37 номера числа фибоначчи уже заметно что итеративный алгоритм работает быстрее, на 40 числе рекурсивный думает секунд 10 - 15, 
//когда итеративный мнгновенно выдает ответ
