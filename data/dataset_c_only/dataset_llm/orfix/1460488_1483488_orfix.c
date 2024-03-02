#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIGITS 10

typedef struct {
    int a;
    int b;
} Range;

int calculateTotalCases(int total, Range range) {
    int n, a, b, s1, s2, m, i, j;
    int power = 10;
    int digits = floor(log10(n) + 1);
    int previous[MAX_DIGITS] = {0};

    a = range.a;
    b = range.b;

    for (n = a; n <= b; n++) {
        digits = floor(log10(n) + 1);
        power = 10;
        for (i = 1; i < digits; i++, power *= 10) {
            s1 = n / power;
            s2 = n % power;
            m = s1 + (s2 * pow(10, digits - i));

            if (n < m && m <= b) {
                for (j = 0; j < i; j++) {
                    if (m == previous[j]) {
                        m = 0;
                        break;
                    }
                }
                if (m) {
                    previous[i - 1] = m;
                    total++;
                }
            }
        }
    }
    return total;
}

int main(void) {
    int totalCases, testCase = 0;

    scanf("%d\n", &totalCases);

    while (testCase < totalCases) {
        int total = 0;
        Range range;

        scanf("%d %d\n", &range.a, &range.b);

        total = calculateTotalCases(total, range);

        printf("Case #%d: %d\n", ++testCase, total);
    }

    return 0;
}