#include <stdio.h>

typedef struct {
    long a;
    long b;
} Pair;

long getMostSignificantDigit(long n) {
    long tens;

    for (tens = 1; n >= 10; n /= 10, tens *= 10)
        ;

    return tens;
}

long rotate(long m, long msd) {
    return m / 10 + msd * (m % 10);
}

long countPairs(long a, long b, long n) {
    const long msd = getMostSignificantDigit(a);
    long count = 0;
    long m;

    for (m = rotate(n, msd); m != n; m = rotate(m, msd)) {
        if (m <= b && m > n) {
            count++;
            fprintf(stderr, "(%ld, %ld)\n", n, m);
        }
    }

    return count;
}

void runTestCases(int numTestCases) {
    for (int i = 0; i < numTestCases; i++) {
        long a, b;
        long totalPairs = 0;

        scanf("%ld %ld", &a, &b);

        for (long n = a; n <= b; n++) {
            totalPairs += countPairs(a, b, n);
        }

        printf("Case #%d: %ld\n", i + 1, totalPairs);
    }
}

int main() {
    int numTestCases;

    scanf("%d", &numTestCases);

    runTestCases(numTestCases);

    return 0;
}