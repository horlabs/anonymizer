#include <assert.h>
#include <stdio.h>
#include <string.h>


void solve(int c, double C, double F, double X) {
    double t = 0, rate = 2;

    while ((X / rate) > (X / (rate + F) + (C / rate))) {
        t = t + C / rate;
        rate = rate + F;
    }

    t = t + X / rate;
    printf("Case #%d: %.7lf\n", c, t);
}

int main(int argc, char **argv) {
    int t, i;
    double C, F, X;

    assert(scanf("%d ", &t) == 1);
    for (i = 1; i <= t; i++) {
        assert(scanf("%lf %lf %lf ", &C, &F, &X) == 3);
        solve(i, C, F, X);
    }
    return 0;
}
