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

TEST_LIST = {
    { "enqueue_and_size", enqueue_and_size },
    { "dequeue", dequeue },
    { NULL, NULL }
};
