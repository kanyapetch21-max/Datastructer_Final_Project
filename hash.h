#ifndef HASH_H
#define HASH_H

#include "deck.h"

#define TABLE_SIZE 101

typedef struct HashNode {
    Card *card;
    struct HashNode *next;
} HashNode;

void initTable(void);
void insertHash(Card *c);
void deleteHash(const char *word);
Card* searchHash(const char *word);

#endif
