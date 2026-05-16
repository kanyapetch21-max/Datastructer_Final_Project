#include <stdio.h>
#include "deck.h"
#include "hash.h"
#include "review.h"
#include "storage.h"
#include "ui.h"

int main(void) {
    Card *deck = NULL;

    initTable();
    loadFromFile(&deck);

    if (!deck) {
        add(&deck, "Acrimony", "bitterness");
        insertHash(find(deck, "Acrimony"));

        add(&deck, "Adversity", "hardship");
        insertHash(find(deck, "Adversity"));

        add(&deck, "Aesthetic", "beauty");
        insertHash(find(deck, "Aesthetic"));

        add(&deck, "Altruistic", "selfless");
        insertHash(find(deck, "Altruistic"));

        add(&deck, "Amiable", "friendly");
        insertHash(find(deck, "Amiable"));

        add(&deck, "Animosity", "hatred");
        insertHash(find(deck, "Animosity"));

        add(&deck, "Apathy", "no interest");
        insertHash(find(deck, "Apathy"));

        add(&deck, "Arduous", "very hard");
        insertHash(find(deck, "Arduous"));

        add(&deck, "Assiduous", "hardworking");
        insertHash(find(deck, "Assiduous"));

        add(&deck, "Audacious", "bold");
        insertHash(find(deck, "Audacious"));

        add(&deck, "Benevolent", "kind");
        insertHash(find(deck, "Benevolent"));

        add(&deck, "Belligerent", "aggressive");
        insertHash(find(deck, "Belligerent"));

        add(&deck, "Capricious", "unpredictable");
        insertHash(find(deck, "Capricious"));

        add(&deck, "Cognizant", "aware");
        insertHash(find(deck, "Cognizant"));

        add(&deck, "Conundrum", "problem");
        insertHash(find(deck, "Conundrum"));

        add(&deck, "Deleterious", "harmful");
        insertHash(find(deck, "Deleterious"));

        add(&deck, "Diligent", "careful");
        insertHash(find(deck, "Diligent"));

        add(&deck, "Disparity", "difference");
        insertHash(find(deck, "Disparity"));

        add(&deck, "Eloquent", "fluent");
        insertHash(find(deck, "Eloquent"));

        add(&deck, "Ephemeral", "short-lived");
        insertHash(find(deck, "Ephemeral"));

        add(&deck, "Erudite", "scholarly");
        insertHash(find(deck, "Erudite"));

        add(&deck, "Exacerbate", "worsen");
        insertHash(find(deck, "Exacerbate"));

        add(&deck, "Fastidious", "very picky");
        insertHash(find(deck, "Fastidious"));

        add(&deck, "Fortuitous", "lucky");
        insertHash(find(deck, "Fortuitous"));

        add(&deck, "Impeccable", "perfect");
        insertHash(find(deck, "Impeccable"));

        add(&deck, "Impetuous", "rash");
        insertHash(find(deck, "Impetuous"));

        add(&deck, "Juxtapose", "compare");
        insertHash(find(deck, "Juxtapose"));

        add(&deck, "Lethargic", "lazy");
        insertHash(find(deck, "Lethargic"));

        add(&deck, "Meticulous", "very careful");
        insertHash(find(deck, "Meticulous"));

        add(&deck, "Pragmatic", "practical");
        insertHash(find(deck, "Pragmatic"));
    }

    while (1) {
        menu();

        int c = getInt("Select: ");

        if (c == 1) {
            review(deck);
        } else if (c == 2) {
            addUI(&deck);
        } else if (c == 3) {
            deleteUI(&deck);
        } else if (c == 4) {
            searchUI(deck);
        } else if (c == 5) {
            clear();
            line();
            centerText("ALL VOCABULARY");
            line();
            showAll(deck);
            line();
            pauseScreen();
        } else if (c == 6) {
            saveToFile(deck);
            pauseScreen();
        } else if (c == 0) {
            saveToFile(deck);
            break;
        }
    }

    freeAll(deck);
    return 0;
}
