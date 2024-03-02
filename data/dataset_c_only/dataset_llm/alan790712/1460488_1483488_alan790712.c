/*
* This is an anonymized version of the original code.
* The code has been rearranged and variables/functions have been renamed to conceal the original author's intent.
* The logic flow and control flow have been modified while retaining the core functionality.
* Comments have been adjusted for readability.
* The code appearance has been altered to obfuscate the original layout.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

int numRangeStart, numRangeEnd;
int digitCount;
int numPermutations[MAX_DIGITS];
int permutationCount;

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int check(int num) {
    int i;
    int totalPermutations = 0;
    permutationCount = 0;

    for (i = 1; i < digitCount; ++i) {
        numPermutations[permutationCount] = num % ten[i] * ten[digitCount - i] + num / ten[i];
        if (numPermutations[permutationCount] >= numRangeStart && numPermutations[permutationCount] <= numRangeEnd && numPermutations[permutationCount] < num) {
            ++permutationCount;
        }
    }

    qsort(numPermutations, permutationCount, sizeof(int), compare);
    totalPermutations = (permutationCount > 0);

    for (i = 1; i < permutationCount; ++i) {
        if (numPermutations[i] != numPermutations[i - 1]) {
            ++totalPermutations;
        }
    }

    return totalPermutations;
}

int main() {
    int testCases;
    int i;
    int total = 0;
    int currentTestCase = 0;

    scanf("%d", &testCases);

    while (testCases--) {
        scanf("%d %d", &numRangeStart, &numRangeEnd);

        for (i = numRangeStart, digitCount = 0; i > 0; i /= 10, ++digitCount);

        for (i = numRangeStart, total = 0; i <= numRangeEnd; ++i) {
            total += check(i);
        }

        printf("Case #%d: %d\n", ++currentTestCase, total);
    }

    return 0;
}