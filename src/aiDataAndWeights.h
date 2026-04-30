//
// Created by wildepic on 4/30/26.
//

#ifndef TICTACTOE_AIDATAANDWEIGHTS_H
#define TICTACTOE_AIDATAANDWEIGHTS_H

#include <stdio.h>

typedef struct {
    char arr[3][3];
} winCondition2;

const winCondition2 winConditions2[8] = {
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

#endif //TICTACTOE_AIDATAANDWEIGHTS_H
