#include <stdio.h>

int main() {
    int t, a, b, i, j, k, ten, c;
    scanf("%d", &t);
    for (i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        scanf("%d%d", &a, &b);
        for (ten = 10; ten <= a; ten *= 10)
            ;
        if (ten == 10) {
            puts("0");
            continue;
        }
        ten /= 10;
        c = 0;
        for (j = a; j < b; ++j) {
            int lc = 0;
            k = j;
            while (1) {
                k = k % ten * 10 + k / ten;
                if (k == j) break;
                if (k > j && k <= b) ++c;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
