#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

struct TestCase {
    unsigned long a;
    unsigned long b;
};

int isPalindrome(unsigned long num) {
    char str[MAX_LENGTH];
    int i, len, mid;

    sprintf(str, "%lu ", num);
    len = strlen(str) - 1;
    mid = len / 2;

    for (i = 0; i < mid; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int countPalindromeSquares(unsigned long start, unsigned long stop) {
    int count = 0;
    unsigned long p;

    for (p = start; p <= stop; p++) {
        if (isPalindrome(p) && isPalindrome(p * p)) {
            count++;
        }
    }

    return count;
}

void processTestCases(struct TestCase* testCases, int numCases) {
    int i, count;
    unsigned long start, stop;

    for (i = 0; i < numCases; i++) {
        count = 0;
        start = ceil(sqrt(testCases[i].a));
        stop = floor(sqrt(testCases[i].b));
        count = countPalindromeSquares(start, stop);

        printf("Case #%d: %d\n", i + 1, count);
    }
}

int main() {
    int t, i;
    struct TestCase* testCases;

    scanf("%d", &t);

    testCases = (struct TestCase*)malloc(t * sizeof(struct TestCase));
    if (testCases == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    for (i = 0; i < t; i++) {
        scanf("%lu %lu", &testCases[i].a, &testCases[i].b);
    }

    processTestCases(testCases, t);

    free(testCases);

    return 0;
}