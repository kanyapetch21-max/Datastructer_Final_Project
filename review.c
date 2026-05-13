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

    Queue *q = (Queue*)malloc(sizeof(Queue) * max);
    if (!q) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < max; i++) {
        initQ(&q[i]);
    }

    resetFlag(deck);

    Card *cur = deck;
    int idx = 0;
    while (cur) {
        enqueue(&q[idx / SET_SIZE], cur);
        cur = cur->next;
        idx++;
    }

    for (int s = 0; s < max; s++) {
        while (!emptyQ(&q[s])) {
            Node *n = dequeue(&q[s]);
            Card *c = n->card;
            free(n);

            clear();
            line();
            centerText("FLASHCARD");
            line();

            {
                char buf[128];
                snprintf(buf, sizeof(buf), "WORD: %s", c->word);
                textLine(buf);
            }
            line();
            textLine("Press Enter to reveal...");
            line();
            pauseScreen();

            clear();
            line();
            centerText("ANSWER");
            line();
            {
                char buf[160];
                snprintf(buf, sizeof(buf), "WORD: %s", c->word);
                textLine(buf);
                snprintf(buf, sizeof(buf), "MEAN: %s", c->meaning);
                textLine(buf);
                snprintf(buf, sizeof(buf), "SCORE: %d%%", c->score);
                textLine(buf);
            }
            line();
            textLine("1) Easy   (+50)");
            textLine("2) Medium (+25)");
            textLine("3) Hard   (-75)");
            textLine("0) Exit");
            line();

            int ch = getInt("Choose: ");

            if (ch == 0) {
                for (int i = s; i < max; i++) {
                    freeQueue(&q[i]);
                }
                free(q);
                return;
            }

            if (ch == 1) {
                c->score += 50;
                if (c->score > 100) c->score = 100;

                int t = s + EASY_GAP;
                if (t < max) enqueue(&q[t], c);
            } else if (ch == 2) {
                c->score += 25;
                if (c->score > 100) c->score = 100;

                int t = s + MEDIUM_GAP;
                if (t < max) enqueue(&q[t], c);
            } else {
                c->score -= 75;
                if (c->score < 0) c->score = 0;

                if (c->flag == 0) {
                    c->flag = 1;
                    enqueue(&q[s], c);
                } else {
                    c->flag = 0;
                    int t = minInt(s + 1, max - 1);
                    enqueue(&q[t], c);
                }
            }
        }
    }

    free(q);

    clear();
    line();
    centerText("REVIEW FINISHED");
    line();
    textLine("All sets are done.");
    line();
    pauseScreen();
}
