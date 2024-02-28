#ifndef STACK_H
#define STACK_H

typedef struct stackNode
{
    void *data;

    struct stackNode *next;
} StackNode;

typedef struct stack
{
    StackNode *first;
} Stack;

Stack *stack_create();
int stack_size(Stack *stack);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
void stack_destroy(Stack *stack);

#endif