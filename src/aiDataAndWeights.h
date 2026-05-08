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

const int fieldWeights[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

int winLineCategory[8];

const int fullLines = 0;
const int lineWithOnePlayerCategory =1;
const int lineWithTwoPlayerCategory =2;
const int lineWhitoutPlayerOrAICategory = 3;
const int lineWithOneAICategory = 4;
const int lineWithTwoAICategory = 5;

const int winLineWeights[8] = {0 , 0, 0, 0, 0, 0 ,0 ,0};
const int fullLinesWeight = 0;
const int lineWithOnePlayerWeight = 0;
const int lineWithTwoPlayerWeight =0;
const int lineWhitoutPlayerOrAIWeigt = 0;
const int lineWithOneAIWeight =0;
const int lineWithTwoAIWeight = 0;

int fieldWeightsCalculated[3][3];
int fieldWeightRangeCalculated[3][3][2];

#endif //TICTACTOE_AIDATAANDWEIGHTS_H
