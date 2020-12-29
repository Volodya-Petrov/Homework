#pragma once

// структура дерева
typedef struct Tree Tree;

// создание дерева
Tree* createTree(const char* string);

// выдает выражение в постфиксном виде
void getPostfixForm(Tree* tree, char string[]);

// считает значение дерева
float countTreeValue(Tree* tree);

// удаляет дерево
void deleteTree(Tree** tree);