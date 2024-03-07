#include <stdlib.h>

#include "graph.h"
#include "./../list/list.h"

#define FLT_MAX 3.40282e+38F

Graph *graph_create(int size) {
    Graph *graph = malloc(sizeof(Graph));
    if(graph == NULL) {
        return NULL;
    }

    graph->vertices = size;

    List **adjacencies = calloc(size, sizeof(List*));
    if(adjacencies == NULL) {
        free(graph);

        return NULL;
    }

    graph->adjacencies = adjacencies;

    return graph;
}

void graph_destroy(Graph *graph) {
    if(graph == NULL) {
        return;
    }

    for(int i = 0; i < graph->vertices; i++) {
        List *adjacency = graph->adjacencies[i];
        if(adjacency == NULL) {
            continue;
        }

        list_destroy(adjacency); 
    }

    free(graph->adjacencies);
    free(graph);
}

void graph_add_edge(Graph *graph, int sourceNode, int targetNode, float weight) {
    int vertices = graph->vertices;
    if(graph == NULL || (sourceNode < 0 || sourceNode >= vertices) || (targetNode < 0 || targetNode >= vertices)) {
        return;
    }

    List *adjacency = graph->adjacencies[sourceNode];
    if(adjacency == NULL) {
        adjacency = list_create();
        if(adjacency == NULL) {
            return;
        }

        graph->adjacencies[sourceNode] = adjacency;
    }

    Edge *edge = malloc(sizeof(Edge));
    if(edge == NULL) {
        return;
    }

    edge->node = targetNode;
    edge->weight = weight;

    list_append(adjacency, edge);
}

// Implementation inspiration: https://www.youtube.com/watch?v=_lHSawdgXpI
float graph_dijkstra(Graph *graph, int sourceNode, int targetNode) {
    int vertices = graph->vertices;
    if(graph == NULL || (sourceNode < 0 || sourceNode >= vertices) || (targetNode < 0 || targetNode >= vertices)) {
        return -1;
    }

    float distances[vertices];
    int visited[vertices];
    
    if(distances == NULL || visited == NULL) {
        return -1;
    }

    for (int i = 0; i < vertices; i++) {
        distances[i] = FLT_MAX;
        visited[i] = 0;
    }

    distances[sourceNode] = 0;
    visited[sourceNode] = 1;

    List *currentAdjacency = graph->adjacencies[sourceNode];
    
    Edge *minEdge = malloc(sizeof(Edge));
    if(minEdge == NULL) {
        return -1;
    }

    float currentDistance = 0;
    for(int step = 0; step < vertices; step++) {
        if(currentAdjacency == NULL) {
            break;
        }

        for(ListNode *nearbyNode = currentAdjacency->first; nearbyNode != NULL; nearbyNode = nearbyNode->next) {
            Edge *nearbyEdge = (Edge*) nearbyNode->data;

            float totalDistance = currentDistance + nearbyEdge->weight;
            if(visited[nearbyEdge->node] == 0 && totalDistance < distances[nearbyEdge->node]) {
                distances[nearbyEdge->node] = totalDistance;
            }
        }
        
        minEdge->node = -1;
        minEdge->weight = FLT_MAX;

        for(int i = 0; i < vertices; i++) {
            if(visited[i] == 0 && distances[i] < minEdge->weight) {
                minEdge->node = i;
                minEdge->weight = distances[i];
            }
        }

        visited[minEdge->node] = 1;

        if(minEdge->node == targetNode) {
            break;
        }

        currentDistance = minEdge->weight;
        currentAdjacency = graph->adjacencies[minEdge->node];
    }

    free(minEdge);
    
    return distances[targetNode];
}