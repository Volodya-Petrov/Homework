#pragma once

// структура графа
typedef struct Graph Graph;

// создание графа с "сount" вершинами
Graph* makeGraph(int count);

// устанавливает расстояние между двумя вершинами
void fillGraph(Graph* graph, int i, int j, int len);

// удаляет граф
void deleteGraph(Graph** graph);

// выдает расстояние между двумя вершинами
int getDistance(Graph* graph, int i, int j);

// выдает кол-во вершин в графе
int getVertices(Graph* graph);