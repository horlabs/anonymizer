#include <stdio.h>
#include <stdlib.h>

typedef struct record_0 {
    int field_0;
    int field_1;
    int field_2;
    struct record_0 *field_3[2];
} set;

set *func_0(set *var_0, int var_1, int var_2);

int func_1(int var_3, int var_4) { return var_3 - var_4; }

int func_2(set *var_5) {
    if (var_5 == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int func_3(set *var_6) {
    if (var_6 == NULL) {
        return 0;
    } else {
        return var_6->field_1;
    }
}

int func_4(set *var_7) {
    if (var_7 == NULL) {
        return 0;
    } else {
        return var_7->field_2;
    }
}

set *func_5(set *var_8) {
    int var_9;

    for (var_9 = 0; var_9 < 2; var_9++) {
        if (func_4(var_8->field_3[!var_9]) - func_4(var_8->field_3[var_9]) <
            -1) {
            if (func_4(var_8->field_3[var_9]->field_3[!var_9]) -
                    func_4(var_8->field_3[var_9]->field_3[var_9]) >
                0) {
                var_8->field_3[var_9] =
                    func_0(var_8->field_3[var_9], var_9, !var_9);
            }

            return func_0(var_8, !var_9, var_9);
        }
    }

    if (var_8 != NULL) {
        if (func_4(var_8->field_3[0]) > func_4(var_8->field_3[1])) {
            var_8->field_2 = func_4(var_8->field_3[0]) + 1;
        } else {
            var_8->field_2 = func_4(var_8->field_3[1]) + 1;
        }

        var_8->field_1 =
            func_3(var_8->field_3[0]) + func_3(var_8->field_3[1]) + 1;
    }

    return var_8;
}

set *func_0(set *var_0, int var_1, int var_2) {
    set *var_10 = var_0->field_3[var_2];

    var_0->field_3[var_2] = var_10->field_3[var_1];
    var_10->field_3[var_1] = func_5(var_0);

    if (var_0 != NULL) {
        var_0->field_1 =
            func_3(var_0->field_3[0]) + func_3(var_0->field_3[1]) + 1;
    }
    if (var_10 != NULL) {
        var_10->field_1 =
            func_3(var_10->field_3[0]) + func_3(var_10->field_3[1]) + 1;
    }

    return func_5(var_10);
}

set *func_6(set *var_11, int var_12) {
    int var_13;

    if (var_11 == NULL) {
        set *var_14 = malloc(sizeof(set));

        var_14->field_0 = var_12;
        var_14->field_1 = 1;
        var_14->field_2 = 1;
        var_14->field_3[0] = NULL;
        var_14->field_3[1] = NULL;

        return var_14;
    } else {

        var_13 = func_1(var_11->field_0, var_12);

        if (var_13 == 0) {
            return var_11;
        } else {

            if (var_13 > 0) {
                var_11->field_3[0] = func_6(var_11->field_3[0], var_12);
            } else {
                var_11->field_3[1] = func_6(var_11->field_3[1], var_12);
            }

            var_11->field_1++;

            return func_5(var_11);
        }
    }
}

set *func_7(set *var_15, set *var_16) {
    if (var_15 == NULL) {
        return var_16;
    } else {

        var_15->field_3[1] = func_7(var_15->field_3[1], var_16);

        return func_5(var_15);
    }
}

int func_8(set *var_17, int var_18) {
    int var_19;

    if (var_17 == NULL) {
        return 0;
    } else {

        var_19 = func_1(var_17->field_0, var_18);

        if (var_19 == 0) {
            return 1;
        } else {

            if (var_19 > 0) {
                return func_8(var_17->field_3[0], var_18);
            } else {
                return func_8(var_17->field_3[1], var_18);
            }
        }
    }
}

void func_9(set *var_20) {
    if (var_20 == NULL) {
    } else {

        func_9(var_20->field_3[0]);
        func_9(var_20->field_3[1]);

        free(var_20);
    }
    return;
}

int func_10(set *var_21, int var_22) {
    int var_23 = func_3(var_21->field_3[0]);

    if (var_22 < var_23) {
        return func_10(var_21->field_3[0], var_22);
    } else {
        if (var_22 == var_23) {
            return var_21->field_0;
        } else {
            return func_10(var_21->field_3[1], var_22 - var_23 - 1);
        }
    }
}

int var_24[2000001][10];
int var_25[2000001];

int main(int argc, char **argv) {
    int var_26;
    int var_27;
    int var_28;
    int var_29;

    set *var_30 = NULL;

    for (var_27 = 1; var_27 <= 2000000; var_27++) {
        int var_31[10];
        int var_32 = var_27;
        int var_33 = 0;

        while (var_32) {
            var_31[var_33++] = var_32 % 10;
            var_32 = var_32 / 10;
        }

        for (var_28 = 0; var_28 < var_33 - 1; var_28++) {
            int var_34 = 0;

            if (var_31[var_28] == 0) {
                continue;
            } else {

                for (var_29 = var_28; var_29 >= 0; var_29--) {
                    var_34 = var_34 * 10;
                    var_34 = var_34 + var_31[var_29];
                }

                for (var_29 = var_33 - 1; var_29 > var_28; var_29--) {
                    var_34 = var_34 * 10;
                    var_34 = var_34 + var_31[var_29];
                }

                if (var_34 < var_27) {
                    var_30 = func_6(var_30, var_34);
                }
            }
        }

        for (var_28 = func_3(var_30) - 1; var_28 >= 0; var_28--) {
            var_24[var_27][var_25[var_27]++] = func_10(var_30, var_28);
        }

        func_9(var_30);
        var_30 = NULL;
    }

    scanf("%d", &var_26);

    for (var_27 = 0; var_27 < var_26; var_27++) {
        int var_35;
        int var_36;
        int var_37 = 0;

        scanf("%d %d", &var_35, &var_36);

        for (var_28 = var_35; var_28 <= var_36; var_28++) {
            for (var_29 = 0; var_29 < var_25[var_28]; var_29++) {
                if (var_24[var_28][var_29] < var_35) {
                    break;
                } else {

                    var_37++;
                }
            }
        }

        printf("Case #%d: %d\n", var_27 + 1, var_37);
    }

    return 0;
}
