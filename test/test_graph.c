#include <stdio.h>

#include "acutest.h"
#include "./../lib/graph/graph.h"

void dijkstra(){
    Graph* graph = graph_create(5);
    graph_add_edge(graph, 0, 1, 5);
    graph_add_edge(graph, 0, 2, 20);
    graph_add_edge(graph, 0, 3, 25);
    graph_add_edge(graph, 0, 4, 50);
    graph_add_edge(graph, 1, 2, 10);
    graph_add_edge(graph, 1, 3, 30);
    graph_add_edge(graph, 2, 3, 10);
    graph_add_edge(graph, 2, 4, 20);
    graph_add_edge(graph, 3, 4, 20);
    TEST_ASSERT_(graph_dijkstra(graph, 0, 1) == 5, "dijkstra(graph, 0, 1) == 5 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 0, 2) == 15, "dijkstra(graph, 0, 2) == 15 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 0, 3) == 25, "dijkstra(graph, 0, 3) == 25 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 0, 4) == 35, "dijkstra(graph, 0, 4) == 35 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 1, 2) == 10, "dijkstra(graph, 1, 2) == 10 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 1, 3) == 20, "dijkstra(graph, 1, 3) == 20 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 1, 4) == 30, "dijkstra(graph, 1, 4) == 30 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 2, 3) == 10, "dijkstra(graph, 2, 3) == 10 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 2, 4) == 20, "dijkstra(graph, 2, 4) == 20 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 3, 4) == 20, "dijkstra(graph, 3, 4) == 20 failed");
    graph_destroy(graph);
}

TEST_LIST = {
    { "dijkstra", dijkstra },
    { NULL, NULL }
};
