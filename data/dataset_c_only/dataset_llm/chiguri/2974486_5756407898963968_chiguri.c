#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int fc;
    int lc;
    int *f;
    int *l;
} Puzzle;

int findMatchingNumber(Puzzle puzzle) {
    int p = -1;
    int n = 0;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (puzzle.f[puzzle.fc * 4 - i] == puzzle.l[puzzle.lc * 4 - j]) {
                p = puzzle.f[puzzle.fc * 4 - i];
                n++;
            }
        }
    }

    return n;
}

void printResult(int num, int p) {
    printf("Case #%d: ", num);

    switch (p) {
        case 1:
            printf("%d\n", p);
            break;
        case 0:
            printf("Volunteer cheated!\n");
            break;
        default:
            printf("Bad magician!\n");
            break;
    }
}

int main(void) {
    int num;
    
    scanf("%d", &num);

    for (int i = 1; i <= num; ++i) {
        Puzzle puzzle;

        scanf("%d", &puzzle.fc);
        puzzle.f = (int*) malloc(sizeof(int) * 16);

        for (int j = 0; j < 16; ++j) {
            scanf("%d", &puzzle.f[j]);
        }

        scanf("%d", &puzzle.lc);
        puzzle.l = (int*) malloc(sizeof(int) * 16);

        for (int j = 0; j < 16; ++j) {
            scanf("%d", &puzzle.l[j]);
        }

        int matchedNumbers = findMatchingNumber(puzzle);

        printResult(i, matchedNumbers);

        free(puzzle.f);
        free(puzzle.l);
    }

    return 0;
}