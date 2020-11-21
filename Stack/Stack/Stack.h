#pragma once

#include <stdbool.h>

// ��������� �����, ����� ���� ����, � ������ ������ �� ������ �����
struct Stack;

// ������� ��� ��������� ������ �� ����
struct Stack* createStack(void);

// ������� ��� ��������� �������� ���������� �������� � �����
bool pop(struct Stack* stack, int* value);

// ���������� �������� � ����
void push(struct Stack* stack, int value);

// �������� �����
void deleteStack(struct Stack** stack);

// �������� �� ������� �����
bool isEmpty(struct Stack* stack);