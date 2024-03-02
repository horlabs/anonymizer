#include <stdio.h>
#include <stdlib.h>

#define MAX_LAWN_SIZE 99
#define POSSIBLE       1
#define IMPOSSIBLE     0

typedef struct {
    int rows;
    int cols;
    int lawn[MAX_LAWN_SIZE][MAX_LAWN_SIZE];
} Lawn;

Lawn createLawn(int rows, int cols) {
    Lawn newLawn;
    newLawn.rows = rows;
    newLawn.cols = cols;
    return newLawn;
}

Lawn readLawn() {
    int rows, cols;
    int i, j;
    scanf("%d %d\n", &rows, &cols);
    Lawn newLawn = createLawn(rows, cols);
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &newLawn.lawn[i][j]);
        }
        getchar();
    }
    return newLawn;
}

int isLawnPossible(Lawn lawn) {
    int i, j;
    int res = POSSIBLE;
    
    for (i = 0; i < lawn.rows && res == POSSIBLE; i++) {
        for (j = 0; j < lawn.cols && res == POSSIBLE; j++) {
            int i_res = POSSIBLE;
            int j_res = POSSIBLE;
            int ii, jj;
            
            for (ii = 0; ii < lawn.rows; ii++) {
                if (lawn.lawn[ii][j] > lawn.lawn[i][j]) {
                    i_res = IMPOSSIBLE;
                }
            }
            
            for (jj = 0; jj < lawn.cols; jj++) {
                if (lawn.lawn[i][jj] > lawn.lawn[i][j]) {
                    j_res = IMPOSSIBLE;
                }
            }
            
            if (i_res == IMPOSSIBLE && j_res == IMPOSSIBLE) {
                res = IMPOSSIBLE;
            }
        }
    }
    
    return res;
}

void printResult(int caseNumber, int result) {
    printf("Case #%d: %s\n", caseNumber, result == POSSIBLE ? "YES" : "NO");
}

int main(void) {
    freopen("B-small-attempt0.in", "r", stdin);

    int testcase = 0;
    int testcases;
    scanf("%d\n", &testcases);
    
    while (testcase < testcases) {
        Lawn lawn = readLawn();
        int result = isLawnPossible(lawn);
        printResult(++testcase, result);
    }

    return 0;
}