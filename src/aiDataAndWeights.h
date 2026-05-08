//
// Created by wildepic on 4/30/26.
//

#ifndef TICTACTOE_AIDATAANDWEIGHTS_H
#define TICTACTOE_AIDATAANDWEIGHTS_H

#include <stdio.h>

typedef struct {
    char arr[3][3];
} winLine;

const winLine winLines[8] = {
    {
        {
            {'x' , 'x' , 'x'},
            {'l' , 'l' , 'l'},
            {'l' , 'l' , 'l'}
        }
    },
    {
                                   {
                                       {'l' , 'l' , 'l'},
                                       {'x' , 'x' , 'x'},
                                       {'l' , 'l' , 'l'}
                                   }
    },
    {
                                   {
                                       {'l' , 'l' , 'l'},
                                       {'l' , 'l' , 'l'},
                                       {'x' , 'x' , 'x'}
                                   }
    },
    {
                                   {
                                       {'x' , 'l' , 'l'},
                                       {'x' , 'l' , 'l'},
                                       {'x' , 'l' , 'l'}
                                   }
    },
    {
                                   {
                                       {'l' , 'x' , 'l'},
                                       {'l' , 'x' , 'l'},
                                       {'l' , 'x' , 'l'}
                                   }
    },
    {
                                   {
                                       {'l' , 'l' , 'x'},
                                       {'l' , 'l' , 'x'},
                                       {'l' , 'l' , 'x'}
                                   }
    },
    {
                                   {
                                       {'x' , 'l' , 'l'},
                                       {'l' , 'x' , 'l'},
                                       {'l' , 'l' , 'x'}
                                   }
    },
    {
                                   {
                                       {'l' , 'l' , 'x'},
                                       {'l' , 'x' , 'l'},
                                       {'x' , 'l' , 'l'}
                                   }
    }
};

// 1. Positional Value
// Keep these as they are; they represent perfect Tic-Tac-Toe geometry.
const int fieldWeights[3][3] = {
    {9, 3, 9},
    {3, 10, 3},
    {9, 3, 9}
};

int winLineCategory[8];

const int fullLines = 0;
const int lineWithOnePlayerCategory =1;
const int lineWithTwoPlayerCategory =2;
const int lineWhitoutPlayerOrAICategory = 3;
const int lineWithOneAICategory = 4;
const int lineWithTwoAICategory = 5;

// 2. Line Type Value
// Increased diagonals to 15 to force the AI to value corner-center-corner lines.
const int winLineWeights[8] = {4, 8, 4, 4, 8, 4, 15, 15};

// 3. Situational Weights (Reworked for maximum "Win/Draw" efficiency)
const int lineWithTwoAIWeight = 1200;      // Total Decision: Always take the win
const int lineWithTwoPlayerWeight = 1000;   // Solid Block: Force the draw
const int lineWithOneAIWeight = 60;        // Strategic Setup: Create the fork
const int lineWithOnePlayerWeight = 30;    // Aggressive Defense: Deny the player
const int lineWhitoutPlayerOrAIWeigt = 20; // Early Game: Control the board
const int fullLinesWeight = 10;

int fieldWeightsCalculated[3][3];
int fieldWeightRangeCalculated[3][3][2];

#endif //TICTACTOE_AIDATAANDWEIGHTS_H
