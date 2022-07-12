#include <stdio.h>
#include <stdlib.h> // for random generation
#include <time.h> // for time_t
#include <Windows.h> // for clearing and pausing the screen

#include "ConsoleDeco.h"

void confirmation(const char* const question, _Bool* b);

/*************************************
 * ---------- Tic-Tac-Toe ---------- *
 *************************************/
int checkGameStatus(char board[], int* gameStatus, _Bool* isPlayerTurn, int* playerScore, int* enemyScore) {
    if (*gameStatus == 0) {
        int isOver = 0;
        // Check if rows are filled:
        if (board[0] == board[1] && board[1] == board[2])
            isOver = 1;
        else if (board[3] == board[4] && board[4] == board[5])
            isOver = 1;
        else if (board[6] == board[7] && board[7] == board[8])
            isOver = 1;

        // Check if columns are filled:
        else if (board[0] == board[3] && board[3] == board[6])
            isOver = 1;
        else if (board[1] == board[4] && board[4] == board[7])
            isOver = 1;
        else if (board[2] == board[5] && board[5] == board[8])
            isOver = 1;

        // Check if Slants are filled:
        else if (board[0] == board[4] && board[4] == board[8])
            isOver = 1;
        else if (board[2] == board[4] && board[4] == board[6])
            isOver = 1;

        // Tie:
        else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' &&
                board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
                return 1;

        // Winning condition:
        if (isOver) {
            // Player Scored:
            if (*isPlayerTurn) (*playerScore)++;

            // Enemy Scored:
            else (*enemyScore)++;
        }

        // Check player turn:
        *isPlayerTurn = (!(*isPlayerTurn)) ? 1 : 0;
        return isOver;
    }
    // Check if something is wrong:
    if (*isPlayerTurn) {
        setFontColor(red);
        printf("\nNumber is already marked, please try again.\n");
        Sleep(300);
        system("pause");
    }
        
    return 0;
}

void markBoard(char board[], int* gameStatus, _Bool isPlayerTurn) {
    // check if it's player turn:
    unsigned int input = 0;
    if (isPlayerTurn) {
        printf("\nType here: ");
        setFontColor(white);
        scanf("%d", &input);
    }
        
    else // Enemy:
        input = 1 + rand() % 9;

    // check if the player already marked the board
    _Bool isChecked = 0;
    for (int i = 0; i < 9; i++) {
        if (input == i + 1)
            if (board[i] != '0' + i + 1) {
                isChecked = 1;
                *gameStatus = 2;
            }
    }

    // mark the board:
    if (!isChecked) {
        switch (input) {
        case 1: board[0] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 2: board[1] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 3: board[2] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 4: board[3] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 5: board[4] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 6: board[5] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 7: board[6] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 8: board[7] = (isPlayerTurn) ? 'X' : 'O'; break;
        case 9: board[8] = (isPlayerTurn) ? 'X' : 'O'; break;

        // If input is invalid or not found:
        default:
            setFontColor(red);
            printf("\nWrong input, please try again.\n");
            Sleep(300);
            setFontColor(white);
            system("pause");
            *gameStatus = 2;
            break;
        }
    }
}

void displayBoard(char board[], int playerScore, int enemyScore) {
    setFontColor(white);
    printf("Player: %d\t", playerScore);
    setFontColor(red);
    printf("Enemy: %d\n\n", enemyScore);

    setFontColor(green);
    printf("  ._____._____._____.\n");

    // Upper:
    printf("  |  %c  |  %c  |  %c  |\n", board[0], board[1], board[2]);
    printf("  |_____|_____|_____|\n");

    // Middle:
    printf("  |  %c  |  %c  |  %c  |\n", board[3], board[4], board[5]);
    printf("  |_____|_____|_____|\n");

    // Lower:
    printf("  |  %c  |  %c  |  %c  |\n", board[6], board[7], board[8]);
    printf("  |_____|_____|_____|\n");
}

void gameLoop(void) {
    // Declare and initialize:
    _Bool isGameOn = 1;

    _Bool isPlayerTurn = 1;
    int playerScore = 0, enemyScore = 0;

    // Game Loop:
    while (isGameOn) {
        // Game Loop Init:
        char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        int gameStatus = 0;

        // Gameplay:
        while (gameStatus == 0) { 
            system("cls"); // clear screen
            // Display board:
            displayBoard(board, playerScore, enemyScore);
            // Mark board:
            markBoard(board, &gameStatus, isPlayerTurn);
            // Check if the game is over:
            gameStatus = checkGameStatus(board, &gameStatus, &isPlayerTurn, &playerScore, &enemyScore);
        }
        system("cls"); // clear screen
        displayBoard(board, playerScore, enemyScore);
        confirmation("\n\'Y\' - go back to main menu\n\'N\' - keep playing\n", &isGameOn);
    }
}

/***********************************
 * ---------- Main Menu ---------- *
 ***********************************/
void confirmation(const char* const question, _Bool* b) {
    _Bool isConfirming = 1;
    
    printf(question);
    printf("Type \'Y\' or \'N\': ");
    while (isConfirming) {
        char input = '\0';
        setFontColor(white);
        scanf("%c", &input);

        switch(input) {
        case 'Y':
        case 'y':
            isConfirming = 0;
            *b = 0;
            break;

        case 'N':
        case 'n':
            isConfirming = 0;
            break;

        default:
            break;
        }
    }
}

void mainMenu(_Bool* isProgramRunning) {
    system("cls");

    setFontColor(green);
    printf("\n");
    printf("  ._______________________________.\n");
    printf("  |   TIC-TAC-TOE CONSOLE GAME    |\n");
    printf("  |_______________________________|\n");
    printf("  |   \'P\' - play tic-tac-toe      |\n");
    printf("  |   \'Q\' - Quit Program          |\n");
    printf("  |_______________________________|\n");
    printf("\nType here: ");
    char input = '\0';
    setFontColor(white);
    scanf("%c", &input);

    setFontColor(green);
    switch(input) {
    case 'P':
    case 'p':
        gameLoop();
        break;
        
    case 'Q':
    case 'q':    
        system("cls");
        confirmation("Are you sure you want to quit the program?\n", isProgramRunning);
        break;

    default:
        break;
    }
}

/***************************************
 * ---------- Main Function ---------- *
 ***************************************/
int main(void) { // Takes no parameters
    // Random init:
    time_t t;
    srand((unsigned)time(&t));

    _Bool isProgramRunning = 1;

    // Program Loop:
    while(isProgramRunning)
        mainMenu(&isProgramRunning);
    
    system("cls");
    setFontColor(white);
    return 0;
}