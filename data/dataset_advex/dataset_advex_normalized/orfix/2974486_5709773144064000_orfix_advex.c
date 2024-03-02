#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    freopen("B-small-attempt0.in", "r", stdin);

    int var_0 = 0;
    int var_1;
    double var_2;
    double var_3;
    double var_4;

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {
        double var_5 = 0;
        double var_6 = 2;

        scanf("%lf %lf %lf\n", &var_2, &var_3, &var_4);

        while (1) {
            if (var_5 + (var_4 / var_6) >
                var_5 + (var_2 / var_6) + (var_4 / (var_6 + var_3))) {

                var_5 = var_5 + (var_2 / var_6);
                var_6 = var_6 + var_3;
            } else {

                var_5 = var_5 + (var_4 / var_6);
                break;
            }
        }

        printf("Case #%d: %lf\n", ++var_0, var_5);
    }

    return 0;
}
