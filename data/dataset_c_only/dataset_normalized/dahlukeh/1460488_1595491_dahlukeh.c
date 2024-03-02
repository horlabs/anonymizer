#include <stdio.h>
#include <stdlib.h>

int var_0;
int var_1[1000];
int var_2;
int var_3;

void func_0();

int func_1(int var_4);
int func_2(int var_5);

int main(int argc, char **argv) {
    int var_6;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d ", &var_6);
    int var_7;
    for (var_7 = 0; var_7 < var_6; var_7++) {
        printf("Case #%d: ", var_7 + 1);
        func_0();
    }
    return 0;
}

void func_0() {
    scanf("%d %d %d ", &var_0, &var_3, &var_2);
    int var_8;
    for (var_8 = 0; var_8 < var_0; var_8++) {
        scanf("%d ", &var_1[var_8]);
    }
    int var_9 = 0;
    for (var_8 = 0; var_8 < var_0; var_8++) {
        if (func_1(var_1[var_8])) {
            var_9++;
        } else {
            if (var_3 > 0 && func_2(var_1[var_8])) {
                var_9++;
                var_3--;
            }
        }
    }
    printf("%d\n", var_9);
    return;
    return;
}

int func_1(int var_4) {
    int var_10 = var_4 % 3;
    int var_11 = var_4 / 3;
    if (var_10 > 0) {
        var_11++;
    }
    return var_11 >= var_2;
}

int func_2(int var_5) {
    int var_12 = var_5 % 3;
    int var_13 = var_5 / 3;
    if (var_12 == 2) {
        var_13 = var_13 + 2;
    } else {
        if (var_12 == 1 || var_5 > 0) {
            var_13++;
        }
    }
    return var_13 >= var_2;
}
