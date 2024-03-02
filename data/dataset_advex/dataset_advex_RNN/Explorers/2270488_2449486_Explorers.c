#include <stdio.h>


int main() {
    int ntest;
    int i, k, j;
    char *res[100];
    int data[10][10];
    int row, col;
    int flagNo = 0;

    scanf("%d", &ntest);

    for (i = 0; i < ntest; i++) {
        flagNo = 0;
        scanf("%d %d", &row, &col);

        for (j = 0; j < row; j++) {
            for (k = 0; k < col; k++)
                scanf("%d", &data[j][k]);
        }

        for (j = 0; j < row; j++) {
            for (k = 0; k < col; k++) {
                if (data[j][k] == 1) {
                    if (horizCheck(j, k, row, col, data) == 1 || vertCheck(j, k, row, col, data) == 1)
                        continue;
                    else {
                        flagNo = 1;
                        break;
                    }
                }
            }
            if (flagNo == 1)
                break;
        }

        if (flagNo == 1)
            res[i] = "NO";
        else
            res[i] = "YES";
    }

    for (i = 0; i < ntest; i++)
        printf("Case #%d: %s\n", i + 1, res[i]);
}

int horizCheck(int r, int c, int row, int col, int data[10][10]) {
    int i;

    for (i = 0; i < col; i++) {
        if (data[r][i] != 1)
            return 0;
    }
    return 1;
}

int vertCheck(int r, int c, int row, int col, int data[10][10]) {
    int i;

    for (i = 0; i < row; i++) {
        if (data[i][c] != 1)
            return 0;
    }
    return 1;
}
