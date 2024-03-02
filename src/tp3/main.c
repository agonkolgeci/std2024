#include <stdio.h>

#include "./../../lib/list/list.h"
#include "./../../lib/tree/tree.h"

/*

   This file is for debugging only.

*/

int int_cmp(void *a, void *b) {
    int x = (int) a;
    int y = (int) b;
    if(x < y){
        return -1;
    } else if(x > y){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Tree *tree = tree_create();

    tree_insert(tree, (void *) 10, int_cmp);
    tree_insert(tree, (void *) 5, int_cmp);
    tree_insert(tree, (void *) 20, int_cmp);
    tree_insert(tree, (void *) 4, int_cmp);
    tree_insert(tree, (void *) 6, int_cmp);
    tree_insert(tree, (void *) 19, int_cmp);
    tree_insert(tree, (void *) 21, int_cmp);

    List *list = tree_bfs(tree);
    for(int i = 0; i < list_size(list); i++){
        printf("%d | ", ((int *) list_get(list, i)));
    }

    List *list = tree_dfs(tree);
    for(int i = 0; i < list_size(list); i++){
        printf("%d | ", ((int *) list_get(list, i)));
    }

    tree_destroy(tree);

    return 0;
}
