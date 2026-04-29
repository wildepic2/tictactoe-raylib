#ifndef TICTACTOE_DATA_H
#define TICTACTOE_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"

# define boardSize 3
const char player1 = 'o';
const char player2 = 'x';
const int sizeXField = 120;
const int sizeYField = 120;

typedef struct {
    char arr[3][3];
} winCondition;

const winCondition winConditions[8] = {
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

const int fieldsInput[3][3][2] = {
    {
        {
            20 ,20
        },
        {
            160,20
        },
        {
            310,20
        }
    },

{
            {
                20 ,160
            },
            {
                160,160
            },
            {
                310,160
            }
    },

{
            {
                20 ,310
            },
            {
                160,310
            },
            {
                310,310
            }
    },
};

const int XorOpos[3][3][2] = {
    {
        {
            40 ,0
        },
        {
            190,0
        },
        {
            330,0
        }
    },

{
                {
                    40 ,140
                },
                {
                    190,140
                },
                {
                    330,140
                }
    },

{
                {
                    40 ,290
                },
                {
                    190,290
                },
                {
                    330,290
                }
    },
};

enum menuState {
    STARTMENU,
    SETUPGAME,
    GAME,
    ENDMENU
  };

bool retryInput = false;
int winningLine = 0;
char winner = 'l';

void gameLoop();
void printBoard(char board[][boardSize] , bool won);
void playerInput(char board[][boardSize] , char player);
void checkIfPlayerWon(char board[][boardSize] , char player);
bool checkDraw(char board[][boardSize]);
void playerBlock(char board[][boardSize] , char player );
char randomPlayer();
void mainMenuPrint();
void printGameBG();
void startButton(enum menuState *menuState);

#endif //TICTACTOE_DATA_H