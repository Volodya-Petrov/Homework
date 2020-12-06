#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
	int** matrix;
	int vertices;
} Graph;

Graph* makeGraph(int count)
{
	Graph* newGraph = calloc(1, sizeof(Graph));
	if (newGraph == NULL)
	{
		return NULL;
	}
	newGraph->matrix = calloc(count, sizeof(int*));
	for (int i = 0; i < count; i++)
	{
		newGraph->matrix[i] = calloc(count, sizeof(int));
	}
	newGraph->vertices = count;
	return newGraph;
}

void fillGraph(Graph* graph, int i, int j, int len)
{
	graph->matrix[i][j] = len;
	graph->matrix[j][i] = len;
}

void printGraph(const Graph* graph)
{
	const int size = graph->vertices;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%i ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}

int getDistance(Graph* graph, int i, int j)
{
	if (i < 0 || i >= graph->vertices)
	{
		return -1;
	}
	if (j < 0 || j >= graph->vertices)
	{
		return -1;
	}
	return graph->matrix[i][j];
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->vertices; i++)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}

int getVertices(Graph* graph)
{
	return graph->vertices;
}