#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

Card* create(char *w, char *m) {
    Card *c = (Card*)malloc(sizeof(Card));
    if (!c) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(c->word, w);
    strcpy(c->meaning, m);
    c->score = 0;
    c->flag = 0;
    c->next = NULL;
    return c;
}

Card* find(Card *head, char *w) {
    while (head) {
        if (strcmp(head->word, w) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
