#include "queue.h"
#include <stdlib.h>

Queue *queue_create() {
    Queue *queue = malloc(sizeof(Queue));
    if(queue == NULL) {
        return NULL;
    }

    queue->front = NULL;

    return queue;
}

void queue_destroy(Queue *queue) {
    if(queue == NULL) {
        return;
    }

    for(QueueNode *node = queue->front; node != NULL;) {
        QueueNode *tmp = node->next;

        free(node);

        node = tmp;
    }

    free(queue);
}

void queue_enqueue(Queue *queue, void *data) {
    if(queue == NULL) {
        return;
    }

    QueueNode *newNode = malloc(sizeof(QueueNode));
    if(newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(queue->front != NULL) {
        queue->rear->next = newNode;
        queue->rear = newNode;
    } else {
        queue->front = queue->rear = newNode;
    }
}

void *queue_dequeue(Queue *queue) {
    if(queue == NULL) {
        return NULL;
    }

    QueueNode *frontNode = queue->front;
    if(frontNode != NULL) {
        queue->front = frontNode->next;
        
        void *data = frontNode->data;
        
        free(frontNode);

        return data;
    }

    return NULL;
}

int queue_size(Queue *queue) {
    if(queue == NULL) {
        return 0;
    }

    int size = 0;
    for(QueueNode *node = queue->front; node != NULL; node = node->next) {
        size++;
    }

    return size;
}