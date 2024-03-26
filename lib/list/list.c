#include "list.h"
#include <stdlib.h>

List *list_create() {
    List *list = malloc(sizeof(List));
    if(list == NULL) {
        return NULL;
    }

    list->first = NULL;

    return list;
}

int list_size(List *list) {
    if(list == NULL) {
        return 0;
    }

    int size = 0;
    for(ListNode *node = list->first; node != NULL; node = node->next) {
        size++;
    }

    return size;
}

void *list_get(List *list, int index) {
    if(list == NULL) {
        return NULL;
    }

    for(ListNode *node = list->first; node != NULL; node = node->next) {
        if(node->index == index) {
            return node->data;
        }
    }

    return NULL;
}

int list_contains(List *list, void *data) {
    if(list == NULL) {
        return 0;
    }

    for(ListNode *node = list->first; node != NULL; node = node->next) {
        if(node->data == data) {
            return 1;
        }
    }

    return 0;
}

void list_append(List *list, void *data) {
    if(list == NULL) {
        return;
    }

    ListNode *newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) {
        return;
    }

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
    if(list == NULL || (index < 0 || index >= size)) {
        return;
    }

    ListNode *prevNode = NULL;
    ListNode *nextNode = list->first;
    for(int i = 0; i < index; i++) {
        prevNode = nextNode;
        nextNode = nextNode->next;
    }

    ListNode *newNode = malloc(sizeof(ListNode));
    if(newNode == NULL) {
        return;
    }

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
    if(list == NULL) {
        return -1;
    }

    for(ListNode *node = list->first; node != NULL; node = node->next) {
        if(node->data == data) {
            return node->index;
        }
    }

    return -1;
}

void list_delete(List *list, int index) {
    int size = list_size(list);
    if(list == NULL || (index < 0 || index >= size)) {
        return;
    }

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
    if(list == NULL) {
        return;
    }

    for (ListNode *node = list->first; node != NULL;) {
        ListNode *tmp = node->next;

        free(node);

        node = tmp;
    }

    free(list);
}