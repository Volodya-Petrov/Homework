#pragma once

#include <stdbool.h>

//структура стека, имеет одно поле, а именно ссылку на голову стека
struct Stack;

//функция для выделения памяти на стек
struct Stack* createStack(void);

//Функция для получения значения последнего элемента в стеке
int pop(struct Stack* stack);

// добавление элемента в стек
void push(struct Stack* stack, int value);

// удаление стека
void deleteStack(struct Stack** stack);

// проверка на пустоту стека
bool isEmpty(struct Stack* stack);
