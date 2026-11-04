#ifndef GAME.H
#define GAME.H

int isGameEnd(int board[15][15]);
int isValidPlace(int board[15][15]);
void placeStone(int column, int row, int color);
void restartGame();

#endif
