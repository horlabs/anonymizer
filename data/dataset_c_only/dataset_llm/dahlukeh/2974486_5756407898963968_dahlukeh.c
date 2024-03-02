#include <stdio.h>

typedef struct {
    int grid[101][101];
    int isValid[101];
} Data;

void initializeArray(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        array[i] = 0;
    }
}

void fillGrid(Data *data, int row) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf ("%d ", &data->grid[i][j]);
        }
    }
    initializeArray(data->isValid, 101);
    for (i = 0; i < 4; i++) {
        data->isValid[data->grid[row][i]] = 1;
    }
}

void findNumber(Data *data, int row) {
    int i, found = 0, mult = 0, ans = 0;
    for (i = 1; i <= 16; i++) {
        if (data->isValid[i] && data->isValid2[i]) {
            if (found) {
                mult = 1;
            }
            found = 1;
            ans = i;
        }
    }
    if (!found) {
        printf("Volunteer cheated!\n");
    } else if (mult) {
        printf("Bad magician!\n");
    } else {
        printf("%d\n", ans);
    }
}

int main() {
    int t, i;
    scanf ("%d ", &t);
    for (i = 0; i < t; i++) {
        printf("Case #%d: ", i + 1);
        Data data;
        scanf ("%d ", &data.an);
        fillGrid(&data, data.an - 1);
        scanf ("%d ", &data.an);
        fillGrid(&data, data.an - 1);
        findNumber(&data, data.an - 1);
    }
    return 0;
}