#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countNumbers(int a, int b) {
    int k;
    if (a < 10)
        k = 0;
    else if (a < 100)
        k = 1;
    else if (a < 1000)
        k = 2;
    else if (a < 10000)
        k = 3;
    else if (a < 100000)
        k = 4;
    else if (a < 1000000)
        k = 5;
    else if (a < 10000000)
        k = 6;

    int result = 0;
    if (k > 0) {
        int i, j, x, y, z, temp;
        char str[100];
        int dup[10];
        for (i = a; i <= b; i++) {
            z = 10;
            memset(dup, 0, 10 * sizeof(int));
            for (j = 0; j < k; j++) {
                x = i % z;
                y = i / z;
                sprintf(str, "%d%d", x, y);
                temp = atoi(str);
                if ((temp > i) && (temp <= b) && (temp >= a)) {
                    int bdup = 0;
                    for (int ii = 0; ii < j; ii++) {
                        if (dup[ii] == temp)
                            bdup = 1;
                    }
                    if (!bdup) {
                        result++;
                        dup[j] = temp;
                    }
                }
                z *= 10;
            }
        }
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int nc = 1; nc <= t; nc++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int result = countNumbers(a, b);
        printf("Case #%d: %d\n", nc, result);
    }

    return 0;
}