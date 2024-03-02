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
    int i = 0;
    for(StackNode *node = stack->first; node != NULL; node = node->next) {
        i++;
    }

    return i;
}

void stack_push(Stack *stack, void *data) {
    StackNode *newNode = malloc(sizeof(StackNode));
    if(newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    StackNode *lastNode = stack->first;
    if(lastNode != NULL) {
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    } else {
        stack->first = newNode;
    }
}

void *stack_pop(Stack *stack) {
    StackNode *lastNode = stack->first;
    if(lastNode != NULL) {
        StackNode *prevNode = NULL;
        while(lastNode->next != NULL) {
            prevNode = lastNode;
            lastNode = lastNode->next;
        }

        void *data = lastNode->data;

        if(prevNode != NULL) {
            prevNode->next = NULL;
        } else {
            stack->first = NULL;
        }
        
        free(lastNode);

        return data;
    }

    return NULL;
}

void stack_destroy(Stack *stack) {
    for (StackNode *node = stack->first; node != NULL;) {
        StackNode *tmp = node->next;

        free(node);

        node = tmp;
    }

    free(stack);
}