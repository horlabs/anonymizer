#include <stdlib.h>
#include <stdio.h>

typedef struct Board {
    int rows[4][4];
} Board;

typedef struct NumberCount {
    int count[16];
} NumberCount;

void ReadInput(Board *board, int *row) {
    int i, j;
    scanf("%d", row);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &(board->rows[i][j]));
        }
    }
}

void CountNumbers(Board *board, NumberCount *count, int row) {
    int i;
    for (i = 0; i < 16; i++) {
        count->count[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        count->count[board->rows[row-1][i]-1] += 1;
    }
}

int CheckPossibleNumbers(NumberCount *count, int *answer) {
    int i, possibleCount = 0;
    for (i = 0; i < 16; i++) {
        if (count->count[i] == 2) {
            possibleCount += 1;
            *answer = i+1;
        }
    }
    return possibleCount;
}

void WriteOutput(int testCase, int possibleCount, int answer) {
    FILE *fout=fopen("out.txt","a");
    fprintf(fout,"Case #%d: ", testCase);
    if (possibleCount == 1) {
        fprintf(fout,"%d\n", answer);
    } else {
        fprintf(fout,"%s\n", possibleCount > 1 ? "Bad magician!" : "Volunteer cheated!");
    }
    fclose(fout);
}

int main(void) {
    int T, k;
    Board board;
    NumberCount count;
    int row, psb, ans;

    FILE *fin=fopen("A-small-attempt0.in","r");
    fscanf(fin,"%d",&T);
    fclose(fin);
    
    FILE *fout=fopen("out.txt","w");
    fclose(fout);

    for (k = 0; k < T; k++) {
        ReadInput(&board, &row);
        CountNumbers(&board, &count, row);
        psb = CheckPossibleNumbers(&count, &ans);
        WriteOutput(k+1, psb, ans);
    }

    return 0;
}
