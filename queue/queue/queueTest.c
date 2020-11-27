#include "queue.h"
#include "queueTest.h"
#include <stdlib.h>
#include <stdio.h>

bool queueTest(void)
{
	bool result = true;
	Queue* queue = initQueue();
	enqueue(queue, 5);
	if (empty(queue))
	{
		result = false;
		printf("Тест 1 провален\n");
	}
	if (dequeue(queue) != 5)
	{
		printf("Тест 2 провален\n");
	}
	if (!empty(queue))
	{
		result = false;
		printf("Тест 3 провален\n");
	}
	enqueue(queue, 6);
	enqueue(queue, 7);
	if (dequeue(queue) != 6)
	{
		result = false;
		printf("Тест 4 провален\n");
	}
	deleteQueue(&queue);
	if (queue != NULL)
	{
		result = false;
	}
	return result;
}