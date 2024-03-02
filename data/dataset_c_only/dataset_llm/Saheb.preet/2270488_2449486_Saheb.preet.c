#include <stdio.h>

#define MAX_ROWS 101
#define MAX_COLS 101

typedef struct {
    int row_max[MAX_ROWS];
    int col_max[MAX_COLS];
    int ground[MAX_ROWS][MAX_COLS];
} Grid;

void initialize(Grid* grid, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        grid->row_max[i] = 0;
        for (int j = 0; j < num_cols; j++) {
            grid->col_max[j] = 0;
            grid->ground[i][j] = 0;
        }
    }
}

void calculateMaxValues(Grid* grid, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            int value;
            scanf("%d", &value);
            grid->ground[i][j] = value;
            if (value > grid->row_max[i]) {
                grid->row_max[i] = value;
            }
            if (value > grid->col_max[j]) {
                grid->col_max[j] = value;
            }
        }
    }
}

int validateGrid(Grid* grid, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (grid->ground[i][j] != grid->row_max[i] && grid->ground[i][j] != grid->col_max[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n, m;
        scanf("%d%d", &n, &m);

        Grid grid;
        initialize(&grid, n, m);
        calculateMaxValues(&grid, n, m);

        int isValid = validateGrid(&grid, n, m);

        if (isValid) {
            printf("Case #%d: YES\n", i + 1);
        } else {
            printf("Case #%d: NO\n", i + 1);
        }
    }

    return 0;
}