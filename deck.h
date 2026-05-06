#ifndef DECK_H
#define DECK_H

#define WORD_SIZE 64
#define MEANING_SIZE 256

typedef struct Card {
    char word[WORD_SIZE];
    char meaning[MEANING_SIZE];
    int score;
    int flag;
    struct Card *next;
} Card;

Card* create(char *w, char *m);
void add(Card **head, char *w, char *m);
Card* find(Card *head, char *w);
void deleteCard(Card **head, char *w);
void showAll(Card *deck);
void freeAll(Card *deck);
int count(Card *deck);
void resetFlag(Card *deck);
int accuracy(Card *c);

#endif
