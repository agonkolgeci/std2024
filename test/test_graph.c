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

/*
This is a second test of a graph I retrieved from this video : https://www.youtube.com/watch?v=_lHSawdgXpI

By the way, it's from this video that I drew inspiration to implement the algorithm.
*/
void dijkstra2() {
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
    TEST_ASSERT_(graph_dijkstra(graph, 0, 1) == 3, "dijkstra2(graph, 0, 1) == 3 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 0, 2) == 2, "dijkstra2(graph, 0, 2) == 2 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 0, 3) == 5, "dijkstra2(graph, 0, 3) == 5 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 0, 4) == 6, "dijkstra2(graph, 0, 4) == 6 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 1, 2) == 3, "dijkstra2(graph, 1, 2) == 3 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 1, 3) == 2, "dijkstra2(graph, 1, 3) == 2 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 1, 4) == 3, "dijkstra2(graph, 1, 4) == 3 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 2, 3) == 3, "dijkstra2(graph, 2, 3) == 3 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 2, 4) == 4, "dijkstra2(graph, 2, 4) == 4 failed");
    TEST_ASSERT_(graph_dijkstra(graph, 3, 4) == INT_MAX, "dijkstra2(graph, 3, 4) == INT_MAX failed");
    graph_destroy(graph);
}

TEST_LIST = {
    { "dijkstra", dijkstra },
    { "dijsktra_2", dijkstra2 },
    { NULL, NULL }
};
