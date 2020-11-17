#include "structGraph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
	int **matrix;
	int count;
}Graph;

Graph* createGraph(const char* fileName)
{
	Graph* newGraph = calloc(1, sizeof(Graph));
	if (newGraph == NULL)
	{
		return NULL;
	}
	FILE* fOpen = fopen(fileName, "r");
	int count = 0;
	fscanf(fOpen, "%i\n", &count);
	newGraph->count = count;
	newGraph->matrix = calloc(count, sizeof(int*));
	for (int i = 0; i < count; i++)
	{	
		newGraph->matrix[i] = calloc(count, sizeof(int));
		for (int j = 0; j < count; j++)
		{
			fscanf(fOpen, "%i", &(newGraph->matrix[i][j]));
		}
	}
	fclose(fOpen);
	return newGraph;
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->count; i++)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}

void printGraph(Graph* graph)
{
	for (int i = 0; i < graph->count; i++)
	{
		for (int j = 0; j < graph->count; j++)
		{
			printf("%i ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}