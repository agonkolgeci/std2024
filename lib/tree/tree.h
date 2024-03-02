#ifndef TREE_H
#define TREE_H

#include "./../list/list.h"
#include "./../queue/queue.h"
#include "./../stack/stack.h"

typedef struct treeNode
{
    void *data;
    struct treeNode *left;
    struct treeNode *right;
} TreeNode;

typedef struct tree
{
    TreeNode *root;
} Tree;

Tree *tree_create();
TreeNode *tree_search(Tree *tree, void *data, int (*cmp)(void *, void *));
void tree_destroy(Tree *tree);
void tree_insert(Tree *tree, void *data, int (*cmp)(void *, void *));
List *tree_bfs(Tree *tree);
List *tree_dfs(Tree *tree);

#endif