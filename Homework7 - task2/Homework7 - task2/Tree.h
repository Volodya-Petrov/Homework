#pragma once

// ��������� ������
typedef struct Tree Tree;

// �������� ������
Tree* createTree(const char* string);

// ������ ��������� � ����������� ����
void getPostfixForm(Tree* tree, char string[]);

// ������� �������� ������
float countTreeValue(Tree* tree);

// ������� ������
void deleteTree(Tree** tree);