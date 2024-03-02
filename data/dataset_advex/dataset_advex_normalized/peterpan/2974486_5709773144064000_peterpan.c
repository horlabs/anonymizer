#include <stdio.h>
#include <stdlib.h>
int main() {
    int T, tcase, i, counter;
    double C, F, X, t, v, tf, tmin;

    scanf("%d", &T);
    for (tcase = 1; tcase <= T; tcase++) {
        scanf("%lf %lf %lf", &C, &F, &X);

        i = 0;
        tf = 0;
        v = 2.0;
        tmin = tf + X / v;
        counter = 0;
        while (counter < 100) {
            tf += C / v;
            i++;
            v += F;
            t = tf + X / v;
            if (t < tmin) {
                tmin = t;
                if (counter)
                    fprintf(stderr, "Reseting counter.\n");
                counter = 0;
            } else
                counter++;
        }
        printf("Case #%d: %.7lf\n", tcase, tmin);
    }

    return 0;
}
