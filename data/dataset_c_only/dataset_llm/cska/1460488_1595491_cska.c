#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_N 128

typedef struct {
    int T;
    int testcases[MAX_N];
} Data;

int getTestCaseCount(FILE* file) {
    int T;
    fscanf(file, "%d\n", &T);
    return T;
}

void readTestCases(FILE* file, Data* data) {
    for (int i = 0; i < data->T; i++) {
        fscanf(file, "%d\n", &data->testcases[i]);
    }
}

int calculateScore(int N, int S, int P, int* t) {
    int k = 0;
    for (int j = 0; j < N; j++) {
        switch (t[j] % 3) {
            case 0:
                if (t[j] / 3 >= P) {
                    k++;
                } else if (S > 0 && t[j] / 3 > 0 && t[j] / 3 < 10 && t[j] / 3 + 1 >= P) {
                    S--;
                    k++;
                }
                break;
            case 1:
                if (t[j] / 3 + 1 >= P) {
                    k++;
                }
                break;
            case 2:
                if (t[j] / 3 + 1 >= P) {
                    k++;
                } else if (S > 0 && t[j] / 3 < 9 && t[j] / 3 + 2 >= P) {
                    S--;
                    k++;
                }
                break;
        }
    }
    return k;
}

void writeOutput(FILE* file, int T, int* scores) {
    for (int i = 0; i < T; i++) {
        fprintf(file, "Case #%d: %d\n", i + 1, scores[i]);
    }
}

int main(void) {
    FILE* fin = fopen("B-small-attempt0.in", "r");
    FILE* fout = fopen("out.txt", "w");

    Data data;
    data.T = getTestCaseCount(fin);
    readTestCases(fin, &data);
    
    int scores[MAX_N];
    for (int i = 0; i < data.T; i++) {
        scores[i] = calculateScore(data.testcases[i], 0, 0, NULL);
    }

    writeOutput(fout, data.T, scores);

    fclose(fin);
    fclose(fout);
    return 0;
}