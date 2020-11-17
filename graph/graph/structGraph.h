#pragma once

typedef struct Graph Graph;

Graph* createGraph(const char* fileName);

void printGraph(Graph* graph);

void deleteGraph(Graph** graph);