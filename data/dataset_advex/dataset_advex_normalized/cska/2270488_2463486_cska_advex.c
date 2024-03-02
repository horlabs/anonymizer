#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char var_0[150];
char var_1[150];
unsigned long long var_2 = 0;

int func_0(char *var_3, char *var_4) {
    int var_5;
    for (var_5 = 0; var_5 < 150; var_5++) {
        if (var_3[var_5] > var_4[var_5]) {
            return 1;
        } else {
            if (var_3[var_5] < var_4[var_5]) {
                return 2;
            }
        }
    }
    return 0;
}

void func_1(char *var_6, unsigned long long var_7) {
    for (int var_8 = 150 - 1; var_8 >= 0;
         var_6[var_8] = var_7 ? var_7 % 10 : 0, var_7 = var_7 / 10, var_8--) {
        ;
    }
    return;
}

void func_2(char *var_9, char *var_10) {
    int var_11;
    int var_12;
    int var_13;
    int var_14 = 0;

    func_1(var_10, 0);
    for (var_11 = 150 - 1; var_11 >= 0; var_11--) {
        for (var_14 = 0, var_13 = var_11, var_12 = 150 - 1; var_13 >= 0;
             var_13--, var_12--) {
            var_14 = var_14 + (var_10[var_13] + var_9[var_11] * var_9[var_12]);
            var_10[var_13] = var_14 % 10;
            var_14 = var_14 / 10;
        }
    }
    return;
}

int func_3(char *var_15) {
    int var_16 = -1;
    while (var_15[++var_16] == 0) {
        ;
    }
    return 150 - var_16;
}

int func_4(char *var_17) {
    int var_18 = -1;
    int var_19;

    while (var_17[++var_18] == 0) {
        ;
    }
    for (var_19 = 150 - 1; var_18 <= var_19 && var_17[var_18] == var_17[var_19];
         var_18++, var_19--) {
        ;
    }
    return var_18 > var_19;
}

void func_5(char *var_20, int var_21, int var_22) {
    static char var_23[150];
    int var_24;
    int var_25;
    int var_26;

    if (var_22 < ceil((float)var_21 / 2)) {
        for (var_24 = var_22 == 0 ? 1 : 0; var_24 < 10; var_24++) {
            var_20[150 - 1 - var_22] = var_20[150 - var_21 + var_22] = var_24;
            func_5(var_20, var_21, var_22 + 1);
        }
    } else {
        func_2(var_20, var_23);
        if (func_4(var_23)) {
            var_25 = func_0(var_0, var_23);
            var_26 = func_0(var_1, var_23);
            if ((var_25 == 0 || var_25 == 2) && (var_26 == 0 || var_26 == 1)) {
                var_2 = var_2 + 1;
            }
        }
    }
    return;
}

int main(int argc, char **argvvoid) {
    char var_27[150] = {0};
    int var_28;
    int var_29;
    int var_30;

    unsigned long long var_31;
    unsigned long long var_32;

    FILE *var_33 = fopen("C-small-attempt0.in", "r");
    FILE *var_34 = fopen("out.txt", "w");

    fscanf(var_33, "%d", &var_30);

    for (var_29 = 0; var_29 < var_30; var_29++) {
        fscanf(var_33, "%llu%llu", &var_31, &var_32);

        func_1(var_0, var_31);
        func_1(var_1, var_32);

        var_2 = 0;
        for (var_28 = ceil(func_3(var_0) / 2.0);
             var_28 <= ceil(func_3(var_1) / 2.0); var_28++) {
            func_1(var_27, 0);
            func_5(var_27, var_28, 0);
        }

        fprintf(var_34, "Case #%d: %llu\n", var_29 + 1, var_2);
    }

    fclose(var_33);
    fclose(var_34);
    return 0;
}
