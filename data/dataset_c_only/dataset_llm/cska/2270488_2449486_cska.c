#include <stdlib.h>
#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_LAWN_SQUARES (MAX_ROWS * MAX_COLUMNS)
#define INPUT_FILE "B-small-attempt0.in"
#define OUTPUT_FILE "out.txt"

typedef struct {
    int row;
    int column;
    int diffHeight;
    int isGood;
} LawnSquare;

int compare(const void *elem1, const void *elem2) {
    return ((LawnSquare *)elem1)->diffHeight - ((LawnSquare *)elem2)->diffHeight;
}

void readInput(int *T, int *N, int *M, LawnSquare lawn[MAX_ROWS][MAX_COLUMNS]) {
    FILE *fin = fopen(INPUT_FILE, "r");
    fscanf(fin, "%d", T);
    for (int i = 0; i < *T; i++) {
        fscanf(fin, "%d%d", N, M);
        for (int j = 0; j < *N; j++) {
            for (int k = 0; k < *M; k++) {
                lawn[j][k].row = j;
                lawn[j][k].column = k;
                lawn[j][k].isGood = 0;
                fscanf(fin, "%d", &(lawn[j][k].diffHeight));
            }
        }
    }
    fclose(fin);
}

void sortLawn(LawnSquare lawn[MAX_ROWS][MAX_COLUMNS], LawnSquare lawnStraight[MAX_LAWN_SQUARES], int N, int M) {
    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            lawnStraight[index].row = lawn[i][j].row;
            lawnStraight[index].column = lawn[i][j].column;
            lawnStraight[index].isGood = lawn[i][j].isGood;
            lawnStraight[index].diffHeight = lawn[i][j].diffHeight;
            index++;
        }
    }
    qsort(lawnStraight, index, sizeof(LawnSquare), compare);
}

int checkIfLawnIsGood(LawnSquare lawn[MAX_ROWS][MAX_COLUMNS], LawnSquare lawnStraight[MAX_LAWN_SQUARES], int N, int M) {
    int isGood = 1;
    for (int i = 0; i < N && isGood; i++) {
        int height = lawnStraight[i].diffHeight;
        int row = lawnStraight[i].row;
        int column = lawnStraight[i].column;

        // check row
        int j;
        for (j = 0; j < M && lawn[row][j].diffHeight <= height; j++);
        if (j == M) {
            isGood = 1;
        } else {
            // check column
            for (j = 0; j < N && lawn[j][column].diffHeight <= height; j++);
            if (j == N) {
                isGood = 1;
            } else {
                isGood = 0;
            }
        }
    }
    return isGood;
}

void writeOutput(int k, int isGood) {
    FILE *fout = fopen(OUTPUT_FILE, "a");
    fprintf(fout, "Case #%d: %s\n", k + 1, isGood == 1 ? "YES" : "NO");
    fclose(fout);
}

int main(void) {
    int T, N, M;
    LawnSquare lawn[MAX_ROWS][MAX_COLUMNS];
    LawnSquare lawnStraight[MAX_LAWN_SQUARES];

    readInput(&T, &N, &M, lawn);
    for (int k = 0; k < T; k++) {
        sortLawn(lawn, lawnStraight, N, M);
        int isGood = checkIfLawnIsGood(lawn, lawnStraight, N, M);
        writeOutput(k, isGood);
    }
    
    return 0;
}