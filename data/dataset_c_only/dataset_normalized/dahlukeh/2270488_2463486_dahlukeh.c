#include <stdio.h>
#include <stdlib.h>

void func_0();

long long var_0;
long long var_1;

char var_2[200];

long long func_1(long long var_3);

int func_2(long long var_4);
long long func_3(long long var_5, int var_6);
void func_4(long long var_7, char *var_8);
long long func_5(char *var_9);

int func_6(long long var_10);

int main(int argc, char **argv) {
    freopen("cin.txt", "r", stdin);
    freopen("cout.txt", "w", stdout);
    int var_11;
    scanf("%d ", &var_11);
    int var_12;
    for (var_12 = 0; var_12 < var_11; var_12++) {
        printf("Case #%d: ", var_12 + 1);
        func_0();
    }
    return 0;
}

void func_0() {
    scanf("%I64d %I64d ", &var_0, &var_1);
    long long var_13 = func_1(var_1) - func_1(var_0 - 1);
    printf("%I64d\n", var_13);
    return;
    return;
}

long long func_1(long long var_3) {
    long long var_14;
    long long var_15 = 0ll;
    int var_16;
    int var_17;

    for (var_16 = 1;; var_16++) {
        var_14 = 1ll;
        for (var_17 = 0; var_17 < ((var_16 - 1) / 2); var_17++) {
            var_14 = var_14 * 10LL;
        }
        long long var_18 = var_14 * 10ll;
        for (; var_14 < var_18; var_14++) {
            long long var_19 = func_3(var_14, var_16);
            if (var_19 * var_19 > var_3) {
                return var_15;
            } else {
                if (func_6(var_19 * var_19)) {
                    var_15++;
                }
            }
        }
    }
    return var_15;
}

long long func_3(long long var_5, int var_6) {
    func_4(var_5, var_2);
    int var_20;
    for (var_20 = var_6 - 1; var_20 >= 0; var_20--) {
        var_2[var_20] = var_2[var_6 - var_20 - 1];
    }
    var_2[var_6] = '\0';
    return func_5(var_2);
}

int func_6(long long var_10) {
    func_4(var_10, var_2);
    int var_21 = func_2(var_10);
    int var_22;
    for (var_22 = 0; var_22 < var_21; var_22++) {
        if (var_2[var_22] != var_2[var_21 - var_22 - 1]) {
            return 0;
        }
    }
    return 1;
}

int func_2(long long var_4) {
    int var_23 = 1;
    long long var_24 = 10ll;
    for (; var_24 <= var_4; var_23++) {
        var_24 = var_24 * 10LL;
    }
    return var_23;
}

void func_4(long long var_7, char *var_8) {
    int var_25 = func_2(var_7);
    int var_26;
    var_8[var_25] = '\0';
    for (var_26 = 0; var_26 < var_25; var_26++) {
        char var_27 = (var_7 % 10ll) + '0';
        var_8[var_25 - var_26 - 1] = var_27;
        var_7 = var_7 / 10LL;
    }
    return;
    return;
}

long long func_5(char *var_9) {
    long long var_28 = 0ll;
    int var_29;
    for (var_29 = 0; var_9[var_29] != '\0'; var_29++) {
        var_28 = var_28 * 10LL;
        var_28 = var_28 + (var_9[var_29] - '0');
    }
    return var_28;
}
