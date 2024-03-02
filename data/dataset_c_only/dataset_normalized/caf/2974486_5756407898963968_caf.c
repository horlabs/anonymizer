#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_0(int var_0, int var_1, int var_2, int var_3, int var_4) {
    return var_0 == var_1 || var_0 == var_2 || var_0 == var_3 || var_0 == var_4;
}

void func_1(int var_5) {
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;

    int var_12;
    int var_13 = 0;

    scanf("%d", &var_7);

    for (var_6 = 1; var_6 < 5; var_6++) {
        int var_14;
        int var_15;
        int var_16;
        int var_17;

        scanf("%d %d %d %d", &var_14, &var_15, &var_16, &var_17);

        if (var_6 == var_7) {
            var_8 = var_14;
            var_9 = var_15;
            var_10 = var_16;
            var_11 = var_17;
        }
    }

    scanf("%d", &var_7);

    for (var_6 = 1; var_6 < 5; var_6++) {
        int var_18;
        int var_19;
        int var_20;
        int var_21;

        scanf("%d %d %d %d", &var_18, &var_19, &var_20, &var_21);

        if (var_6 == var_7) {
            if (func_0(var_8, var_18, var_19, var_20, var_21)) {
                var_12 = var_8;
                var_13++;
            }
            if (func_0(var_9, var_18, var_19, var_20, var_21)) {
                var_12 = var_9;
                var_13++;
            }
            if (func_0(var_10, var_18, var_19, var_20, var_21)) {
                var_12 = var_10;
                var_13++;
            }
            if (func_0(var_11, var_18, var_19, var_20, var_21)) {
                var_12 = var_11;
                var_13++;
            }
        }
    }

    printf("Case #%d: ", var_5 + 1);
    if (var_13 < 1) {
        printf("Volunteer cheated!\n");
    } else {
        if (var_13 > 1) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", var_12);
        }
    }
    return;
}

int main(int argc, char **argv) {
    int var_22;
    int var_23;

    scanf("%d", &var_22);

    for (var_23 = 0; var_23 < var_22; var_23++) {
        func_1(var_23);
    }

    return 0;
}
