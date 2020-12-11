#pragma once

#include <stdbool.h>

// структура дерева
typedef struct Tree Tree;

// выделение пам€ти под дерево
Tree* createTree(void);

// вставка ключа в дерево, функци€ делает только копии строк, не измен€€ их, оставл€€ во владение вызывающему
void insert(Tree* tree, char* key, char* value);

// удаление ключа из дерева, key остаетс€ во владении вызывающего
void delete(Tree* tree, char* key);

// удаление дерева
void deleteTree(Tree** tree);

// получение значени€ по ключу, key остаетс€ во владении вызывающего
const char* getValue(Tree* tree, char* key);

// проверка существовани€ ключа, key остаетс€ во владении вызывающего
bool checkExist(Tree* tree, char* key);