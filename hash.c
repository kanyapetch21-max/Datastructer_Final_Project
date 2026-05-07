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

void initTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

void insertHash(Card *c) {
    if (!c) return;

    int idx = hashFunction(c->word);

    HashNode *n = (HashNode*)malloc(sizeof(HashNode));
    if (!n) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n->card = c;
    n->next = table[idx];
    table[idx] = n;
}

void deleteHash(const char *word) {
    int idx = hashFunction(word);
    HashNode *cur = table[idx];
    HashNode *prev = NULL;

    while (cur) {
        if (strcmp(cur->card->word, word) == 0) {
            if (!prev) {
                table[idx] = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
