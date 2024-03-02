#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    double var_2;
    double var_3;
    double var_4;

    double var_5;
    double var_6;
    double var_7;

    int var_8;

    fscanf(stdin, "%d\n", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {

        fscanf(stdin, "%lf %lf %lf\n", &var_2, &var_3, &var_4);

        var_5 = 0;
        var_8 = 0;
        while (1) {
            var_6 = var_5 + var_4 / (var_3 * var_8 + 2);
            var_5 = var_5 + (var_2 / (var_3 * var_8 + 2));
            var_8++;
            var_7 = var_5 + var_4 / (var_3 * var_8 + 2);
            if (var_6 <= var_7) {
                break;
            }
        }

        printf("Case #%d: ", var_1 + 1);
        printf("%.7f\n", var_6);
    }

    return 0;
}
