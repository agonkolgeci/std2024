#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "./../list/list.h"
#include "hash.h"

#define ALPHABET_SIZE 26

// Specific hash function
// Implementation reference : https://www3.cs.stonybrook.edu/~skiena/214/lectures/lect21/lect21.html
unsigned long int hashFunction(void *key) {
    const char *string = (const char *) key;

    unsigned long int hash = 0;

    for (int i = 0; i < strlen(string); i++) {
        char letter = string[i];

        /*
        On détermine la position de chaque lettre dans l'alphabet :
        Pour cela, nous faisons la différence entre le code ASCII de la lettre ainsi que celle de la première lettre de l'alphabet et on ajoute 1.
            
        Exemple: 
            'g' = 103 | 'a' = 97
            'g' - 'a' = 6
            6 + 1 = 7
        */
        int alphabetPosition = letter - 'a' + 1;

        hash += alphabetPosition * pow(ALPHABET_SIZE, i);
    }
    
    return hash;
}

// Hash table
HashTable *hashCreate(int size, unsigned long int (*hashFunction)(void *)) {
    HashTable *table = malloc(sizeof(HashTable));
    if(table == NULL) {
        return NULL;
    }

    void **buckets = calloc(size, sizeof(void *));
    if(buckets == NULL) {
        free(table);

        return NULL;
    }

    table->hashFunction = hashFunction;

    table->size = size;
    table->buckets = buckets;

    return table;
}

void hash_destroy(HashTable *table) {
    if(table == NULL) {
        return;
    }

    free(table->buckets);
    free(table);
}

void hash_insert(HashTable *table, void *key, void* data) {
    if(table == NULL) {
        return;
    }

    unsigned long int hash = table->hashFunction(key);
    int index = hash % table->size;

    table->buckets[index] = data;
}

void hash_delete(HashTable *table, void *key) {
    if(table == NULL) {
        return;
    }

    unsigned long int hash = table->hashFunction(key);
    int index = hash % table->size;
    
    table->buckets[index] = NULL;
}

void *hash_get(HashTable *table, void *key) {
    if(table == NULL) {
        return NULL;
    }

    unsigned long int hash = table->hashFunction(key);
    int index = hash % table->size;

    return table->buckets[index];
}


int hash_size(HashTable *table) {
    if(table == NULL) {
        return 0;
    }

    int size = 0;
    for(int i = 0; i < table->size; i++) {
        if(table->buckets[i] != NULL) {
            size++;
        }
    }

    return size;
}

// Hash table with external chaining
HashTableChain *hashChainCreate(int size, unsigned long int (*hashFunction)(void *)) {
    HashTableChain *table = malloc(sizeof(HashTableChain));
    if(table == NULL) {
        return NULL;
    }

    List **buckets = calloc(size, sizeof(List *));
    if(buckets == NULL) {
        free(table);

        return NULL;
    }

    table->hashFunction = hashFunction;

    table->size = size;
    table->buckets = buckets;

    return table;
}

void hash_chain_destroy(HashTableChain *table) {
    if(table == NULL) {
        return;
    }

    for(int i = 0; i < table->size; i++) {
        List *chain = table->buckets[i];
        if(chain == NULL) {
            continue;
        }

        list_destroy(chain);
    }

    free(table->buckets);
    free(table);
}

void hash_chain_insert(HashTableChain *table, void *key, void *data) {
    if(table == NULL) {
        return;
    }

    unsigned long int hash = table->hashFunction(key);
    int index = hash % table->size;

    List *bucketChain = table->buckets[index];
    if(bucketChain == NULL) {
        bucketChain = list_create();
        if(bucketChain == NULL) {
            return;
        }

        table->buckets[index] = bucketChain;
    }

    HashTableBucketNode *bucketNode = malloc(sizeof(HashTableBucketNode));
    if(bucketNode == NULL) {
        return;
    }

    bucketNode->key = key;
    bucketNode->data = data;

    list_append(bucketChain, bucketNode);
}

void hash_chain_delete(HashTableChain *table, void *key) {
    if(table == NULL) {
        return;
    }

    unsigned long int hash = table->hashFunction(key);
    int index = hash % table->size;

    List *bucketChain = table->buckets[index];
    if(bucketChain == NULL) {
        return;
    }

    for(ListNode *currentNode = bucketChain->first; currentNode != NULL; currentNode = currentNode->next) {
        HashTableBucketNode *bucketNode = (HashTableBucketNode *) currentNode->data;
        if(bucketNode == NULL) {
            continue;
        }
        
        if(bucketNode->key == key) {
            list_delete(bucketChain, currentNode->index);
        }
    }
}

void *hash_chain_get(HashTableChain *table, void *key) {
    if(table == NULL) {
        return NULL;
    }

    unsigned long int hash = table->hashFunction(key);
    int index = hash % table->size;

    List *bucketChain = table->buckets[index];
    if(bucketChain == NULL) {
        return NULL;
    }

    for(ListNode *currentNode = bucketChain->first; currentNode != NULL; currentNode = currentNode->next) {
        HashTableBucketNode *bucketNode = (HashTableBucketNode *) currentNode->data;
        if(bucketNode == NULL) {
            continue;
        }
        
        if(bucketNode->key == key) {
            return bucketNode->data;
        }
    }

    
    return NULL;
}

int hash_chain_size(HashTableChain *table) {
    if(table == NULL) {
        return 0;
    }

    int size = 0;
    for(int i = 0; i < table->size; i++) {
        List *bucketChain = table->buckets[i];
        if(bucketChain != NULL) {
            size += list_size(bucketChain);
        }
    }

    return size;
}