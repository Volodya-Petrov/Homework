#pragma once

typedef struct Graph Graph;

Graph* makeGraph(int count);

void fillGraph(Graph* graph, int i, int j, int len);

void deleteGraph(Graph** graph);

int getDistance(Graph* graph, int i, int j);

int getVertices(Graph* graph);