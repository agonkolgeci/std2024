#include <stdio.h>

#include "acutest.h"
#include "./../lib/queue/queue.h"

void enqueue_and_size(){
    Queue* queue = queue_create();
    
    TEST_ASSERT_(queue_size(queue) == 0, "Queue size should be 0");
    queue_enqueue(queue, (void*) 1);
    TEST_ASSERT_(queue_size(queue) == 1, "Queue size should be 1");
    queue_enqueue(queue, (void*) 2);
    TEST_ASSERT_(queue_size(queue) == 2, "Queue size should be 2");
    queue_enqueue(queue, (void*) 3);
    TEST_ASSERT_(queue_size(queue) == 3, "Queue size should be 3");
}

void dequeue(){
    Queue* queue = queue_create();
    
    queue_enqueue(queue, (void*) 1);
    queue_enqueue(queue, (void*) 2);
    queue_enqueue(queue, (void*) 3);
    
    TEST_ASSERT_(queue_dequeue(queue) == (void*) 1, "Queue dequeue should return 1");
    TEST_ASSERT_(queue_size(queue) == 2, "Queue size should be 2");
    TEST_ASSERT_(queue_dequeue(queue) == (void*) 2, "Queue dequeue should return 2");
    TEST_ASSERT_(queue_size(queue) == 1, "Queue size should be 1");
    TEST_ASSERT_(queue_dequeue(queue) == (void*) 3, "Queue dequeue should return 3");
    TEST_ASSERT_(queue_size(queue) == 0, "Queue size should be 0");
    TEST_ASSERT_(queue_dequeue(queue) == NULL, "Queue dequeue should return NULL");
    TEST_ASSERT_(queue_size(queue) == 0, "Queue size should be 0");
}

void enqueue_and_size_extra(){
    Queue* queue = queue_create();
    
    char* hello = "hello";
    char* test = "test";

    TEST_ASSERT_(queue_size(queue) == 0, "Queue size should be 0");
    queue_enqueue(queue, (void*) hello);
    TEST_ASSERT_(queue_size(queue) == 1, "Queue size should be 1");
    queue_enqueue(queue, (void*) test);
    TEST_ASSERT_(queue_size(queue) == 2, "Queue size should be 2");
}

void dequeue_extra(){
    Queue* queue = queue_create();

    char* hello = "hello";
    char* test = "test";
    
    queue_enqueue(queue, (void*) hello);
    queue_enqueue(queue, (void*) test);
    
    TEST_ASSERT_(queue_size(queue) == 2, "Queue size should be 2");
    TEST_ASSERT_(queue_dequeue(queue) == (void*) hello, "Queue dequeue should return 'hello'");
    TEST_ASSERT_(queue_size(queue) == 1, "Queue size should be 2");
    TEST_ASSERT_(queue_dequeue(queue) == (void*) test, "Queue dequeue should return 'test'");
    TEST_ASSERT_(queue_size(queue) == 0, "Queue size should be 0");
    TEST_ASSERT_(queue_dequeue(queue) == NULL, "Queue dequeue should return NULL");
    TEST_ASSERT_(queue_size(queue) == 0, "Queue size should be 0");
}

TEST_LIST = {
    { "enqueue_and_size", enqueue_and_size },
    { "dequeue", dequeue },
    { "enqueue_and_size_extra", enqueue_and_size_extra },
    { "dequeue_extra", dequeue_extra },
    { NULL, NULL }
};
