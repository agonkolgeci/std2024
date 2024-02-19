#ifndef HASH_H
#define HASH_H

#include "./../list/list.h"

// Specific hash function
unsigned long int hashFunction(void *key);

// Hash table
typedef struct hashTable
{
    // TODO: Implement
} HashTable;

HashTable *hashCreate(int size, unsigned long int (*hashFunction)(void *));
void hash_destroy(HashTable *table);
void hash_insert(HashTable *table, void *key, void* data);
void hash_delete(HashTable *table, void *key);
void *hash_get(HashTable *table, void *key);
int hash_size(HashTable *table);



// Hash table with external chaining
typedef struct hashTableChain
{
    // TODO: Implement
} HashTableChain;

HashTableChain *hashChainCreate(int size, unsigned long int (*hashFunction)(void *));
void hash_chain_destroy(HashTableChain *table);
void hash_chain_insert(HashTableChain *table, void *key, void *data);
void hash_chain_delete(HashTableChain *table, void *key);
void *hash_chain_get(HashTableChain *table, void *key);
int hash_chain_size(HashTableChain *table);


#endif