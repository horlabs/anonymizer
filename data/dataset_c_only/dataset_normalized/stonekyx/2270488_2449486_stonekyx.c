#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2[110][110];
int var_3[110][110];
struct record_0 {
    int field_0, field_1;
} var_4[11000];
int var_5;
int var_6[110][110];

int func_0(const void *var_7, const void *var_8) {
    struct record_0 *var_9 = (struct record_0 *)var_7;
    struct record_0 *var_10 = (struct record_0 *)var_8;

    return var_2[var_10->field_0][var_10->field_1] -
           var_2[var_9->field_0][var_9->field_1];
}

int main(int argc, char **argv) {
    int var_11;
    int var_12 = 0;

    for (scanf("%d", &var_11); var_11; var_11--) {
        int var_13;
        var_5 = 0;
        scanf("%d%d", &var_0, &var_1);
        for (var_13 = 0; var_13 < var_0; var_13++) {
            int var_14;
            for (var_14 = 0; var_14 < var_1; var_14++) {
                scanf("%d", var_2[var_13] + var_14);
                var_4[var_5].field_0 = var_13;
                var_4[var_5].field_1 = var_14;
                var_5++;
                var_3[var_13][var_14] = 100;
            }
        }
        qsort(var_4, var_5, sizeof(struct record_0), func_0);
        memset(var_6, 0, sizeof var_6);
        for (var_13 = 0; var_13 < var_5; var_13++) {
            int var_15;
            int var_16 = var_2[var_4[var_13].field_0][var_4[var_13].field_1];

            for (var_15 = 0; var_15 < var_0; var_15++) {
                if (var_3[var_15][var_4[var_13].field_1] > var_16 &&
                    var_6[var_15][var_4[var_13].field_1]) {
                    break;
                }
            }
            if (var_15 >= var_0) {
                for (var_15 = 0; var_15 < var_0; var_15++) {
                    if (var_3[var_15][var_4[var_13].field_1] > var_16) {
                        var_3[var_15][var_4[var_13].field_1] = var_16;
                    }
                }
            } else {
                for (var_15 = 0; var_15 < var_1; var_15++) {
                    if (var_3[var_4[var_13].field_0][var_15] > var_16 &&
                        var_6[var_4[var_13].field_0][var_15]) {
                        break;
                    }
                }
                if (var_15 >= var_1) {
                    for (var_15 = 0; var_15 < var_1; var_15++) {
                        if (var_3[var_4[var_13].field_0][var_15] > var_16) {
                            var_3[var_4[var_13].field_0][var_15] = var_16;
                        }
                    }
                } else {
                    break;
                }
            }
            var_6[var_4[var_13].field_0][var_4[var_13].field_1] = 1;
        }
        printf("Case #%d: ", ++var_12);
        if (var_13 >= var_5) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
