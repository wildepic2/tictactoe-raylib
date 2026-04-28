#include "data.h"

int main(void) {
    InitWindow(450, 650, "TIC TAC TOE");
    gameLoop();
    CloseWindow();
    return 0;
}

void gameLoop() {
    enum menuState menuState = STARTMENU;

    char currentPlayer= randomPlayer();
    char board[3][3];

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (menuState) {
            case STARTMENU:
                mainMenuPrint();
                startButton(&menuState);
                break;

            case SETUPGAME:
                for (int i = 0 ; i < 3 ; i++) {
                    for (int ii = 0 ; ii < 3 ; ii++) {
                        board[i][ii] = 'l';
                    }
                }

                winner = 'l';

                menuState = GAME;
                break;

            case GAME:
                char temp[2];
                temp[0] = currentPlayer;
                temp[1] = '\n';
                DrawText(temp, 190, 450 , 150 , RED);

                printBoard(board ,false);
                retryInput = false;
                playerBlock(board , currentPlayer);


                if (!retryInput) {
                    if (currentPlayer == player1) {
                        currentPlayer = player2;
                    }
                    else if (currentPlayer == player2) {
                        currentPlayer = player1;
                    }
                }

                if (checkDraw(board) || winner != 'l') {
                    menuState = ENDMENU;
                }

                break;

            case ENDMENU:
                if (winner != 'l') {
                    char playWon[]= "player   won!";
                    playWon[7] = winner;
                    DrawText(playWon,20 , 580 , 60 , RED);
                    printBoard(board , true);
                }
                else if (winner == 'l') {
                    DrawText("Draw",150 , 580 , 60 , RED);
                    printBoard(board , false);
                }
                startButton(&menuState);

                break;
        }
        EndDrawing();
    }
}

void printBoard(char board[][boardSize] , bool won) {
    printGameBG();
    for (int i = 0; i < boardSize ; i++) {
        for (int ii = 0; ii < boardSize ; ii++) {
            if (board[i][ii] != 'l') {
                char temp[2];
                temp[0] = board[i][ii];
                temp[1] = '\n';
                if (won && winConditions[winningLine].arr[i][ii] == 'x') {
                    DrawText(temp, XorOpos[i][ii][0], XorOpos[i][ii][1] , 150 , RED);
                }
                else
                    DrawText(temp, XorOpos[i][ii][0], XorOpos[i][ii][1] , 150 , BLACK);
            }
        }
    }
}

void Input(int *fieldX , int *fieldY) {
    int x , y;

    if (IsMouseButtonReleased(0)) {
        x = GetMouseX();
        y = GetMouseY();

        for (int i = 0 ; i < 3 ; i++) {
            for (int ii = 0 ; ii < 3 ; ii++) {
                if (fieldsInput[i][ii][0]  < x && (fieldsInput[i][ii][0] + sizeXField)  > x && fieldsInput[i][ii][1]  < y && (fieldsInput[i][ii][1] + sizeYField) > y ){
                   *fieldX = i;
                    *fieldY = ii;
                    return;
                }
            }
        }
    }
}


void playerInput(char board[][boardSize] , char player) {
    int x = -1;
    int y = -1;

    Input(&x , &y);

    if ( board[x][y] != 'l') {
        retryInput = true;
    }
    else {
        if (player == player1) {
            board[x][y] = player1;
        }
        else if (player == player2) {
            board[x][y] = player2;
        }
    }
}

void checkIfPlayerWon(char board[][boardSize], char player) {
    bool returnValue = false;

    for (int i = 0; i < 8 ; i++) {
            returnValue = true;
            for (int ii = 0; ii< 3 ; ii++) {
                for (int iii = 0; iii < 3 ; iii++) {
                    if (player != board[ii][iii] && winConditions[i].arr[ii][iii] == 'x') {
                        returnValue = false;
                    }
                }
            }

           if (returnValue  == true) {
               winningLine = i;
               winner = player;
               break;
           }
    }
}

bool checkDraw(char board[][boardSize]) {
    int locked = 0;

    for (int i = 0; i < 8 ; i++) {
            int p1Counter = 0;
            int p2Counter = 0;

            for (int ii = 0; ii< 3 ; ii++) {
                for (int iii = 0; iii < 3 ; iii++) {
                    if (winConditions[i].arr[ii][iii] == 'x') {
                        if (board[ii][iii] == player1) {
                            p1Counter++;
                        }
                        if (board[ii][iii] == player2) {
                            p2Counter++;
                        }

                    }
                }
            }

            if (p1Counter > 0 && p2Counter > 0) {
                locked++;
            }
    }

    if (locked == 8) {
        return true;
    }

    return false;
}

void playerBlock(char board[][boardSize] , char player ) {
    playerInput(board , player);
    checkIfPlayerWon(board, player);
}

char randomPlayer() {
    srand(time(NULL));  // seed with current tim
    int random = rand() % 2;

    if (random == 1) {
        return player2;
    }
    return player1;
}

void mainMenuPrint() {
    DrawText("Tic-Tac-Toe" , 50, 10 , 50 , BLACK);
    DrawText("By Wildepic" , 240, 60 , 25 , BLACK);
}

void printGameBG() {
    DrawRectangle(140 , 20 , 20 , 400 , BLACK);
    DrawRectangle(290 , 20 , 20 , 400 , BLACK);
    DrawRectangle(20 , 140 , 400 , 20 , BLACK);
    DrawRectangle(20 , 290 , 400 , 20 , BLACK);
}

void printStartButton() {
    DrawRectangle(55 , 515 , 350 , 50 , BLACK);
    DrawText("Press button to start Game",80 , 530 , 20 , WHITE);
}

void startButton(enum menuState *menuState) {
    printStartButton();
    if (IsMouseButtonReleased(0)  && GetMouseX() > 55 && GetMouseX() < 405 && GetMouseY() > 515 && GetMouseY() < 565) {
        *menuState = SETUPGAME;
    }
}