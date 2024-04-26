#include <stdio.h>

#define BOARD_SIZE 3

#define EMPTY 0
#define X 1
#define O 2

#define TRUE 1
#define FALSE 0

int board[BOARD_SIZE][BOARD_SIZE];

void print_board();
void display_move(int mover, int square);
int check_square(int square, int board[BOARD_SIZE][BOARD_SIZE]);
int check_win();
int swap(int mover);

int main() {

    print_board();

    int square;
    int mover = X;

    while (1) {
        if (mover == X) {
            printf("Choose a square for X placement: \n");
            scanf("%d", &square);
        } else if (mover == O) {
            printf("Choose a square for O placement: \n");
            scanf("%d", &square);
        }

        if (!check_square(square, board))
        {
            printf("Invalid move. Try again. \n");
            continue;
        }

        display_move(mover, square);

        check_win();
        if (check_win() == X)
        {
            printf("The winner is X! Game is over. \n");
            break;
        }
        else if (check_win() == O)
        {
            printf("The winner is O! Game is over. ");
            break;
        }
        else if (check_win() == -1)
        {
            printf("It is a tie! Game over. ");
            break;
        }

        mover = swap(mover);

    }
}

// This function is used to initialize the 3x3 game board.
void print_board()
{
    int i, j;

    printf("\n|---|---|---|\n");

    for (i = 0; i < BOARD_SIZE; i++) {

        printf("|");

        for (j = 0; j < BOARD_SIZE; j++) {

            if (board[i][j] == EMPTY) {
                printf("   ");
            }
            else if (board[i][j] == X) {
                printf(" X ");
            }
            else if (board[i][j] == O) {
                printf(" O ");
            }

            if ((j + 1) % 1 == 0)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % 1 == 0)
            printf("|---|---|---|\n");

    }
    printf("\n");
}

// This function displays the tic-tac-toe board after each user input.
void display_move(int mover, int square)
{
    int i;

    if (check_square(square, board) == TRUE) {

        if (mover == X) {
            for (i = 0; i < 3; i++) {
                if (square == i + 1) {
                    board[0][i] = X;
                }
                if (square == i + 4) {
                    board[1][i] = X;
                }
                if (square == i + 7) {
                    board[2][i] = X;
                }
            }
        }

        if (mover == O) {
            for (i = 0; i < 3; i++) {
                if (square == i + 1) {
                    board[0][i] = O;
                }
                if (square == i + 4) {
                    board[1][i] = O;
                }
                if (square == i + 7) {
                    board[2][i] = O;
                }
            }
        }

        print_board();

    }
    else
    {
        printf("Invalid move. Try again. ");
    }
}

// This function verifies that the square is empty before placing an X or O.
int check_square(int square, int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    switch (square) {
        case 1:
            i = 0;
            j = 0;
            break;
        case 2:
            i = 0;
            j = 1;
            break;
        case 3:
            i = 0;
            j = 2;
            break;
        case 4:
            i = 1;
            j = 0;
            break;
        case 5:
            i = 1;
            j = 1;
            break;
        case 6:
            i = 1;
            j = 2;
            break;
        case 7:
            i = 2;
            j = 0;
            break;
        case 8:
            i = 2;
            j = 1;
            break;
        case 9:
            i = 2;
            j = 2;
            break;
        default:
            // Invalid square number.
            return 0;
    }
    if (board[i][j] == EMPTY)
    {
        return TRUE; // Square is empty.
    }
    else
    {
        return FALSE; // Square is full.
    }
}

int check_win()
{
    int winner = 0;
    int full = 1;

    //Check across
    if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != EMPTY)
    {
        winner = board[0][0];
    }
    else if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != EMPTY)
    {
        winner = board[1][0];
    }
    else if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != EMPTY)
    {
        winner = board[2][0];
    }

    //Check down
    if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != EMPTY)
    {
        winner = board[0][0];
    }
    else if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != EMPTY)
    {
        winner = board[0][1];
    }
    else if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != EMPTY)
    {
        winner = board[0][2];
    }

    //Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY)
    {
        winner = board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != EMPTY)
    {
        winner = board[0][2];
    }

    // Check for a tie

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                full = 0; // There is an empty square
                break;
            }
        }
    }

    if (full && winner == 0) {
        return -1; // Return -1 to indicate a tie
    }

    return winner;

}

// Swaps to the next player
int swap(int mover) {
    if (mover == X) {
        return O;
    } else if (mover == O) {
        return X;
    }

}
