#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    int var_0 = 0;
    int var_1;

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {

        int var_2 = 0;
        int var_3 = 0;
        int var_4 = 0;
        double var_5 = 0;
        double var_6;
        double var_7;

        scanf("%d %d %lf", &var_2, &var_4, &var_5);

        while (var_2--) {
            double var_8;
            double var_9;
            double var_10;

            scanf("%lf", &var_6);

            if (var_6 < var_5) {
                continue;
            } else {

                var_7 = var_6 / 3;
                var_8 = var_7 - floor(var_7);
                var_7 = floor(var_7);

                if (var_8 == 0) {
                    var_9 = var_7;
                    var_10 = var_7 + 1;

                } else {
                    if (var_8 <= 0.5) {
                        var_9 = var_7 + 1;
                        var_10 = var_9;

                    } else {
                        if (var_8 >= 0.5) {
                            var_9 = var_7 + 1;
                            var_10 = var_7 + 2;
                        }
                    }
                }
                if (var_9 >= var_5) {
                    var_3++;
                } else {
                    if (var_4 > 0 && var_10 >= var_5) {
                        var_3++;
                        var_4--;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", ++var_0, var_3);
    }

    return 0;
}
