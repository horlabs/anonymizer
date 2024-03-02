#include <stdio.h>
#include <string.h>

int convertToNum(char ch)
{
    switch (ch) {
        case 'X':
            return 0;
        case 'O':
            return 1;
        case 'T':
            return 2;
        case '.':
            return -1;
    }
    return -1;
}

int checkWinner(int sum[10][3])
{
    for (int i = 0; i < 10; i++) {
        if (sum[i][0] + sum[i][2] == 4)
            return 0;
        else if (sum[i][1] + sum[i][2] == 4)
            return 1;
    }
    return -1;
}

void processCases()
{
    int caseCount, caseNum, row, col, index, i, temp, flag;
    int sums[10][3];
    char chessBoard[5][5], ch;

    scanf("%d", &caseCount);
    getchar();
    for (caseNum = 1; caseNum <= caseCount; caseNum++) {
        flag = 0;
        printf("Case #%d: ", caseNum);
        if (caseNum > 1)
            getchar();
        for (row = 0; row < 4; row++) {
            fgets(chessBoard[row], sizeof(chessBoard[0]), stdin);
            getchar();
            //puts(chessBoard[row]);
        }

        memset(sums, 0, sizeof(sums));
        // check winner
        for (index = 0; index < 4; index++) {
            for (i = 0; i < 4; i++) {
                temp = convertToNum(chessBoard[index][i]);
                if (temp >= 0)
                    sums[index][temp]++;
                temp = convertToNum(chessBoard[i][index]);
                if (temp >= 0)
                    sums[4 + index][temp]++;
            }
            temp = convertToNum(chessBoard[index][index]);
            if (temp >= 0)
                sums[8][temp]++;
            temp = convertToNum(chessBoard[index][3 - index]);
            if (temp >= 0)
                sums[9][temp]++;
        }
        int winner = checkWinner(sums);
        if (winner == 0)
            puts("X won");
        else if (winner == 1)
            puts("O won");
        else {
            // check completed
            for (row = 0; row < 4; row++) {
                for (col = 0; col < 4; col++) {
                    if (chessBoard[row][col] == '.') {
                        puts("Game has not completed");
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                    break;
            }
            if (flag == 0)
                puts("Draw");
        }
    }
}

int main()
{
    processCases();
    return 0;
}