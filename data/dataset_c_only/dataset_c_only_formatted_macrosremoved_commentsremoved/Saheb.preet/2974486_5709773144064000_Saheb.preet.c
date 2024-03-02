#include <stdio.h>


int main() {
    int t, i;
    double c, f, x, r, n;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%lf%lf%lf", &c, &f, &x);
        r = 2;
        n = 0;
        while (x / r > (x / (r + f) + c / r)) {
            n += c / r;
            r += f;
        }
        printf("Case #%d: %1.7lf\n", i + 1, x / r + n);
    }
    return 0;
}
