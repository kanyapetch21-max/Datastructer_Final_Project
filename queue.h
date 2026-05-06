#ifndef QUEUE_H
#define QUEUE_H

#include "deck.h"

typedef struct Node {
    Card *card;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQ(Queue *q);
int emptyQ(Queue *q);
void enqueue(Queue *q, Card *c);
Node* dequeue(Queue *q);
void freeQueue(Queue *q);

#endif
