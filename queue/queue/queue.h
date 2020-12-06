#pragma once

#include <stdbool.h>

// структура очереди
typedef struct Queue Queue;
// проверка на пустоту в очереди
bool empty(Queue* queue);

// добавление элемента в очередь
void enqueue(Queue* queue, int value);

// берет элемент из очереди
int dequeue(Queue* queue);

// удаление очереди
void deleteQueue(Queue** queue);

// создание очереди
Queue* initQueue(void);