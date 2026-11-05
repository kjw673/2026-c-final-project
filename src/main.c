#include <stdio.h>
#include "board.h"
#include "game.h"
#include <wchar.h>
#include <locale.h>


int board[15][15];

int main(void){
  setlocale(LC_ALL, "");
  initBoard();
  newTurn();
  return 0;
}
