#pragma once

#include <stdbool.h>

// структура словаря
struct Dictionary;

// создание словаря
struct Dictionary* createDictionary(void);

// функция добавления элемента в словарь
void addElement(struct Dictionary* dict, int key, char value[]);

// выдает значение по ключу
char* getValue(struct Dictionary* dict, int key);

// проверяет существование ключа в словаре
bool keyExists(struct Dictionary* dict, int key);

// удаляет элемент из словаря
void deleteElement(struct Dictionary* dict, int key);

// удаляет словарь
void deleteDict(struct Dictionary** dict);