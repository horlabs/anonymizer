#include <stdio.h>

int var_0[110][110];
int var_1[110][110];
int var_2[110];
int var_3[110];
int var_4[220][3];

int func_0(int var_5, int var_6) { return var_5 < var_6 ? var_5 : var_6; }
int func_1(int var_7, int var_8) { return var_7 > var_8 ? var_7 : var_8; }

int main(int argc, char **argv) {
    int var_9;
    int var_10 = 1;

    int var_11 = 0;
    int var_12 = 1;

    int var_13;
    int var_14;
    int var_15;
    int var_16;
    int var_17;
    int var_18;
    int var_19;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B_out.txt", "w", stdout);
    scanf("%d", &var_9);
    while (var_9--) {
        scanf("%d%d", &var_14, &var_15);
        for (var_16 = 0; var_16 < var_14; var_16++) {
            var_2[var_16] = 0;
        }
        for (var_17 = 0; var_17 < var_15; var_17++) {
            var_3[var_17] = 0;
        }
        for (var_16 = 0; var_16 < var_14; var_16++) {
            for (var_17 = 0; var_17 < var_15; var_17++) {
                scanf("%d", &var_0[var_16][var_17]);

                var_2[var_16] = func_1(var_2[var_16], var_0[var_16][var_17]);

                var_3[var_17] = func_1(var_3[var_17], var_0[var_16][var_17]);
            }
        }
        var_18 = 0;
        for (var_16 = 0; var_16 < var_14; var_16++) {
            var_4[var_18][0] = var_2[var_16];
            var_4[var_18][1] = var_16;

            var_4[var_18][2] = var_11;
            var_18++;
        }
        for (var_16 = 0; var_16 < var_15; var_16++) {
            var_4[var_18][0] = var_3[var_16];
            var_4[var_18][1] = var_16;

            var_4[var_18][2] = var_12;
            var_18++;
        }
        for (var_16 = 0; var_16 < var_18; var_16++) {
            for (var_17 = 0; var_17 < var_16; var_17++) {
                if (var_4[var_16][0] < var_4[var_17][0]) {
                    var_19 = var_4[var_16][0];

                    var_4[var_16][0] = var_4[var_17][0];

                    var_4[var_17][0] = var_19;

                    var_19 = var_4[var_16][1];

                    var_4[var_16][1] = var_4[var_17][1];

                    var_4[var_17][1] = var_19;

                    var_19 = var_4[var_16][2];

                    var_4[var_16][2] = var_4[var_17][2];

                    var_4[var_17][2] = var_19;
                }
            }
        }
        for (var_16 = 0; var_16 < var_14; var_16++) {
            for (var_17 = 0; var_17 < var_15; var_17++) {
                var_1[var_16][var_17] = 100;
            }
        }
        for (var_16 = var_18 - 1; var_16 >= 0; var_16--) {
            if (var_4[var_16][2] == var_11) {
                for (var_17 = 0; var_17 < var_15; var_17++) {
                    var_1[var_4[var_16][1]][var_17] = var_4[var_16][0];
                }
            } else {
                for (var_17 = 0; var_17 < var_14; var_17++) {
                    var_1[var_17][var_4[var_16][1]] = var_4[var_16][0];
                }
            }
        }
        var_13 = 0;
        for (var_16 = 0; var_16 < var_14; var_16++) {
            for (var_17 = 0; var_17 < var_15; var_17++) {
                if (var_0[var_16][var_17] != var_1[var_16][var_17]) {
                    var_13 = 1;
                }
            }
        }
        printf("Case #%d: %s\n", var_10++, var_13 ? "NO" : "YES");
    }
    return 0;
}
