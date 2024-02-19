#include <stdio.h>

#include "acutest.h"
#include "./../lib/list/list.h"
#include "./../lib/tree/tree.h"


int int_cmp(void *a, void *b){
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

void insert_search(){
    Tree *tree = tree_create();
    tree_insert(tree, (void *) 5, int_cmp);
    tree_insert(tree, (void *) 3, int_cmp);
    tree_insert(tree, (void *) 7, int_cmp);
    tree_insert(tree, (void *) 2, int_cmp);
    tree_insert(tree, (void *) 4, int_cmp);
    tree_insert(tree, (void *) 6, int_cmp);
    tree_insert(tree, (void *) 8, int_cmp);
    TreeNode *node = tree_search(tree, (void *) 3, int_cmp);
    TEST_ASSERT_(node != NULL, "Node is NULL");
    TEST_ASSERT_((int) node->data == 3, "Node data is not 3");
    node = tree_search(tree, (void *) 5, int_cmp);
    TEST_ASSERT_(node != NULL, "Node is NULL");
    TEST_ASSERT_((int) node->data == 5, "Node data is not 5");
    node = tree_search(tree, (void *) 8, int_cmp);
    TEST_ASSERT_(node != NULL, "Node is NULL");
    TEST_ASSERT_((int) node->data == 8, "Node data is not 8");
    node = tree_search(tree, (void *) 1, int_cmp);
    TEST_ASSERT_(node == NULL, "Node is not NULL");
    tree_destroy(tree);
}

void bfs(){
    Tree *tree = tree_create();
    tree_insert(tree, (void *) 5, int_cmp);
    tree_insert(tree, (void *) 3, int_cmp);
    tree_insert(tree, (void *) 7, int_cmp);
    tree_insert(tree, (void *) 2, int_cmp);
    tree_insert(tree, (void *) 4, int_cmp);
    tree_insert(tree, (void *) 6, int_cmp);
    tree_insert(tree, (void *) 8, int_cmp);
    List* list = tree_bfs(tree);
    TEST_ASSERT_(list != NULL, "List is NULL");
    TEST_ASSERT_(list_size(list) == 7, "List size is not 7");

    int expected[7] = {5, 3, 7, 2, 4, 6, 8};
    for(int i = 0; i < list_size(list); i++){
        TEST_ASSERT_((int) list_get(list, i) == expected[i], "List data is not expected");
    }
}

void dfs(){
    Tree *tree = tree_create();
    tree_insert(tree, (void *) 5, int_cmp);
    tree_insert(tree, (void *) 3, int_cmp);
    tree_insert(tree, (void *) 7, int_cmp);
    tree_insert(tree, (void *) 2, int_cmp);
    tree_insert(tree, (void *) 4, int_cmp);
    tree_insert(tree, (void *) 6, int_cmp);
    tree_insert(tree, (void *) 8, int_cmp);
    List* list = tree_dfs(tree);
    TEST_ASSERT_(list != NULL, "List is NULL");
    TEST_ASSERT_(list_size(list) == 7, "List size is not 7");

    int expected[7] = {5, 3, 2, 4, 7, 6, 8};
    for(int i = 0; i < list_size(list); i++){
        TEST_ASSERT_((int) list_get(list, i) == expected[i], "List data is not expected");
    }
}

TEST_LIST = {
    { "insert_search", insert_search },
    { "bfs", bfs},
    { "dfs", dfs},
    { NULL, NULL }
};
