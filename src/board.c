#include <stdio.h>
#include "board.h"

void initBoard(int board[15][15]){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(i%2==0){
                borad[i][j]=0;
            }else{
                board[i][j]=1;
            }
        }
    }
}
void printBoard(int board[15][15]){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            printf("%d ");
        }
        printf("\n");
    }
}
void placeStone(int board[15][15], int color){

}