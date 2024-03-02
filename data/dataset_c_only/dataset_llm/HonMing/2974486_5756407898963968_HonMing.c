#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int map[4][4];
} Puzzle;

int checkMatch(int* p1, int* p2) {
    int count = 0;
    int ans = -1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (p1[i] == p2[j]) {
                ans = p1[i];
                count++;
                break;
            }
        }
    }

    if (count == 0)
        return -1;
    else if (count == 1)
        return ans;
    else
        return -2;
}

int main() {
    int cases;
    scanf("%d", &cases);

    Puzzle puzzle1[10];
    Puzzle puzzle2[10];
    int results[10];

    for (int i = 0; i < cases; i++) {
        int row1, row2;
        scanf("%d", &row1);

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                scanf("%d", &puzzle1[i].map[j][k]);
            }
        }

        scanf("%d", &row2);

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                scanf("%d", &puzzle2[i].map[j][k]);
            }
        }

        results[i] = checkMatch(puzzle1[i].map[row1-1], puzzle2[i].map[row2-1]);
    }

    for (int i = 0; i < cases; i++) {
        printf("Case #%d: ", i + 1);
        
        if (results[i] == -1)
            printf("Volunteer cheated!\n");
        else if (results[i] == -2)
            printf("Bad magician!\n");
        else
            printf("%d\n", results[i]);
    }
    return 0;
}