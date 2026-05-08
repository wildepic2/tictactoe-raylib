//
// Created by wildepic on 4/30/26.
//

#include <stdlib.h>


#include "aiDataAndWeights.h"
#include "external/miniaudio.h"

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
                if (winLines[i].arr[ii][iii] == 'x') {
                    if (board[ii][iii] == ai) {
                        aiCounter++;
                    } else if (board[ii][iii] == 'x') {
                        playerCounter++;
                    }
                }
            }
        }


        if (aiCounter == 1 && playerCounter == 1) {
            winLineCategory[i] = fullLines;
        }
        else if (playerCounter == 1 && aiCounter == 0) {
            winLineCategory[i] = lineWithOnePlayerCategory;
        }
        else if (playerCounter == 2 && aiCounter == 0) {
            winLineCategory[i] = lineWithTwoPlayerCategory;
        }
        else if (playerCounter == 0 && aiCounter == 1) {
            winLineCategory[i] = lineWithOneAICategory;
        }
        else if (playerCounter == 0 && aiCounter == 2) {
            winLineCategory[i] = lineWithTwoAICategory;
        }
        else if (playerCounter == 0 && aiCounter == 0){
            winLineCategory[i] = lineWhitoutPlayerOrAICategory;
        }
    }
}

void calculateFieldWeights(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int ii = 0; ii < 3; ii++) {
            fieldWeightsCalculated[i][ii] = fieldWeights[i][ii];
            for (int j = 0; j < 8; j++) {
                if (winLines[j].arr[i][ii] == 'x') {
                    fieldWeightsCalculated[i][ii] += winLineWeights[j];
                    if (winLineCategory[j] == lineWithOnePlayerCategory) {
                        fieldWeightsCalculated[i][ii] += lineWithOnePlayerWeight;
                    }
                    else if (winLineCategory[j] == lineWithTwoPlayerCategory) {
                        fieldWeightsCalculated[i][ii] += lineWithTwoPlayerWeight;
                    }
                    else if (winLineCategory[j] == lineWithOneAICategory) {
                        fieldWeightsCalculated[i][ii] += lineWithOneAIWeight;
                    }
                    else if (winLineCategory[j] == lineWithTwoAICategory) {
                        fieldWeightsCalculated[i][ii] += lineWithTwoAIWeight;
                    }
                    else if (winLineCategory[j] == fullLines) {
                        fieldWeightsCalculated[i][ii] += fullLinesWeight;
                    }
                    else {
                        fieldWeightsCalculated[i][ii] += lineWhitoutPlayerOrAIWeigt;
                    }
                }
            }
            if (board[i][ii] == 'x' || board[i][ii] == 'o') {
                fieldWeightsCalculated[i][ii] = 0;
            }
            printf("Field [%d,%d] %d\n", i, ii, fieldWeightsCalculated[i][ii]);
        }
    }
    printf("\n");
}

void calculateFieldWeightRange() {
    int last = 0;
    for (int i = 0; i < 3 ; i++) {
        for (int ii = 0; ii < 3 ; ii++) {
            if (fieldWeightsCalculated[i][ii] == 0) {
                fieldWeightRangeCalculated[i][ii][0] = 0;
                fieldWeightRangeCalculated[i][ii][1] = 0;
            }
            else {
                fieldWeightRangeCalculated[i][ii][0] = last +1;
                fieldWeightRangeCalculated[i][ii][1] = last + fieldWeightsCalculated[i][ii];
                last = last + fieldWeightsCalculated[i][ii] ;
                printf("Field [%d,%d] %d %d\n", i, ii, fieldWeightRangeCalculated[i][ii][0], fieldWeightRangeCalculated[i][ii][1]);
            }
        }
    }
}
void getMove(int *x , int *y) {
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        for (int ii = 0; ii < 3; ii++) {
            sum += fieldWeightsCalculated[i][ii];
        }
    }

    srand(time(NULL));
    int random = rand() % sum +1;
    printf("Random: %d\n", random);

    for (int i = 0 ; i < 3 ; i++) {
        for (int ii = 0 ; ii < 3 ; ii++) {
            if (random >= fieldWeightRangeCalculated[i][ii][0] && random <= fieldWeightRangeCalculated[i][ii][1]) {
                printf("Found: [%d,%d]\n", i, ii);
                *x = i;
                *y = ii;
                return;
            }
        }
    }
}

extern void aiInput(char board[][3] , char ai){
    int x = 0;
    int y = 0;
    initAI();
    calculateWinLineCategory(board , ai);
    calculateFieldWeights(board);
    calculateFieldWeightRange();
    getMove(&x , &y);
    board[x][y] = ai;
}