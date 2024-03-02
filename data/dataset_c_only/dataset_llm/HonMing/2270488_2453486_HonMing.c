#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[4];
} Row;

int checkWinningCondition(char map[4][4], char marker) {
    int i, j;
    
    // check horizontal & vertical
    for (i = 0; i < 4; i++) {
        int rowWin = 1, colWin = 1;
        for (j = 0; j < 4; j++) {
            if (map[i][j] != marker && map[i][j] != 'T') {
                rowWin = 0;
            }
            if (map[j][i] != marker && map[j][i] != 'T') {
                colWin = 0;
            }
        }
        if (rowWin || colWin) {
            return 1;
        }
    }

    // check diagonal
    int diagWin1 = 1, diagWin2 = 1;
    for (i = 0; i < 4; i++) {
        if (map[i][i] != marker && map[i][i] != 'T') {
            diagWin1 = 0;
        }
        if (map[i][3-i] != marker && map[i][3-i] != 'T') {
            diagWin2 = 0;
        }
    }
    if (diagWin1 || diagWin2) {
        return 1;
    }

    return 0;
}

int checkDrawCondition(char map[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (map[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int numCases, i;
    char map[4][4];
    Row rows[4];

    printf("Enter the number of test cases: ");
    scanf("%d", &numCases);

    for (i = 0; i < numCases; i++) {
        int xWin = 0, oWin = 0, draw = 0;
        int j;

        memset(map, 0, sizeof(map));
        
        printf("Enter the values for Case #%d:\n", i+1);
        for (j = 0; j < 4; j++) {
            printf("Enter row %d: ", j+1);
            scanf("%s", rows[j].data);
            memcpy(map[j], rows[j].data, sizeof(rows[j].data));
        }

        xWin = checkWinningCondition(map, 'X');
        oWin = checkWinningCondition(map, 'O');
        draw = checkDrawCondition(map);
        
        if (xWin) {
            printf("Case #%d: X won\n", i+1);
        } else if (oWin) {
            printf("Case #%d: O won\n", i+1);
        } else if (draw) {
            printf("Case #%d: Draw\n", i+1);
        } else {
            printf("Case #%d: Game has not completed\n", i+1);
        }
    }

    return 0;
}