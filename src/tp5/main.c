#include <stdio.h>

#include "./../../lib/hash/hash.h"


/*

   This file is for debugging only.

*/

int main() {
    // alphabet hash function

    printf("Hash value for 'chat' : %lu (NEED TO BE == 352407)", hashFunction((void *) "chat"));
    printf("Hash value for 'g' : %lu (NEED TO BE == 352407)", hashFunction((void *) "g"));

    return 0;
}
