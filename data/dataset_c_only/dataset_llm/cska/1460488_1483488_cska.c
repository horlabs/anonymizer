#include <stdlib.h>
#include <stdio.h>

int countCyclicNumbers(int A, int B);
int getNumDigits(int n);
int calculatePower(int n, int k);

int main(void) {
    int cases, i;
    int startingNum, endingNum;
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    fscanf(inputFile, "%d", &cases);

    for(i = 0; i < cases; i++) {
        fscanf(inputFile, "%d%d\n", &startingNum, &endingNum);
        int count = countCyclicNumbers(startingNum, endingNum);
        fprintf(outputFile, "Case #%d: %d\n", i + 1, count);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

int countCyclicNumbers(int A, int B) {
    int i, j, k, d, n, m, result, temp;
    int digits = getNumDigits(A);
    int* uniqueNums = malloc(sizeof(int) * (B - A));
    int uniqueNumCount = 0;

    for(i = A; i < B; i++) {
        for(j = 1; j < digits; j++) {
            temp = 10;
            for(k = 1; k < j; k++) {
                temp *= 10;
            }
            m = i % temp * calculatePower(10, digits - j) + i / temp;

            if(m > i && m <= B) {
                for(n = 0; n < uniqueNumCount; n++) {
                    if(uniqueNums[n] == m) {
                        break;
                    }
                }
                if(n == uniqueNumCount) {
                    uniqueNums[uniqueNumCount] = m;
                    uniqueNumCount++;
                }
            }
        }
    }

    result = uniqueNumCount;

    free(uniqueNums);
    return result;
}

int getNumDigits(int n) {
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int calculatePower(int n, int k) {
    int result = 1;
    for(int i = 0; i < k; i++) {
        result *= n;
    }
    return result;
}