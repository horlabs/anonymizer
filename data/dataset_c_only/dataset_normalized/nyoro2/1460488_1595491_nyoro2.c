#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;

    int var_3;
    int var_4;
    int var_5;

    int var_6;
    int var_7;
    int var_8;
    int var_9;

    fscanf(stdin, "%d\n", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {
        fscanf(stdin, "%d %d %d", &var_3, &var_4, &var_5);

        var_9 = 0;
        for (var_2 = 0; var_2 < var_3; var_2++) {
            fscanf(stdin, "%d", &var_6);

            var_7 = (var_6 + 2) / 3;

            if (var_7 >= var_5) {
                var_9++;
            } else {
                if ((var_4 > 0) && (((var_6 % 3) != 1) && (var_7 != 0))) {
                    var_8 = var_7 + 1;

                    if (var_8 >= var_5) {
                        var_9++;
                        var_4--;
                    }
                }
            }
        }
        fprintf(stdout, "Case #%d: %d\n", var_1 + 1, var_9);
    }

    return 0;
}
