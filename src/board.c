#include <stdio.h>
#include <wchar.h>
#include "board.h"

extern int board[15][15];

void initBoard(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            board[i][j] = EMPTY;
        }
    }
}


// returns the character to be printed for a given position on the board
static wchar_t onBoard(int row, int col){
    if(board[row][col] == BLACK){
        return L'\u25CF';
    }
    if(board[row][col] == WHITE){
        return L'\u25CB';
    }

    if(row == 0 && col == 0) return L'\u250C';
    if(row == 0 && col == 14) return L'\u2510';
    if(row == 14 && col == 0) return L'\u2514';
    if(row == 14 && col == 14) return L'\u2518';
    if(row == 0) return L'\u252C';
    if(row == 14) return L'\u2534';
    if(col == 0) return L'\u251C';
    if(col == 14) return L'\u2524';
    return L'\u253C';
}

void printBoard(){
    for(int i=0;i<15;i++){
        printf("%2d  ", i + 1);
        for(int j=0;j<15;j++){
            printf("%lc", onBoard(i, j));
            if(j<14){
                printf("%lc%lc", L'\u2500', L'\u2500');
            }
        }
        printf("\n");
    }

    printf("    ");
    for(int j=0;j<15;j++){
        printf("%-3d", j + 1);
    }
    printf("\n");
}
