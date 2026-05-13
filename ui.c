#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "hash.h"

#define WIDTH 50

void clear(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void line(void) {
    printf("+");
    for (int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
}

void centerText(const char *text) {
    int len = (int)strlen(text);
    int pad = (WIDTH - len) / 2;
    if (pad < 0) pad = 0;

    printf("|");
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", text);
    for (int i = 0; i < WIDTH - pad - len; i++) printf(" ");
    printf("|\n");
}

void textLine(const char *text) {
    printf("| %-*s |\n", WIDTH - 2, text);
}

void menu(void) {
    clear();
    line();
    centerText("ANKI VOCAB SYSTEM");
    line();
    textLine("1) Review");
    textLine("2) Add Word");
    textLine("3) Delete Word");
    textLine("4) Search");
    textLine("5) Show All");
    textLine("6) Save Progress");
    textLine("0) Exit");
    line();
}

void readLine(char *buf, int size) {
    if (fgets(buf, size, stdin)) {
        buf[strcspn(buf, "\n")] = '\0';
    } else {
        buf[0] = '\0';
    }
}

int getInt(const char *msg) {
    char buf[32];
    printf("%s", msg);
    if (fgets(buf, sizeof(buf), stdin)) {
        return atoi(buf);
    }
    return 0;
}

void pauseScreen(void) {
    printf("\nPress Enter...");
    getchar();
}

void addUI(Card **deck) {
    char w[WORD_SIZE];
    char m[MEANING_SIZE];

    clear();
    line();
    centerText("ADD WORD");
    line();

    printf("Word: ");
    readLine(w, WORD_SIZE);
    printf("Meaning: ");
    readLine(m, MEANING_SIZE);

    add(deck, w, m);
    insertHash(find(*deck, w));

    pauseScreen();
}

void deleteUI(Card **deck) {
    char w[WORD_SIZE];

    clear();
    line();
    centerText("DELETE WORD");
    line();

    printf("Delete word: ");
    readLine(w, WORD_SIZE);

    deleteHash(w);
    deleteCard(deck, w);

    pauseScreen();
}

void searchUI(Card *deck) {
    char w[WORD_SIZE];

    clear();
    line();
    centerText("SEARCH WORD");
    line();

    printf("Search: ");
    readLine(w, WORD_SIZE);

    Card *c = searchHash(w);
    if (!c) {
        c = find(deck, w);
    }

    if (c) {
        printf("%s = %s [%d%%]\n", c->word, c->meaning, c->score);
    } else {
        printf("Not found.\n");
    }

    pauseScreen();
}
