#include <stdio.h>


int main() {
    int t, u;
    scanf("%d", &t);
    for (u = 1; u <= t; ++u) {
        int n, b, c, d, e, i, j;
        int a[17] = {};
        scanf("%d", &n);
        for (i = 1; i <= 4; ++i) {
            if (i != n) scanf("%*d%*d%*d%*d");
            else {
                scanf("%d%d%d%d", &b, &c, &d, &e);
                a[b] = a[c] = a[d] = a[e] = 1;
            }
        }
        scanf("%d", &n);
        for (i = 1; i <= 4; ++i) {
            if (i != n) scanf("%*d%*d%*d%*d");
            else {
                int ans, cnt = 0;
                for (j = 0; j < 4; ++j) {
                    scanf("%d", &b);
                    if (a[b]) ++cnt, ans = b;
                }
                if (!cnt) printf("Case #%d: Volunteer cheated!\n", u);
                else if (cnt == 1)
                    printf("Case #%d: %d\n", u, ans);
                else
                    printf("Case #%d: Bad magician!\n", u);
            }
        }
    }
    return 0;
}
