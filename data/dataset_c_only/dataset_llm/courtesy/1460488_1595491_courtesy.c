#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int n;
    int s;
    int m;
} InputParams;

int readInt(FILE* file) {
    int x;
    fscanf(file, "%d", &x);
    return x;
}

void readInputParams(FILE* file, InputParams* params) {
    params->n = readInt(file);
    params->s = readInt(file);
    params->m = readInt(file);
}

int calculateResult(int value, int divisor, int threshold, int* remaining) {
    int quotient = value / divisor;
    int remainder = value % divisor;
    if (remainder == 0) {
        if (quotient >= threshold) {
            return 1;
        }
    } else if (remainder == 1) {
        if (quotient + 1 >= threshold) {
            return 1;
        }
    } else if (remainder == 2) {
        if (quotient + 1 >= threshold) {
            return 1;
        } else if (*remaining > 0 && quotient + 2 >= threshold) {
            (*remaining)--;
            return 1;
        }
    }
    return 0;
}

int countResultCases(FILE* inputFile) {
    int cs = readInt(inputFile);
    int i, result;
    char c;
    for (i = 1; i <= cs; i++) {
        result = processCase(inputFile);
        printf("%d", i);
    }
    return cs;
}

int processCase(FILE* inputFile) {
    InputParams params;
    readInputParams(inputFile, &params);
    int i, j, k, r = 0;
    for (i = 1; i <= params.n; i++) {
        j = readInt(inputFile);
        k = j / 3;
        r += calculateResult(j, 3, params.m, &params.s);
        j++;
    }
    return r;
}

int main() {
    FILE* f1 = fopen("/home/vivek/Desktop/s.in", "r");
    FILE* f2 = fopen("/home/vivek/Desktop/s.out", "w");
    int cs = countResultCases(f1);
    fprintf(f2, "%d", cs);
    return 1;
}