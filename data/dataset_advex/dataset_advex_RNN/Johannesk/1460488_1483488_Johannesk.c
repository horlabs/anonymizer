#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int move(int num, int steps, int size) {
    int r, m = 1, sm = 1, p;

    p = size - steps;
    while (p--)
        m = m * 10;
    while (steps--)
        sm = sm * 10;
    r = (num % m) * sm + (num / m);
    return r;
}

int main(int argc, char **argv) {
    int a, b, t, i, j, temp, digits, k, count, m;
    int dup;

    assert(scanf("%d", &t) == 1);
    for (i = 1; i <= t; i++) {
        count = 0;
        assert(scanf("%d %d", &a, &b) == 2);
        for (j = a; j <= b; j++) {
            dup = 0;
            digits = floor(log10(j)) + 1;
            for (k = 1; k < digits; k++) {
                m = move(j, k, digits);
                if (m >= a && m <= b && m > j && m != dup) {

                    count++;
                    dup = m;
                }
            }
        }
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}
