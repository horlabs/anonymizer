#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_VALUE 20

typedef struct {
    int row;
    int map[MAX_SIZE][MAX_SIZE];
    int ans[MAX_VALUE];
} MagicSquare;

void initializeMagicSquare(MagicSquare *square) {
    square->row = 0;
    memset(square->map, 0, sizeof(square->map));
    memset(square->ans, 0, sizeof(square->ans));
}

void readMagicSquare(MagicSquare *square) {
    scanf("%d", &square->row);
    for (int y = 1; y <= 4; y++) {
        for (int x = 0; x < 4; x++) {
            scanf("%d", &square->map[y][x]);
        }
    }
}

void countNumbers(MagicSquare *square) {
    for (int x = 0; x < 4; x++) {
        int val = square->map[square->row][x];
        square->ans[val]++;
    }
}

int checkAnswer(MagicSquare *square) {
    int fAns = 0;
    for (int i = 1; i <= MAX_VALUE; i++) {
        if (square->ans[i] == 2) {
            if (fAns) return 0;
            fAns = i;
        }
    }
    return 1;
}

void printResults(int t, int fAns) {
    printf("Case #%d: ", t);
    if (!fAns) {
        puts("Volunteer cheated!");
        return;
    }
    printf("%d\n", fAns);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int TC, T;
    scanf("%d", &TC);
    for (T = 1; T <= TC; T++) {
        MagicSquare square;
        initializeMagicSquare(&square);

        readMagicSquare(&square);
        countNumbers(&square);

        int fAns = checkAnswer(&square);
        printResults(T, fAns);
    }

    return 0;
}