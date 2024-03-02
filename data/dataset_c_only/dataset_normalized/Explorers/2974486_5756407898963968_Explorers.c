#include <stdio.h>

int func_0(int var_0, int var_1, int var_2, int var_3, int var_4, int var_5,
           int var_6, int var_7) {
    int var_8 = 0;
    int var_9 = 0;
    int var_10;

    if (var_0 == var_4 || var_0 == var_5 || var_0 == var_6 || var_0 == var_7) {
        if (var_8 == 0) {
            var_8 = 1;
            var_10 = var_0;
        } else {
            if (var_9 == 0) {
                return -2;
            }
        }
    }
    if (var_1 == var_4 || var_1 == var_5 || var_1 == var_6 || var_1 == var_7) {
        if (var_8 == 0) {
            var_8 = 1;
            var_10 = var_1;
        } else {
            if (var_9 == 0) {
                return -2;
            }
        }
    }
    if (var_2 == var_4 || var_2 == var_5 || var_2 == var_6 || var_2 == var_7) {
        if (var_8 == 0) {
            var_8 = 1;
            var_10 = var_2;
        } else {
            if (var_9 == 0) {
                return -2;
            }
        }
    }
    if (var_3 == var_4 || var_3 == var_5 || var_3 == var_6 || var_3 == var_7) {
        if (var_8 == 0) {
            var_8 = 1;
            var_10 = var_3;
        } else {
            if (var_9 == 0) {
                return -2;
            }
        }
    }
    if (var_8 == 0 && var_9 == 0) {
        return -3;
    } else {
        return var_10;
    }
}

int main(int argc, char **argv) {
    int var_11;
    int var_12;
    int var_13;
    int var_14;
    int var_15;
    int var_16;
    int var_17;
    int var_18;
    int var_19;
    int var_20;
    int var_21;
    int var_22;
    int var_23;

    int var_24;
    int var_25;
    int var_26;
    int var_27;

    int var_28;

    scanf("%d", &var_11);

    for (var_12 = 0; var_12 < var_11; var_12++) {
        for (var_13 = 0; var_13 < 2; var_13++) {
            scanf("%d", &var_15);
            for (var_14 = 0; var_14 < 4; var_14++) {
                if (var_14 == var_15 - 1) {
                    if (var_13 == 0) {
                        scanf("%d %d %d %d", &var_16, &var_17, &var_18,
                              &var_19);
                    } else {
                        scanf("%d %d %d %d", &var_20, &var_21, &var_22,
                              &var_23);
                    }
                } else {
                    scanf("%d %d %d %d", &var_24, &var_25, &var_26, &var_27);
                }
            }
        }

        var_28 = func_0(var_16, var_17, var_18, var_19, var_20, var_21, var_22,
                        var_23);
        if (var_28 > 0) {
            printf("Case #%d: %d\n", var_12 + 1, var_28);
        } else {
            if (var_28 == -2) {
                printf("Case #%d: %s\n", var_12 + 1, "Bad magician!");
            } else {
                if (var_28 == -3) {
                    printf("Case #%d: %s\n", var_12 + 1, "Volunteer cheated!");
                }
            }
        }
    }
    return 0;
}
