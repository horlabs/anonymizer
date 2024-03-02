#include <stdio.h>
#include <stdlib.h>

#define require(CHECK, MESSAGE) { if(!(CHECK)) { fprintf(stderr,"%s\n",MESSAGE); exit(-1); } }
#define BOARD_SIZE 4

char readLine()
{
    while(getchar() != '\n')
        ;
}

void checkWinner(char board[BOARD_SIZE][BOARD_SIZE], char last, int tcase)
{
    int i, j, winner;

    for(i = 0; i < BOARD_SIZE; i++)
    {
        winner = 1;
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] != last && board[i][j] != 'T')
            {
                winner = 0;
                break;
            }
        }
        if(winner)
        {
            printf("Case #%d: %c won\n", tcase, last);
            return;
        }

        winner = 1;
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[j][i] != last && board[j][i] != 'T')
            {
                winner = 0;
                break;
            }
        }
        if(winner)
        {
            printf("Case #%d: %c won\n", tcase, last);
            return;
        }
    }

    winner = 1;
    for(j = 0; j < BOARD_SIZE; j++)
    {
        if(board[j][j] != last && board[j][j] != 'T')
        {
            winner = 0;
            break;
        }
    }
    if(winner)
    {
        printf("Case #%d: %c won\n", tcase, last);
        return;
    }

    winner = 1;
    for(j = 0; j < BOARD_SIZE; j++)
    {
        if(board[BOARD_SIZE-1-j][j] != last && board[BOARD_SIZE-1-j][j] != 'T')
        {
            winner = 0;
            break;
        }
    }
    if(winner)
    {
        printf("Case #%d: %c won\n", tcase, last);
        return;
    }

    printf("Case #%d: Game has not completed\n", tcase);
}

int main()
{
    int tcase, T, xs, os, ts;
    char board[BOARD_SIZE][BOARD_SIZE], last;

    scanf("%d", &T);

    for(tcase = 1; tcase <= T; tcase++)
    {
        xs = os = ts = 0;

        readLine();

        for(int i = 0; i < BOARD_SIZE; i++)
        {
            for(int j = 0; j < BOARD_SIZE; j++)
            {
                board[i][j] = getchar();

                if(board[i][j] == 'X')
                    xs++;
                else if(board[i][j] == 'O')
                    os++;
                else if(board[i][j] == 'T')
                    ts++;
                else if(board[i][j] != '.')
                {
                    fprintf(stderr, "Error reading input!\n");
                    exit(1);
                }
            }
            readLine();
        }

        if(xs > os)
            last = 'X';
        else
            last = 'O';

        checkWinner(board, last, tcase);
    }

    return 0;
}