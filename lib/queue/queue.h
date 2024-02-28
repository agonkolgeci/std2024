#ifndef QUEUE_H
#define QUEUE_H

typedef struct queueNode
{
    void *data;

    struct queueNode *next;
} QueueNode;

typedef struct queue
{
    QueueNode *first;
} Queue;

Queue *queue_create();
void queue_destroy(Queue *queue);
void queue_enqueue(Queue *queue, void *data);
void *queue_dequeue(Queue *queue);
int queue_size(Queue *queue);

#endif