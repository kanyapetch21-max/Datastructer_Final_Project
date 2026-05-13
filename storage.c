#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"
#include "hash.h"

#define FILE_NAME "vocab.txt"

void saveToFile(Card *deck) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error saving file.\n");
        return;
    }

    while (deck) {
        fprintf(fp, "%s|%s|%d\n", deck->word, deck->meaning, deck->score);
        deck = deck->next;
    }

    fclose(fp);
    printf("Saved successfully.\n");
}

void loadFromFile(Card **deck) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return;

    char line[400];
    while (fgets(line, sizeof(line), fp)) {
        char word[WORD_SIZE];
        char meaning[MEANING_SIZE];
        int score = 0;

        word[0] = meaning[0] = '\0';

        if (sscanf(line, "%63[^|]|%255[^|]|%d", word, meaning, &score) == 3) {
            add(deck, word, meaning);
            Card *c = find(*deck, word);
            if (c) {
                c->score = score;
                insertHash(c);
            }
        }
    }
    fclose(fp);
}
