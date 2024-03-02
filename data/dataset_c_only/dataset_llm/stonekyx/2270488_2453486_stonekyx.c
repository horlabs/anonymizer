#include <stdio.h>
#include <string.h>

typedef struct {
    char row[10];
} Grid;

Grid grid[5];

int checkWin(char ch) {
    int i;
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            if (grid[i].row[j] != ch && grid[i].row[j] != 'T') {
                break;
            }
        }
        if (j >= 4) return 1;
        for (j = 0; j < 4; j++) {
            if (grid[j].row[i] != ch && grid[j].row[i] != 'T') {
                break;
            }
        }
        if (j >= 4) return 1;
    }
    for (i = 0; i < 4; i++) {
        if (grid[i].row[i] != ch && grid[i].row[i] != 'T') {
            break;
        }
    }
    if (i >= 4) return 1;
    for (i = 0; i < 4; i++) {
        if (grid[i].row[3 - i] != ch && grid[i].row[3 - i] != 'T') {
            break;
        }
    }
    if (i >= 4) return 1;
    return 0;
}

int checkFull(void) {
    int i;
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 4; j++) {
            if (grid[i].row[j] == '.') return 0;
        }
    }
    return 1;
}

int getResult(void) {
    if (checkWin('X')) return 0;
    if (checkWin('O')) return 1;
    if (checkFull()) return 2;
    return 3;
}

int main() {
    int numTests, testCount = 0;
    scanf("%d\n", &numTests);
    while (numTests) {
        int i;
        int result;
        for (i = 0; i < 5; i++) {
            fgets(grid[i].row, sizeof(grid[i].row), stdin);
            grid[i].row[strcspn(grid[i].row, "\n")] = '\0';
        }
        result = getResult();
        printf("Case #%d: ", ++testCount);
        switch (result) {
            case 0:
                puts("X won");
                break;
            case 1:
                puts("O won");
                break;
            case 2:
                puts("Draw");
                break;
            case 3:
                puts("Game has not completed");
                break;
            default:
                break;
        }
        numTests--;
    }
    return 0;
}