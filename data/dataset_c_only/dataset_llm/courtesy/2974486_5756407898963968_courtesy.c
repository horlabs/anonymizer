#include <stdio.h>

void readIntegers(int *nums, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }
}

int main() {
    int numTests, row, index, x, answer, state;
    int row1[4], row2[4];

    scanf("%d", &numTests);

    for (int c = 1; c <= numTests; c++) {
        scanf("%d", &row);
        readIntegers(row1, 4);

        state = 0;
        scanf("%d", &row);
        readIntegers(row2, 4);

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == (row - 1)) {
                    if ((row2[k] == row1[0]) || (row2[k] == row1[1]) || (row2[k] == row1[2]) || (row2[k] == row1[3])) {
                        if (state == 0) {
                            answer = row2[k];
                            state = 1;
                        } else {
                            state = 2;
                        }
                    }
                }
            }
        }

        if (state == 1)
            printf("Case #%d: %d\n", c, answer);
        else if (state == 0)
            printf("Case #%d: Volunteer cheated!\n", c);
        else
            printf("Case #%d: Bad magician!\n", c);
    }

    return 0;
}