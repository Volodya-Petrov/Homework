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
		printf("���� 1 ��������\n");
	}
	if (dequeue(queue) != 5)
	{
		printf("���� 2 ��������\n");
	}
	if (!empty(queue))
	{
		result = false;
		printf("���� 3 ��������\n");
	}
	enqueue(queue, 6);
	enqueue(queue, 7);
	if (dequeue(queue) != 6)
	{
		result = false;
		printf("���� 4 ��������\n");
	}
	deleteQueue(&queue);
	if (queue != NULL)
	{
		result = false;
	}
	return result;
}