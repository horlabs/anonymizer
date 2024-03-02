#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 4
#define MAX_COLUMNS 4

typedef struct {
    int rows[MAX_ROWS][MAX_COLUMNS];
} Grid;

bool isValidRow(int row) {
    return row >= 1 && row <= MAX_ROWS;
}

bool isValidNumber(int number) {
    return number >= 1 && number <= 16;
}

bool isNumberInRow(Grid grid, int number, int row) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
        if (grid.rows[row][j] == number) {
            return true;
        }
    }
    return false;
}

void initializeGrid(Grid *grid) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            grid->rows[i][j] = 0;
        }
    }
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);

    int testCase = 1;
    while (numTestCases--) {
        int row1, row2;
        scanf("%d", &row1);

        Grid grid;
        initializeGrid(&grid);

        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLUMNS; j++) {
                int number;
                scanf("%d", &number);
                grid.rows[i][j] = number;
            }
        }

        if (!isValidRow(row1)) {
            printf("Invalid row number for the first magician!\n");
            return 1;
        }

        int answer = -1;

        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLUMNS; j++) {
                int number;
                scanf("%d", &number);

                if (!isValidRow(row2)) {
                    printf("Invalid row number for the second magician!\n");
                    return 1;
                }

                if (isNumberInRow(grid, number, row2 - 1)) {
                    if (answer != -1 && answer != number) {
                        answer = -2;
                    } else {
                        answer = number;
                    }
                }
            }
        }

        printf("Case #%d: ", testCase++);

        if (answer == -2) {
            printf("Bad Magician!\n");
        } else if (answer == -1) {
            printf("Volunteer cheated!\n");
        } else {
            printf("%d\n", answer);
        }
    }

    return 0;
}