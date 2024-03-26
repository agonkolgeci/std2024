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

void append_and_get_extra(){
    List* list = list_create();
    list_append(list, (void*)"Hello");
    list_append(list, (void*)"Darkness");
    list_append(list, (void*)"My old friend");
    TEST_ASSERT_((char*)list_get(list, 0) == "Hello", "get(list, 0) == 'Hello' failed");
    TEST_ASSERT_((char*)list_get(list, 1) == "Darkness", "get(list, 1) == 'Darkness' failed");
    TEST_ASSERT_((char*)list_get(list, 2) == "My old friend", "get(list, 2) == 'My old friend' failed");
    TEST_ASSERT_(list_get(list, 3) == NULL, "get(list, 3) == NULL failed");
}

void size_extra(){
    List* list = list_create();
    TEST_ASSERT_(list_size(list) == 0, "size(list) == 0 failed");
    int adds = 10;
    int removes = 5;
    for(int i = 0; i < adds; i++){
        list_append(list, (void*)i);
    }

    for(int i = 0; i < removes; i++){
        list_delete(list, 0);
    }

    TEST_ASSERT_(list_size(list) == adds - removes, "size(list) == adds - removes failed");
}

void insert_extra(){
    List* list = list_create();
    list_append(list, (void*)"be");
    list_append(list, (void*)"with you");
    list_insert(list, 0, (void*)"May the force");
    TEST_ASSERT_((char*)list_get(list, 0) == "May the force", "get(list, 0) == 'May the force' failed");
    TEST_ASSERT_((char*)list_get(list, 1) == "be", "get(list, 1) == 'be' failed");
    TEST_ASSERT_((char*)list_get(list, 2) == "with you", "get(list, 2) == 'with you' failed");
}

void indexOf_extra(){
    List* list = list_create();
    
    for(int i = 0; i<100; i++){
        list_append(list, (void*)i);
    }

    for(int i = 0; i<100; i++){
        TEST_ASSERT_(list_indexOf(list, (void*)i) == i, "indexOf(list, i) == i failed");
    }

    TEST_ASSERT_(list_indexOf(list, (void*)100) == -1, "indexOf(list, 100) == -1 failed");
}

void delete_extra(void){
    List* list = list_create();
    list_append(list, (void*)1);
    list_append(list, (void*)2);
    list_append(list, (void*)3);
    list_delete(list, 0);
    list_delete(list, 1);
    TEST_ASSERT_(list_size(list) == 1, "size(list) == 1 failed");
    TEST_ASSERT_((int)list_get(list, 0) == 2, "get(list, 0) == 2 failed");
    TEST_ASSERT_(list_get(list, 1) == NULL, "get(list, 1) == NULL failed");
}

void contains_extra(){
    List* list = list_create();
    char* hello = "Hello";
    char* test = "Test";
    list_append(list, (void*)hello);
    list_append(list, (void*)test);
    TEST_ASSERT_(list_contains(list, (void*)hello) == 1, "List contains 'Hello' failed");
    TEST_ASSERT_(list_contains(list, (void*)test) == 1, "List contains 'Test' failed");
    list_delete(list, 0);
    TEST_ASSERT_(list_contains(list, (void*)hello) == 0, "List contains 'Hello' failed");
    list_delete(list, 0);
    TEST_ASSERT_(list_contains(list, (void*)test) == 0, "List contains 'Test' failed");
}

TEST_LIST = {
    { "append_and_get", append_and_get },
    { "size", size },
    { "insert", insert },
    { "indexOf", indexOf },
    { "delete", delete },
    { "contains", contains },
    { "append_and_get_extra", append_and_get_extra },
    { "size_extra", size_extra },
    { "insert_extra", insert_extra },
    { "indexOf_extra", indexOf_extra },
    { "delete_extra", delete_extra },
    { "contains_extra", contains_extra },
    { NULL, NULL }
};
