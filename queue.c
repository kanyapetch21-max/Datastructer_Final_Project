#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQ(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int emptyQ(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Card *c) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    n->card = c;
    n->next = NULL;

    if (!q->rear) {
        q->front = q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
}

Node* dequeue(Queue *q) {
    if (!q->front) return NULL;

    Node *n = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    n->next = NULL;
    return n;
}

void freeQueue(Queue *q) {
    while (!emptyQ(q)) {
        Node *n = dequeue(q);
        free(n);
    }
}
