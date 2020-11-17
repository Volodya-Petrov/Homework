#pragma once

#include <stdbool.h>

// ��������� ������
typedef struct Tree Tree;

// ��������� ������ ��� ������
Tree* createTree();

// ������� ����� � ������
void insert(Tree* tree, int key, char* value);

// �������� ����� �� ������
void delete(Tree* tree, int key);

// �������� ������
void deleteTree(Tree** tree);

// ��������� �������� �� �����
const char* getValue(Tree* tree, int key);

// �������� ������������� �����
bool checkExist(Tree* tree, int key);