#include <stdio.h>
#include <stdlib.h>


int main() {
    int T, tcase, N, S, p, t, t3, best, i, res;

    scanf("%d", &T);
    for (tcase = 1; tcase <= T; tcase++) {
        scanf("%d", &N);
        scanf("%d", &S);
        scanf("%d", &p);
        res = 0;
        for (i = 0; i < N; i++) {
            scanf("%d", &t);
            t3 = t % 3;
            best = t / 3;
            if (t3 != 0)
                best++;
            if (best >= p)
                res++;
            else if (S > 0 && best + 1 >= p && (t3 == 2 || (t3 == 0 && best - 1 >= 0))) {
                res++;
                S--;
            }
        }
        printf("Case #%d: %d\r\n", tcase, res);
    }
    return 0;
}
