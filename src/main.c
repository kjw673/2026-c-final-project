#include <stdio.h>
#include "board.h"
#include "game.h"

int board[15][15];

int main(void){

  initBoard(board);
  printBoard(board);
  return 0;
}
