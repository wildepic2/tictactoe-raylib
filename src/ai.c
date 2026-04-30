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

void calculateWinLineCategory(char board[][3] , char ai) {
    for (int i = 0; i < 8; i++) {
        int aiCounter = 0;
        int playerCounter = 0;

        for (int ii = 0; ii < 3; ii++) {
            for (int iii = 0; iii < 3; iii++) {

            }
        }
    }
}
void calculateFieldWeights() {}
void calculateFieldWeightRange() {}
void getMove(int *x , int *y){}

extern void aiInput(char board[][3] , char ai){
    int x = 0;
    int y = 0;
    initAI();
    calculateWinLineCategory(board , ai);
    calculateFieldWeights();
    calculateFieldWeightRange();
    getMove(&x , &y);
    board[x][y] = ai;
}