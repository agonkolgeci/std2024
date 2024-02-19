#include <stdio.h>

#include "acutest.h"
#include "./../lib/list/list.h"

void append_and_get(){
    List* list = list_create();
    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);
    TEST_ASSERT_((int)list_get(list, 0) == 1, "get(list, 0) == 1 failed");
    TEST_ASSERT_((int)list_get(list, 1) == 2, "get(list, 1) == 2 failed");
    TEST_ASSERT_((int)list_get(list, 2) == 3, "get(list, 2) == 3 failed");
}

void size(){
    List* list = list_create();
    TEST_ASSERT_(list_size(list) == 0, "size(list) == 0 failed");
    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);
    TEST_ASSERT_(list_size(list) == 3, "size(list) == 3 failed");
}

void insert(){
    List* list = list_create();
    list_append(list, (void*)1);
    list_append(list, (void*)3);
    list_insert(list, 1, (void*)2);
    TEST_ASSERT_((int)list_get(list, 0) == 1, "get(list, 0) == 1 failed");
    TEST_ASSERT_((int)list_get(list, 1) == 2, "get(list, 1) == 2 failed");
    TEST_ASSERT_((int)list_get(list, 2) == 3, "get(list, 2) == 3 failed");
}

void indexOf(){
    List* list = list_create();
    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);
    TEST_ASSERT_(list_indexOf(list, (void*)1) == 0, "indexOf(list, 1) == 0 failed");
    TEST_ASSERT_(list_indexOf(list, (void*)2) == 1, "indexOf(list, 2) == 1 failed");
    TEST_ASSERT_(list_indexOf(list, (void*)3) == 2, "indexOf(list, 3) == 2 failed");
}

void delete(void){
    List* list = list_create();
    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);
    list_delete(list, 0);
    TEST_ASSERT_(list_size(list) == 2, "size(list) == 2 failed");
    TEST_ASSERT_((int)list_get(list, 0) == 2, "get(list, 0) == 2 failed");
    TEST_ASSERT_((int)list_get(list, 1) == 3, "get(list, 1) == 3 failed");
}

void contains(){
    List* list = list_create();
    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);
    TEST_ASSERT_(list_contains(list, (void*)1) == 1, "List contains 1 failed");
    TEST_ASSERT_(list_contains(list, (void*)2) == 1, "List contains 2 failed");
    TEST_ASSERT_(list_contains(list, (void*)3) == 1, "List contains 3 failed");
    list_delete(list, 0);
    TEST_ASSERT_(list_contains(list, (void*)1) == 0, "List contains 1 failed");
    list_delete(list, 1);
    TEST_ASSERT_(list_contains(list, (void*)2) == 1, "List contains 2 failed");
    TEST_ASSERT_(list_contains(list, (void*)3) == 0, "List contains 3 failed");
    list_delete(list, 0);
    TEST_ASSERT_(list_contains(list, (void*)2) == 0, "List contains 2 failed");
}

TEST_LIST = {
    { "append_and_get", append_and_get },
    { "size", size },
    { "insert", insert },
    { "indexOf", indexOf },
    { "delete", delete },
    { "contains", contains },
    { NULL, NULL }
};
