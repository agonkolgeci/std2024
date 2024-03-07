#include <stdio.h>
#include <stdlib.h>

#include "./../../lib/graph/graph.h"

/*

   This file is for debugging only.

*/

int main() {
    Graph* graph = graph_create(5);
    graph_add_edge(graph, 0, 1, 4);
    graph_add_edge(graph, 0, 2, 2);
    graph_add_edge(graph, 1, 2, 3);
    graph_add_edge(graph, 1, 3, 2);
    graph_add_edge(graph, 1, 4, 3);
    graph_add_edge(graph, 2, 1, 1);
    graph_add_edge(graph, 2, 3, 4);
    graph_add_edge(graph, 2, 4, 5);
    graph_add_edge(graph, 4, 3, 1);
    
    float distance = graph_dijkstra(graph, 0, 4);

    return 0;
}
