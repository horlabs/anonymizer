#include <stdio.h>

char board[4][5];

int check(char player)
{
    int count;
    
    count = 0;
    for (int i=0; i<4; i++)
        count += (board[i][i] == player || board[i][i] == 'T');
    if (count == 4)
        return 1;

    count = 0;
    for (int i=0; i<4; i++)
        count += (board[i][3-i] == player || board[i][3-i] == 'T');
    if (count == 4)
        return 1;
    
    for (int i=0; i<4; i++)
    {
        count = 0;
        for (int j=0; j<4; j++)
            count += (board[i][j] == player || board[i][j] == 'T');
        if (count == 4)
            return 1;

        count = 0;
        for (int j=0; j<4; j++)
            count += (board[j][i] == player || board[j][i] == 'T');
        if (count == 4)
            return 1;
    }

    return 0;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int caseNum=1; caseNum<=testCases; caseNum++)
    {
        for (int i=0; i<4; i++)
            scanf("%s", board[i]);

        const char *result = "Draw";
        if (check('X'))
            result = "X won";
        else if (check('O'))
            result = "O won";
        else
        {
            int emptyCount = 0;
            for (int i=0; i<4; i++)
            {
                for (int j=0; j<4; j++)
                {
                    if (board[i][j] == '.')
                        emptyCount++;
                }
            }
            if (emptyCount > 0)
                result = "Game has not completed";
        }

        printf("Case #%d: %s\n", caseNum, result);
    }
}