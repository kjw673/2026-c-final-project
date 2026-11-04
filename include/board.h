#ifndef BOARD_H
#define BOARD_H

#define EMPTY 0
#define BLACK 1
#define WHITE 2

void initBoard(int board[15][15]);
void printBoard(int board[15][15]);
void placeStone(int board[15][15], int color);

#endif
