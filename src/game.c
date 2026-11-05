#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

extern int board[15][15];
int turn = BLACK;

void newTurn() {
    clearScreen();
    if(isGameEnd() != 0) {
        restartGame();
    }
    printBoard();
    printf("%s's turn.\n", turn == BLACK ? "Black" : "White");
    inputMove();
}

// Checks whether five consecutive stones are aligned horizontally, vertically, and diagonally.
int isGameEnd() {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            if(board[i][j] != EMPTY) {
                int color = board[i][j];
                if(j <= 10 && board[i][j+1] == color && board[i][j+2] == color && board[i][j+3] == color && board[i][j+4] == color) {
                    return color;
                }
                if(i <= 10 && board[i+1][j] == color && board[i+2][j] == color && board[i+3][j] == color && board[i+4][j] == color) {
                    return color;
                }
                if(i <= 10 && j <= 10 && board[i+1][j+1] == color && board[i+2][j+2] == color && board[i+3][j+3] == color && board[i+4][j+4] == color) {
                    return color;
                }
                if(i >= 4 && j <= 10 && board[i-1][j+1] == color && board[i-2][j+2] == color && board[i-3][j+3] == color && board[i-4][j+4] == color) {
                    return color;
                }
            }
        }
    }
    return 0;
}

int isValidPlace(int row, int col) {
    if(board[row][col] == EMPTY) {
        return 1; // Valid place
    }
    return 0;
}

void restartGame() {
    char choice = '\0';
    printf("%s wins!\n",isGameEnd() == BLACK ? "Black" : "White");
    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        printf("Do you want to restart? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            clearScreen();
            printBoard();
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    if(choice == 'y' || choice == 'Y') {
        initBoard();
        newTurn();
    }
    else{
        printf("Game over.\n");
        exit(0);
    }
}
void inputMove() {
    int row = 0;
    int col = 0;
    int validInput = 0;

    while (!validInput) {
        printf("Enter row and column: ");
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 15 || col < 1 || col > 15) {
            printf("Please enter a row and column between 1 and 15.\n");
        } else if (!isValidPlace(row - 1, col - 1)) {
            printf("Invalid position.\n");
        } else {
            validInput = 1;
        }
    }

    if (validInput) {
        placeStone(row-1, col-1, turn);
    }
}
void placeStone(int row, int col, int color) {
    if(isValidPlace(row, col)) {
        board[row][col] = color;
        turn = (turn == BLACK) ? WHITE : BLACK;
        newTurn();
    }
    else{
        printf("Invalid position.\n");
    }
}

void clearScreen(void) {
    printf("\033[2J\033[H");
    fflush(stdout);
}