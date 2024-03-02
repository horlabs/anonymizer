#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *var_0;
FILE *var_1;
int var_2[8];
int var_3[8];
int var_4;
long long var_5[7];
long long var_6;
int func_0(long long var_7) {
    int var_8 = 0;
    while (var_7 > 0) {
        var_8++;
        var_7 = var_7 / 10;
    }
    return var_8 - 1;
}
void func_1(long long var_9) {
    int var_10;
    int var_11;

    for (var_10 = var_4; var_10 >= 0; var_10--) {
        var_2[var_10] = var_9 % 10;
        var_9 = var_9 / 10;
    }
    return;
}
long long func_2() {
    long long var_12 = 0;
    int var_13;
    for (var_13 = 0; var_13 <= var_4; var_13++) {
        var_12 = var_12 + var_3[var_13];
        var_12 = var_12 * 10;
    }
    var_12 = var_12 / 10;
    return var_12;
}
int func_3(long long var_14) {
    int var_15;
    for (var_15 = 0; var_15 <= var_4; var_15++) {
        if (var_2[var_15] != var_3[var_15]) {
            return 0;
        }
    }
    return 1;
}
void func_4() {
    int var_16;
    int var_17;
    int var_18;

    var_16 = var_3[var_4];
    for (var_17 = var_4 - 1; var_17 >= 0; var_17--) {
        var_3[var_17 + 1] = var_3[var_17];
    }
    var_3[0] = var_16;
    return;
}
int func_5(long long var_19, long long var_20, long long var_21) {
    if (var_2[0] == 0) {
        return 0;
    } else {
        int var_22;
        int var_23 = 0;

        for (var_22 = 0; var_22 <= var_4; var_22++) {
            var_3[var_22] = var_2[var_22];
        }
        int var_24;
        long long var_25;
        var_6 = -1;
        for (var_22 = 1; var_22 <= var_4; var_22++) {
            func_4();
            var_25 = func_2();
            for (var_24 = 0; var_24 <= var_6; var_24++) {
                if (var_5[var_24] == var_25) {
                    goto lst;
                }
            }
            if ((var_25 > var_19) && (var_25 >= var_20) && (var_25 <= var_21)) {
                var_23++;
                var_6++;
                var_5[var_6] = var_25;
            }
        lst:
            var_23 = var_23 + 0;
        }
        return var_23;
    }
}
void func_6() {
    long long var_26;
    long long var_27;
    long long var_28;

    long long var_29 = 0;
    long long var_30;

    fscanf(var_0, "%lld", &var_26);
    fscanf(var_0, "%lld", &var_27);
    var_4 = func_0(var_26);
    if (var_4 == 0) {
        goto end;
    }
    for (var_28 = var_26; var_28 <= var_27; var_28++) {
        func_1(var_28);
        var_30 = func_5(var_28, var_26, var_27);
        var_29 = var_29 + var_30;
        if (var_30 > 0) {
            printf("%lld:%ld\t", var_28, var_30);
        }
    }
end:
    fprintf(var_1, "%ld", var_29);
    return;
}
int main(int argc, char **argv) {
    var_0 = fopen("/home/vivek/Desktop/s.in", "r");
    var_1 = fopen("/home/vivek/Desktop/s.out", "w");
    int var_31;
    int var_32;

    char var_33;
    fscanf(var_0, "%d", &var_31);
    for (var_32 = 1; var_32 <= var_31; var_32++) {
        fprintf(var_1, "Case #%d: ", var_32);
        func_6();
        var_33 = '\n';
        fputc(var_33, var_1);
    }
    return 1;
}
