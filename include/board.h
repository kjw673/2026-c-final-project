#ifndef BOARD_H
#define BOARD_H

#define EMPTY 0
#define BLACK 1
#define WHITE 2

void init_board(int board[15][15]);
void print_board(int board[15][15]);
void place_stone(int board[15][15], int color);

#endif
