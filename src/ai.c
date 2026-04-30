//
// Created by wildepic on 4/30/26.
//

#include "aiDataAndWeights.h"

void initAI() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fieldWeightRangeCalculated[i][j][0] = 0;
            fieldWeightRangeCalculated[i][j][1] = 0;
            fieldWeightsCalculated[i][j] = 0;
        }
    }
    for (int i = 0; i < 8; i++) {
        winLineCategory[i] = 0;
    }
}

void calculateWinCategory(char board[][3] , char player) {

}
void calculateFieldWeights() {}
void calculateFieldWeightRange() {}
void getMove(int *x , int *y){}

extern void aiInput(char board[][3] , char player){
    int x = 0;
    int y = 0;
    initAI();
    calculateWinCategory(board , player);
    calculateFieldWeights();
    calculateFieldWeightRange();
    getMove(&x , &y);
    board[x][y] = player;
}