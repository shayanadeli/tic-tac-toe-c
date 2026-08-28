#include <stdio.h>
#include <stdbool.h>

#define PLAYER 'X'
#define COMPUTER 'O'

char board[3][3];

// مقدار دهی اولیه برد
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// چاپ صفحه
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// بررسی پایان بازی
bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// بررسی برنده
int evaluate() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            if (board[i][0] == COMPUTER) {
                return 10;
            } else {
                return -10;
            }

    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            if (board[0][j] == COMPUTER) {
                return 10;
            } else {
                return -10;
            }

    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        if (board[0][0] == COMPUTER) {
                return 10;
            } else {
                return -10;
            }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        if (board[0][2] == COMPUTER) {
                return 10;
            } else {
                return -10;
            }

    return 0;
}

int minimax(int depth, bool isMaximizing) {
    int score = evaluate();

    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (isBoardFull()) return 0;

    if (isMaximizing) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = COMPUTER;
                    int val = minimax(depth + 1, false);
                    best = (val > best) ? val : best;
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = PLAYER;
                    int val = minimax(depth + 1, true);
                    best = (val < best) ? val : best;
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void findBestMove(int *satr, int *soton) {
    int bestVal = -1000;
    *satr = -1;
    *soton = -1;

// اگر فقط یک حرکت انجام شده و وسط آزاد است، وسط را بگیر
    int moveCount = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != ' '){
                 moveCount++;
            }
    if (moveCount == 1 && board[1][1] == ' ') {
        *satr = 1;
        *soton = 1;
        return;
    }

    
// حرکت فوری برای بردن
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = COMPUTER;
                if (evaluate() == 10) {
                    *satr = i;
                    *soton = j;
                    board[i][j] = ' ';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // جلوگیری از برد بازیکن
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = PLAYER;
                if (evaluate() == -10) {
                    *satr = i;
                    *soton = j;
                    board[i][j] = ' ';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

// حرکت بهینه با مینیمکس
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = COMPUTER;
                int moveVal = minimax(0, false);
                board[i][j] = ' ';

                if (moveVal > bestVal) {
                    *satr = i;
                    *soton = j;
                    bestVal = moveVal;
                }
            }
        }
    }
}

//نوبت بازیکن
void playerMove() {
    int satr, soton;
    char c;

    while (1) {
        printf("Enter your move (satr and soton: 1-3 1-3): ");

        if (scanf("%d %d", &satr, &soton) != 2) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input! Please enter two numbers.\n");
            continue;
        }

        satr--;
        soton--;

        if (satr < 0 || satr > 2 || soton < 0 || soton > 2) {
            printf("Invalid input! satr and soton must be between 1 and 3.\n");
        } else if (board[satr][soton] != ' ') {
            printf("That cell is already taken. Please try again.\n");
        } else {
            board[satr][soton] = PLAYER;
            break;
        }
    }
}

int main() {

    initializeBoard();
    printf("Game -XO-: You (X) vs Computer (O)\n");
    printf("You start first...\n");
    printBoard();

    while (1) {
        playerMove(); 
        printBoard();

        int result = evaluate();
        if (result == -10) {
            printf(" You win!\n");
            break;
        }

        if (isBoardFull()) {
            printf("Game draw!\n");
            break;
        }

        int satr, soton;
        findBestMove(&satr, &soton);
        board[satr][soton] = COMPUTER;
        printf("Computer plays at (%d,%d)\n", satr+1, soton+1);
        printBoard();

        result = evaluate();
        if (result == 10) {
            printf("Computer wins!\n");
            break;
        }

        if (isBoardFull()) {
            printf("Game draw!\n");
            break;
        }
    }


    printf("\nPress Enter to exit...");
    
    int exit;
    while ((exit = getchar()) != '\n' && exit != EOF);
    
    getchar();

    return 0;
}