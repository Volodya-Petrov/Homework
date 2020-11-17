#include "structGraph.h"
#include <stdio.h>

int main(void)
{
	Graph* graph = createGraph("graph.txt");
	printGraph(graph);
	deleteGraph(&graph);
}