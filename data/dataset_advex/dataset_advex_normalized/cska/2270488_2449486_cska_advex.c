#include <stdio.h>
#include <stdlib.h>

struct record_0 {
    int field_0, field_1, field_2, field_3;
};

int func_0(const void *var_0, const void *var_1) {
    return ((struct record_0 *)var_0)->field_2 -
           ((struct record_0 *)var_1)->field_2;
}

int main(int argc, char **argvvoid) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;
    int var_12;

    struct record_0 var_13[100][100];
    struct record_0 var_14[10000];

    FILE *var_15 = fopen("B-small-attempt0.in", "r");
    FILE *var_16 = fopen("out.txt", "w");

    fscanf(var_15, "%d", &var_8);

    for (var_5 = 0; var_5 < var_8; var_5++) {
        fscanf(var_15, "%d%d", &var_6, &var_7);
        for (var_2 = 0; var_2 < var_6; var_2++) {
            for (var_3 = 0; var_3 < var_7; var_3++) {
                var_13[var_2][var_3].field_0 = var_2;
                var_13[var_2][var_3].field_1 = var_3;
                var_13[var_2][var_3].field_3 = 0;
                fscanf(var_15, "%d", &(var_13[var_2][var_3].field_2));
            }
        }
        for (var_4 = var_2 = 0; var_2 < var_6; var_2++) {
            for (var_3 = 0; var_3 < var_7; var_3++) {
                var_14[var_4].field_0 = var_13[var_2][var_3].field_0;
                var_14[var_4].field_1 = var_13[var_2][var_3].field_1;
                var_14[var_4].field_3 = var_13[var_2][var_3].field_3;
                var_14[var_4].field_2 = var_13[var_2][var_3].field_2;
                var_4++;
            }
        }
        qsort(var_14, var_4, sizeof(struct record_0), func_0);

        for (var_2 = 0, var_11 = 1; var_2 < var_4 && var_11; var_2++) {
            var_12 = var_14[var_2].field_2;
            var_9 = var_14[var_2].field_0;
            var_10 = var_14[var_2].field_1;

            for (var_3 = 0;
                 var_3 < var_7 && var_13[var_9][var_3].field_2 <= var_12;
                 var_3++) {
                ;
            }
            if (var_3 == var_7) {
                var_11 = 1;
            } else {
                for (var_3 = 0;
                     var_3 < var_6 && var_13[var_3][var_10].field_2 <= var_12;
                     var_3++) {
                    ;
                }
                if (var_3 == var_6) {
                    var_11 = 1;
                } else {
                    var_11 = 0;
                }
            }
        }

        fprintf(var_16, "Case #%d: %s\n", var_5 + 1,
                var_11 == 1 ? "YES" : "NO");
    }

    fclose(var_15);
    fclose(var_16);
    return 0;
}
