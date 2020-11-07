#pragma once

#include <stdbool.h>

struct Dictionary;

struct Dictionary* createDictionary(void);

void addElement(struct Dictionary* dict, int key, char value[]);

char* getValue(struct Dictionary* dict, int key);

bool keyExists(struct Dictionary* dict, int key);

void deleteElement(struct Dictionary* dict, int key);

void deleteDict(struct Dictionary** dict);