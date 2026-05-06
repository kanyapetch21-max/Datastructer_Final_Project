#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HashNode *table[TABLE_SIZE];

static int hashFunction(const char *word) {
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        sum = (sum * 31 + (unsigned char)word[i]) % TABLE_SIZE;
    }
    return sum;
}
