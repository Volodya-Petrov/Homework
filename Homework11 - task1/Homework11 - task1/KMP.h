#pragma once

// создает префиксный массив
void prefixFunction(char* substring, int prefixArray[]);

// ищет образец в строке и выдает его позицию
int findSubstring(char* string, char* substring, int prefixArray[]);