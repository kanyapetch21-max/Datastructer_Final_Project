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

void add(Card **head, char *w, char *m) {
    if (find(*head, w)) {
        printf("Already exists.\n");
        return;
    }

    Card *c = create(w, m);

    if (!*head) {
        *head = c;
        return;
    }

    Card *cur = *head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = c;
}

void deleteCard(Card **head, char *w) {
    Card *cur = *head;
    Card *prev = NULL;

    while (cur) {
        if (strcmp(cur->word, w) == 0) {
            if (!prev) {
                *head = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            printf("Deleted.\n");
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("Not found.\n");
}
