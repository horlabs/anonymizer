#include <stdio.h>
#include <stdlib.h>

void func_0();

int var_0;
int var_1;

int var_2[100][100];

int func_1(int var_3, int var_4);

int main(int argc, char **argv) {
    freopen("bin.txt", "r", stdin);
    freopen("bout.txt", "w", stdout);
    int var_5;
    scanf("%d ", &var_5);
    int var_6;
    for (var_6 = 0; var_6 < var_5; var_6++) {
        printf("Case #%d: ", var_6 + 1);
        func_0();
    }
    return 0;
}

void func_0() {
    int var_7;
    int var_8;

    scanf("%d %d ", &var_0, &var_1);
    for (var_7 = 0; var_7 < var_0; var_7++) {
        for (var_8 = 0; var_8 < var_1; var_8++) {
            scanf("%d ", &var_2[var_7][var_8]);
        }
    }
    for (var_7 = 0; var_7 < var_0; var_7++) {
        for (var_8 = 0; var_8 < var_1; var_8++) {
            if (!func_1(var_7, var_8)) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    return;
    return;
}

int func_1(int var_3, int var_4) {
    int var_9 = var_2[var_3][var_4];
    int var_10;
    int var_11 = 1;
    for (var_10 = 0; var_10 < var_0 && var_11; var_10++) {
        if (var_2[var_10][var_4] > var_9) {
            var_11 = 0;
        }
    }
    if (var_11) {
        return 1;
    } else {
        var_11 = 1;
        for (var_10 = 0; var_10 < var_1 && var_11; var_10++) {
            if (var_2[var_3][var_10] > var_9) {
                var_11 = 0;
            }
        }
        return var_11;
    }
}
