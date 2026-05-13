#include <stdio.h>
#include <stdlib.h>
#include "review.h"
#include "queue.h"
#include "ui.h"

#define SET_SIZE 5
#define EASY_GAP 3
#define MEDIUM_GAP 1

void review(Card *deck) {
    int total = count(deck);
    if (total == 0) {
        clear();
        line();
        centerText("REVIEW SESSION");
        line();
        textLine("No words in deck.");
        line();
        pauseScreen();
        return;
    }

    int sets = (total + SET_SIZE - 1) / SET_SIZE;
    int max = sets + EASY_GAP + 2;
