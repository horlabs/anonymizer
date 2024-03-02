#include <stdio.h>


int main() {
    int ncase, i;
    double c, f, x, init, mintime, caltime, timetillfarm;
    scanf("%d", &ncase);

    for (i = 0; i < ncase; i++) {
        init = 2;
        scanf("%lf %lf %lf", &c, &f, &x);
        mintime = x / init;
        caltime = 0;
        timetillfarm = 0;
        while (1) {
            timetillfarm += c / init;
            init += f;
            caltime = timetillfarm + x / init;

            if (caltime < mintime)
                mintime = caltime;
            else
                break;
        }
        printf("Case #%d: %.7lf\n", i + 1, mintime);
    }
}
