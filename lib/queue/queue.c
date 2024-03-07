#include "queue.h"
#include <stdlib.h>

Queue *queue_create() {
    Queue *queue = malloc(sizeof(Queue));
    if(queue == NULL) {
        return NULL;
    }

    queue->first = NULL;

    return queue;
}

void queue_destroy(Queue *queue) {
    if(queue == NULL) {
        return;
    }

    for(QueueNode *node = queue->first; node != NULL;) {
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

    QueueNode *lastNode = queue->first;
    if(lastNode != NULL) {
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    } else {
        queue->first = newNode;
    }
}

void *queue_dequeue(Queue *queue) {
    if(queue == NULL) {
        return NULL;
    }

    QueueNode *first = queue->first;
    if(first != NULL) {
        void *data = first->data;

        queue->first = first->next;
        
        free(first);

        return data;
    }

    return NULL;
}

int queue_size(Queue *queue) {
    if(queue == NULL) {
        return 0;
    }

    int i = 0;
    for(QueueNode *node = queue->first; node != NULL; node = node->next) {
        i++;
    }

    return i;
}