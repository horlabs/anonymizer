#include <stdio.h>
#include <stdlib.h>

int var_0;
int var_1;
int var_2;

void func_0();

int func_1(int var_3);

int main(int argc, char **argv) {
    int var_4;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d ", &var_4);
    int var_5;
    for (var_5 = 0; var_5 < var_4; var_5++) {
        printf("Case #%d: ", var_5 + 1);
        func_0();
    }
    return 0;
}

void func_0() {
    scanf("%d %d ", &var_1, &var_2);
    int var_6;
    int var_7 = 0;
    var_0 = 0;
    int var_8 = var_1;
    while (var_8 > 0) {
        var_8 = var_8 / 10;
        var_0++;
    }
    for (var_6 = var_1; var_6 <= var_2; var_6++) {
        var_7 = var_7 + func_1(var_6);
    }
    printf("%d\n", var_7);
    return;
    return;
}

int func_1(int var_3) {
    int var_9[10];
    int var_10 = 0;
    int var_11;
    int var_12;

    int var_13 = var_3;
    int var_14 = 1;
    for (var_11 = 0; var_11 < var_0 - 1; var_11++) {
        var_14 = var_14 * 10;
    }
    int var_15 = 0;
    for (var_11 = 0; var_11 < var_0; var_11++) {
        int var_16 = var_13 % 10;
        int var_17 = var_13 / 10;
        var_13 = var_16 * var_14 + var_17;
        if (var_13 > var_3 && var_13 <= var_2) {
            int var_18 = 1;
            for (var_12 = 0; var_12 < var_10 && var_18; var_12++) {
                if (var_13 == var_9[var_12]) {
                    var_18 = 0;
                }
            }
            if (var_18) {
                var_9[var_10] = var_13;
                var_10++;
                var_15++;
            }
        }
    }
    return var_15;
}
