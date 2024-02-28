#include <stdio.h>

#include "../../lib/list/list.h"
#include "../../lib/queue/queue.h"
#include "../../lib/stack/stack.h"

void list_fn()
{
    List *list = list_create();

    list_append(list, (void *) 1); //0
    list_append(list, (void *) 2); //1
    list_append(list, (void *) 3); //2
    list_append(list, (void *) 4); //3
    list_append(list, (void *) 5); //4 <---
    list_append(list, (void *) 6); //5
    list_append(list, (void *) 7); //6
    list_append(list, (void *) 8); //7
    list_append(list, (void *) 9); //8

    printf("Taille avant l'insertion à l'index 4: %d", list_size(list));

    list_insert(list, 4, (void *) 0);

    printf("Taille après l'insertion: %d", list_size(list));

    list_destroy(list);
}

void queue_fn()
{
    Queue *queue = queue_create();

    queue_enqueue(queue, (void *) 1);
    queue_enqueue(queue, (void *) 2);
    queue_enqueue(queue, (void *) 3);
    queue_enqueue(queue, (void *) 4);
    queue_enqueue(queue, (void *) 5);
    queue_enqueue(queue, (void *) 6);
    queue_enqueue(queue, (void *) 7);
    queue_enqueue(queue, (void *) 8);
    queue_enqueue(queue, (void *) 9);

    void *data = queue_dequeue(queue);
    if(data == (void *) 1) {
        printf("Le dequeue fonctionne !");
    } else {
        printf(":(");
    }

    queue_destroy(queue);
}

void stack_fn()
{
    Stack *stack = stack_create();

    stack_push(stack, (void *) 1);
    stack_push(stack, (void *) 2);
    stack_push(stack, (void *) 3);
    stack_push(stack, (void *) 4);
    stack_push(stack, (void *) 5);
    stack_push(stack, (void *) 6);
    stack_push(stack, (void *) 7);
    stack_push(stack, (void *) 8);
    stack_push(stack, (void *) 9);

    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);

    printf("Taille de la pile (doit être égale à 0): %d", stack_size(stack));

    stack_destroy(stack);
}

int main()
{
    // List
    list_fn();

    // Queue
    queue_fn();

    // Stack
    stack_fn();

    return 0;
}
