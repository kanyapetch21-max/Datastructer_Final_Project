#ifndef UI_H
#define UI_H

#include "deck.h"

void clear(void);
void line(void);
void centerText(const char *text);
void textLine(const char *text);

void menu(void);
void readLine(char *buf, int size);
int getInt(const char *msg);
void pauseScreen(void);

void addUI(Card **deck);
void deleteUI(Card **deck);
void searchUI(Card *deck);

#endif
