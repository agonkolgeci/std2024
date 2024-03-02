#include <stdlib.h>

#include "tree.h"
#include "./../list/list.h"
#include "./../queue/queue.h"
#include "./../stack/stack.h"

Tree *tree_create() {
    Tree *tree = malloc(sizeof(Tree));
    if(tree == NULL) {
        return NULL;
    }

    tree->root = NULL;

    return tree;
}

TreeNode *tree_search(Tree *tree, void *data, int (*cmp)(void *, void *)) {
    TreeNode *current = tree->root;

    while(current != NULL) {
        int cmp_result = cmp(current->data, data);

        switch (cmp_result) {
            case 0: {
                return current;
            }

            case -1: {
                current = current->left;

                break;
            }

            case 1: {
                current = current->right;

                break;
            }
        }

    }

    return NULL;
}

void tree_destroy(Tree *tree) {
    Stack *stack = stack_create();
    TreeNode *current = tree->root;

    while(current != NULL) {
        TreeNode *tmp = current;

        if(current->left != NULL) {
            stack_push(stack, tmp);
            
            current = current->left;
            tmp->left = NULL;
        } else if(current->right != NULL) {
            stack_push(stack, tmp);

            current = current->right;
            tmp->right = NULL;
        } else {
            free(tmp);

            current = stack_pop(stack);
        }
    }

    tree->root = NULL;

    stack_destroy(stack);
    free(tree);
}

void tree_insert(Tree *tree, void *data, int (*cmp)(void *, void *)) {
    TreeNode *newNode = malloc(sizeof(TreeNode));
    if(newNode == NULL) {
        return;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(tree->root == NULL) {
        tree->root = newNode;

        return;
    }

    TreeNode *current = tree->root;
    TreeNode *parent = NULL;

    while(current != NULL) {
        switch (cmp(current->data, data)) {
            case 0: {
                free(newNode);

                return;
            }
            
            case -1: {
                parent = current;
                current = current->left;

                break;
            }

            case 1: {
                parent = current;
                current = current->right;

                break;
            }
        }
    }

    if(cmp(parent->data, data) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

List *tree_bfs(Tree *tree) {
    List *list = list_create();
    Queue *queue = queue_create();

    queue_enqueue(queue, tree->root);

    while(queue_size(queue) != 0) {
        TreeNode *current = queue_dequeue(queue);

        list_append(list, current->data);

        if(current->right != NULL) {
            queue_enqueue(queue, current->right);
        }

        if(current->left != NULL) {
            queue_enqueue(queue, current->left);
        }
    }

    queue_destroy(queue);

    return list;
}

List *tree_dfs(Tree *tree) {
    List *list = list_create();
    Stack *stack = stack_create();

    stack_push(stack, tree->root);

    while(stack_size(stack) != 0) {
        TreeNode *current = stack_pop(stack);

        list_append(list, current->data);

        if(current->left != NULL) {
            stack_push(stack, current->left);
        }

        if(current->right != NULL) {
            stack_push(stack, current->right);
        }
    }

    stack_destroy(stack);

    return list;
}