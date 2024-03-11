#include "stack.h"
#include <stdlib.h>

Stack *stack_create() {
    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL) {
        return NULL;
    }

    stack->first = NULL;

    return stack;
}

int stack_size(Stack *stack) {
    if(stack == NULL) {
        return 0;
    }

    int i = 0;
    for(StackNode *node = stack->first; node != NULL; node = node->next) {
        i++;
    }

    return i;
}

void stack_push(Stack *stack, void *data) {
    if(stack == NULL) {
        return;
    }

    StackNode *newNode = malloc(sizeof(StackNode));
    if(newNode == NULL) {
        return;
    }

    StackNode *firstNode = stack->first;

    newNode->data = data;
    newNode->next = firstNode;

    stack->first = newNode;
}

void *stack_pop(Stack *stack) {
    if(stack == NULL) {
        return NULL;
    }

    StackNode *firstNode = stack->first;
    if(firstNode != NULL) {
        stack->first = firstNode->next;

        void *data = firstNode->data;

        free(firstNode);

        return data;
    }

    return NULL;
}

void stack_destroy(Stack *stack) {
    if(stack == NULL) {
        return;
    }

    for (StackNode *node = stack->first; node != NULL;) {
        StackNode *tmp = node->next;

        free(node);

        node = tmp;
    }

    free(stack);
}