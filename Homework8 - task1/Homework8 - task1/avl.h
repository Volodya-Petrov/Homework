#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct Tree Tree;

// ��������� ������ ��� ������
Tree* createTree(void);

// ������� ����� � ������, ������� ������ ������ ����� �����, �� ������� ��, �������� �� �������� �����������
void insert(Tree* tree, char* key, char* value);

// �������� ����� �� ������, key �������� �� �������� �����������
void delete(Tree* tree, char* key);

// �������� ������
void deleteTree(Tree** tree);

// ��������� �������� �� �����, key �������� �� �������� �����������
const char* getValue(Tree* tree, char* key);

// �������� ������������� �����, key �������� �� �������� �����������
bool checkExist(Tree* tree, char* key);