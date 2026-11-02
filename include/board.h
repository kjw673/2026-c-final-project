#ifndef BOARD_H
#define BOARD_H

#define BLACK = 0
#define WHITE = 1

void init_board(int board[15][15]);
void print_board(int board[15][15]);
void place_stone(int board[15][15], int color);

#endif
