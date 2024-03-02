#include <stdio.h>

int main(int argc, char **argv) {
    int var_0[200];
    int var_1[200][3];
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9 = 0;
    int var_10;
    int var_11;
    int var_12 = 1;

    FILE *var_13;
    FILE *var_14;

    var_13 = fopen("B-small-attempt0.in", "r");
    var_14 = fopen("output.txt", "w");
    fscanf(var_13, "%d", &var_11);
    while (var_12 <= var_11) {
        fscanf(var_13, "%d %d %d", &var_7, &var_8, &var_3);
        var_0[0] = var_7;
        var_0[1] = var_8;
        var_0[2] = var_3;
        for (var_2 = 0; var_2 < var_7; var_2++) {
            fscanf(var_13, "%d", &var_0[var_2 + 3]);
        }
        for (var_2 = 0; var_2 < var_0[0]; var_2++) {
            for (var_6 = 10; var_6 > 0; var_6--) {

                if (var_0[var_2 + 3] / var_6 == 0) {
                    if (var_6 - 1 == 0) {
                        var_1[var_2][0] = 0;
                        var_1[var_2][1] = 0;
                        var_1[var_2][2] = 0;
                    }
                    continue;
                } else {

                    if (abs((var_0[var_2 + 3] % var_6) - var_6) == 1 ||
                        abs((var_0[var_2 + 3] % var_6) - var_6) == 2) {
                        var_1[var_2][1] = var_6;

                        var_1[var_2][0] = var_0[var_2 + 3] % var_6;
                        var_1[var_2][2] = var_6;
                        break;
                    }
                }
            }
        }
        while (var_8 > 0) {
            for (var_2 = 0; var_2 < var_7; var_2++) {
                if (var_1[var_2][0] <= var_3) {
                    var_8--;
                    var_1[var_2][0]++;
                    var_1[var_2][1]--;
                    var_1[var_2][2]--;
                    break;
                } else {
                    if (var_1[var_2][1] <= var_3) {
                        var_8--;
                        var_1[var_2][0]--;
                        var_1[var_2][1]++;
                        var_1[var_2][2]--;
                        break;
                    } else {
                        var_8--;
                        var_1[var_2][0]--;
                        var_1[var_2][1]--;
                        var_1[var_2][2]++;
                        break;
                    }
                }
            }
        }
        for (var_2 = 0; var_2 < var_0[0]; var_2++) {
            if (var_1[var_2][1] >= var_3 || var_1[var_2][0] >= var_3 ||
                var_1[var_2][2] >= var_3) {
                var_9++;
            }
        }
        fprintf(var_14, "Case #%d: %d\n", var_12, var_9);
        var_12++;
        var_9 = 0;
    }
    return 0;
}
