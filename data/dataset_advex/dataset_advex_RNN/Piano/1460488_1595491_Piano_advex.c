#include <stdio.h>


int main() {
    int T, n, s, p, t[100], i, j, x, u;
    scanf("%d", &T);
    for (u = 1; u <= T; ++u) {
        scanf("%d%d%d", &n, &s, &p);
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            for (j = i; j > 0; --j) {
                if (x <= t[j - 1]) break;
                t[j] = t[j - 1];
            }
            t[j] = x;
        }
        for (i = 0; i < n && t[i] >= p * 3 - 2; ++i)
            ;
        for (j = 0; j < s && i + j < n && t[i + j] >= p * 3 - 4; ++j)
            if (p == 1 && !t[i + j]) break;
        printf("Case #%d: %d\n", u, i + j);
    }
    return 0;
}
