#include "list.h"
#include <stdlib.h>

List *list_create() {
    List *list = malloc(sizeof(List));

    list->first = NULL;

    return list;
}

int list_size(List *list) {
    int i = 0;
    for(ListNode *node = list->first; node != NULL; node = node->next) {
        i++;
    }

    return i;
}

void *list_get(List *list, int index) {
    for(ListNode *node = list->first; node != NULL; node = node->next) {
        if(node->index == index) {
            return node->data;
        }
    }

    return NULL;
}

int list_contains(List *list, void *data) {
    for(ListNode *node = list->first; node != NULL; node = node->next) {
        if(node->data == data) {
            return 1;
        }
    }

    return 0;
}

void list_append(List *list, void *data) {
    ListNode *newNode = malloc(sizeof(ListNode));

    newNode->data = data;
    newNode->next = NULL;

    ListNode *lastNode = list->first;
    if(lastNode != NULL) {
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        newNode->index = lastNode->index + 1;
        lastNode->next = newNode;
    } else {
        newNode->index = 0;
        list->first = newNode;
    }
}

void list_insert(List *list, int index, void *data) {
    int size = list_size(list);
    index = index < list_size(list) ? index : (size - 1);

    ListNode *prevNode = NULL;
    ListNode *nextNode = list->first;
    for(int i = 0; i < index; i++) {
        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    ListNode *newNode = malloc(sizeof(ListNode));

    newNode->index = index;
    newNode->data = data;
    newNode->next = nextNode;
    
    if(prevNode != NULL) {
        prevNode->next = newNode;
    } else {
        list->first = newNode;
    }

    for(ListNode *node = nextNode; node != NULL; node = node->next) {
        node->index++;
    }
}

int list_indexOf(List *list, void *data) {
    for(ListNode *node = list->first; node != NULL; node = node->next) {
        if(node->data == data) {
            return node->index;
        }
    }

    return 0;
}

void list_delete(List *list, int index) {
    int size = list_size(list);
    index = index < list_size(list) ? index : (size - 1);
    
    ListNode *prevNode = NULL;
    ListNode *targetNode = list->first;
    for(int i = 0; i < index; i++) {
        prevNode = targetNode;
        targetNode = targetNode->next;
    }

    ListNode *nextNode = targetNode->next;

    if(prevNode != NULL) {
        prevNode->next = nextNode;
    } else {
        list->first = nextNode;
    }

    for(ListNode *node = nextNode; node != NULL; node = node->next) {
        node->index--;
    }

    free(targetNode);
}

void list_destroy(List *list) {
    for (ListNode *node = list->first; node != NULL;) {
        ListNode *tmp = node->next;

        free(node);

        node = tmp;
    }

    free(list);
}