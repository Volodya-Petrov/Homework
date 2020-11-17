#pragma once

#include <stdbool.h>

// структура дерева
typedef struct Tree Tree;

// выделение памяти под дерево
Tree* createTree();

// вставка ключа в дерево
void insert(Tree* tree, int key, char* value);

// удаление ключа из дерева
void delete(Tree* tree, int key);

// удаление дерева
void deleteTree(Tree** tree);

// получение значение по ключу
const char* getValue(Tree* tree, int key);

// проверка существование ключа
bool checkExist(Tree* tree, int key);