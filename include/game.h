#ifndef GAME_H
#define GAME_H

#define EMPTY 0
#define BLACK 1
#define WHITE 2

int isGameEnd();
int isValidPlace(int row, int col);
void restartGame();
void inputMove();
void placeStone(int row, int col, int color);
void clearScreen();
void newTurn();
#endif
