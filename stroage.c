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
