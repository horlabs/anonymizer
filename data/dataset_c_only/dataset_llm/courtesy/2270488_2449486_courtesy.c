#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int data[MAX_ROWS][MAX_COLS];
    int max_row[MAX_ROWS];
    int max_col[MAX_COLS];
} Matrix;

Matrix matrix;
int num_cases;

void readInput() {
    freopen("C:\\Users\\anonymous\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\anonymous\\Desktop\\out.txt", "w", stdout);

    scanf("%d", &num_cases);

    for (int cs = 1; cs <= num_cases; cs++) {
        int num_rows, num_cols;
        scanf("%d %d", &num_rows, &num_cols);

        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                scanf("%d", &matrix.data[i][j]);
                if (matrix.data[i][j] > matrix.max_row[i])
                    matrix.max_row[i] = matrix.data[i][j];
                if (matrix.data[i][j] > matrix.max_col[j])
                    matrix.max_col[j] = matrix.data[i][j];
            }
        }

        bool isPossible = true;

        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (matrix.data[i][j] < matrix.max_row[i] && matrix.data[i][j] < matrix.max_col[j]) {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible)
                break;
        }

        if (isPossible)
            printf("Case #%d: YES\n", cs);
        else
            printf("Case #%d: NO\n", cs);
    }
}

int main() {
    readInput();
    return 0;
}