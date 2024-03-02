#include <stdio.h>

#define MAX_SIZE 4

void readBoard(char board[MAX_SIZE][MAX_SIZE]);
int checkRows(char board[MAX_SIZE][MAX_SIZE]);
int checkColumns(char board[MAX_SIZE][MAX_SIZE]);
int checkDiagonals(char board[MAX_SIZE][MAX_SIZE]);
int isBoardFull(char board[MAX_SIZE][MAX_SIZE]);

int main()
{
    freopen("C:\\Users\\anonymous\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\anonymous\\Desktop\\out.txt", "w", stdout);

    int testCaseCount;
    scanf("%d", &testCaseCount);

    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        char board[MAX_SIZE][MAX_SIZE];

        readBoard(board);

        int winner = checkRows(board);
        if (winner == 0)
            winner = checkColumns(board);
        if (winner == 0)
            winner = checkDiagonals(board);

        if (winner == 1)
            printf("Case #%d: X won\n", testCase);
        else if (winner == 2)
            printf("Case #%d: O won\n", testCase);
        else
        {
            if (isBoardFull(board))
                printf("Case #%d: Draw\n", testCase);
            else
                printf("Case #%d: Game has not completed\n", testCase);
        }
    }

    return 0;
}

void readBoard(char board[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
        scanf("%s", board[i]);
}

int checkRows(char board[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (board[i][0] == 'X' || board[i][0] == 'T')
        {
            int j;
            for (j = 1; j < MAX_SIZE; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'T')
                    break;
            }
            if (j == MAX_SIZE)
                return 1; // X won
        }
        else if (board[i][0] == 'O' || board[i][0] == 'T')
        {
            int j;
            for (j = 1; j < MAX_SIZE; j++)
            {
                if (board[i][j] != 'O' && board[i][j] != 'T')
                    break;
            }
            if (j == MAX_SIZE)
                return 2; // O won
        }
    }

    return 0; // No winner in rows
}

int checkColumns(char board[MAX_SIZE][MAX_SIZE])
{
    for (int j = 0; j < MAX_SIZE; j++)
    {
        if (board[0][j] == 'X' || board[0][j] == 'T')
        {
            int i;
            for (i = 1; i < MAX_SIZE; i++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'T')
                    break;
            }
            if (i == MAX_SIZE)
                return 1; // X won
        }
        else if (board[0][j] == 'O' || board[0][j] == 'T')
        {
            int i;
            for (i = 1; i < MAX_SIZE; i++)
            {
                if (board[i][j] != 'O' && board[i][j] != 'T')
                    break;
            }
            if (i == MAX_SIZE)
                return 2; // O won
        }
    }

    return 0; // No winner in columns
}

int checkDiagonals(char board[MAX_SIZE][MAX_SIZE])
{
    if ((board[0][0] == 'X' || board[0][0] == 'T') && (board[1][1] == 'X' || board[1][1] == 'T') &&
        (board[2][2] == 'X' || board[2][2] == 'T') && (board[3][3] == 'X' || board[3][3] == 'T'))
        return 1; // X won

    if ((board[0][0] == 'O' || board[0][0] == 'T') && (board[1][1] == 'O' || board[1][1] == 'T') &&
        (board[2][2] == 'O' || board[2][2] == 'T') && (board[3][3] == 'O' || board[3][3] == 'T'))
        return 2; // O won

    if ((board[0][3] == 'X' || board[0][3] == 'T') && (board[1][2] == 'X' || board[1][2] == 'T') &&
        (board[2][1] == 'X' || board[2][1] == 'T') && (board[3][0] == 'X' || board[3][0] == 'T'))
        return 1; // X won

    if ((board[0][3] == 'O' || board[0][3] == 'T') && (board[1][2] == 'O' || board[1][2] == 'T') &&
        (board[2][1] == 'O' || board[2][1] == 'T') && (board[3][0] == 'O' || board[3][0] == 'T'))
        return 2; // O won

    return 0; // No winner in diagonals
}

int isBoardFull(char board[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (board[i][j] == '.')
                return 0; // Board is not full
        }
    }

    return 1; // Board is full
}