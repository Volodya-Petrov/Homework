#pragma once

#include "List.h"

// выдает список, в котором храняться индексы начала и конца комментария
List* getComments(const char* string);

// выводит комментарии
void printComments(List* comments, const char* string);