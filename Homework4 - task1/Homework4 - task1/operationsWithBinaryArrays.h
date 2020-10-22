#pragma once

// Кол-во разрядов в двоичном числе
#define SIZE 32

// находит сумму двух двоичных чисел, результат записывает в массив
void sumOfBinaryNums(int firstNumber[], int secondNumber[], int resultNumber[]);

//переводит интежер в двоичное число
void fromIntToBinary(int array[], int number);

// переводит двоичное число в десятичное
int fromBinaryToInt(int array[]);

// выводит булевый массив/двоичное число
void showBinaryNumber(int array[]);