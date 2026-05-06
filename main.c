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
        add(&deck, "Adversity", "hardship");
        add(&deck, "Aesthetic", "beauty");
        add(&deck, "Altruistic", "selfless");
        add(&deck, "Amiable", "friendly");
        add(&deck, "Animosity", "hatred");
        add(&deck, "Apathy", "no interest");
        add(&deck, "Arduous", "very hard");
        add(&deck, "Assiduous", "hardworking");
        add(&deck, "Audacious", "bold");
        add(&deck, "Benevolent", "kind");
        add(&deck, "Belligerent", "aggressive");
        add(&deck, "Capricious", "unpredictable");
        add(&deck, "Cognizant", "aware");
        add(&deck, "Conundrum", "problem");
        add(&deck, "Deleterious", "harmful");
        add(&deck, "Diligent", "careful");
        add(&deck, "Disparity", "difference");
        add(&deck, "Eloquent", "fluent");
        add(&deck, "Ephemeral", "short-lived");
        add(&deck, "Erudite", "scholarly");
        add(&deck, "Exacerbate", "worsen");
        add(&deck, "Fastidious", "very picky");
        add(&deck, "Fortuitous", "lucky");
        add(&deck, "Impeccable", "perfect");
        add(&deck, "Impetuous", "rash");
        add(&deck, "Juxtapose", "compare");
        add(&deck, "Lethargic", "lazy");
        add(&deck, "Meticulous", "very careful");
        add(&deck, "Pragmatic", "practical");

        insertHash(find(deck, "Aberration"));
        insertHash(find(deck, "Alleviate"));
        insertHash(find(deck, "Ambivalent"));
        insertHash(find(deck, "Anomaly"));
    }
