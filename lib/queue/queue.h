#ifndef QUEUE_H
#define QUEUE_H

typedef struct queueNode
{
    // TODO: Implement
} QueueNode;

typedef struct queue
{
    // TODO: Implement
} Queue;

Queue *queue_create();
void queue_destroy(Queue *queue);
void queue_enqueue(Queue *queue, void *data);
void *queue_dequeue(Queue *queue);
int queue_size(Queue *queue);

#endif