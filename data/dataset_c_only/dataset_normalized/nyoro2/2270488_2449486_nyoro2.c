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

    int var_8[128][128];
    int var_9;
    int var_10;

    fscanf(stdin, "%d\n", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {
        fscanf(stdin, "%d %d\n", &var_2, &var_3);

        fprintf(stdout, "Case #%d: ", var_1 + 1);

        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                fscanf(stdin, "%d", &var_8[var_4][var_5]);
            }
        }

        var_10 = 1;
        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                var_9 = var_8[var_4][var_5];
                for (var_6 = 0; var_6 < var_2; var_6++) {
                    if (var_8[var_6][var_5] > var_9) {
                        break;
                    }
                }
                if (var_6 < var_2) {
                    for (var_7 = 0; var_7 < var_3; var_7++) {
                        if (var_8[var_4][var_7] > var_9) {
                            break;
                        }
                    }
                    if (var_7 < var_3) {
                        var_10 = 0;
                        goto out_result;
                    }
                }
            }
        }
    out_result:
        fprintf(stdout, "%s", var_10 ? "YES" : "NO");
        fprintf(stdout, "\n");
    }

    return 0;
}
