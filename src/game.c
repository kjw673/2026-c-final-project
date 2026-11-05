#include "game.h"
#include "board.h"
#include <stdio.h>


extern int board[15][15];
int turn = BLACK;

void newTurn() {
    clearScreen();
    printBoard();
    printf("%s의 차례입니다.\n", turn == BLACK ? "흑" : "백");
    inputMove();

}
int isGameEnd() {
    
    return 0;
}

int isValidPlace(int row, int col) {
    if(board[row][col] == EMPTY) {
        return 1; // Valid place
    }
    return 0;
}

void restartGame() {
    
}
void inputMove() {
    int row, col;
    printf("행과 열을 입력하세요: ");
    scanf("%d %d", &row, &col);
    if(row < 1 || row > 15 || col < 1 || col > 15) {
        printf("1에서 15 사이의 행과 열을 입력하세요.\n");
        inputMove();
        return;
    }
    placeStone(row-1, col-1, turn);
}
void placeStone(int row, int col, int color) {
    if(isValidPlace(row, col)) {
        board[row][col] = color;
        turn = (turn == BLACK) ? WHITE : BLACK;
        newTurn();
    }else{
        printf("잘못된 위치입니다.\n");
        inputMove();
    }
}

void clearScreen(void) {
    printf("\033[2J\033[H");
    fflush(stdout);
}