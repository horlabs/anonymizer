#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *var_0;
FILE *var_1;
void func_0() {
    int var_2;
    int var_3;
    int var_4;
    int var_5 = 0;

    fscanf(var_0, "%d", &var_2);
    fscanf(var_0, "%d", &var_4);
    fscanf(var_0, "%d", &var_3);
    int var_6;
    int var_7;
    int var_8;

    for (var_6 = 1; var_6 <= var_2; var_6++) {
        fscanf(var_0, "%d", &var_7);
        var_8 = var_7 / 3;
        if ((var_7 % 3) == 0) {
            if (var_8 >= var_3) {
                var_5++;
            } else {
                if ((var_8 != 0) && ((var_8 + 1) >= var_3) && (var_4 > 0)) {
                    var_5++;
                    var_4--;
                }
            }
            goto end;

        } else if ((var_7 % 3) == 1) {
            if ((var_8 + 1) >= var_3) {
                var_5++;
            }
            goto end;

        } else if ((var_7 % 3) == 2) {
            if ((var_8 + 1) >= var_3) {
                var_5++;
            } else {
                if ((var_4 > 0) && ((var_8 + 2) >= var_3)) {
                    var_5++;
                    var_4--;
                }
            }
            goto end;
        }
    end:
        var_7++;
    }
    fprintf(var_1, "%d", var_5);
    return;
}
int main(int argc, char **argv) {
    var_0 = fopen("/home/vivek/Desktop/s.in", "r");
    var_1 = fopen("/home/vivek/Desktop/s.out", "w");
    int var_9;
    int var_10;

    char var_11;
    fscanf(var_0, "%d", &var_9);
    for (var_10 = 1; var_10 <= var_9; var_10++) {
        fprintf(var_1, "Case #%d: ", var_10);
        func_0();
        var_11 = '\n';
        fputc(var_11, var_1);
        printf("%d", var_10);
    }
    return 1;
}
