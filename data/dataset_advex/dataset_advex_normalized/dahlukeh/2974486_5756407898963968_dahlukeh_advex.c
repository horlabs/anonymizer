#include <stdio.h>

int var_0;
int var_1[101][101];

int var_2[101];
int var_3[101];

void func_0(int *var_4) {
    int var_5;
    for (var_5 = 1; var_5 <= 16; var_5++) {
        var_4[var_5] = 0;
    }
    for (var_5 = 0; var_5 < 4; var_5++) {
        var_4[var_1[var_0 - 1][var_5]] = 1;
    }
    return;
}

void func_1() {
    int var_6;
    int var_7;

    scanf("%d ", &var_0);
    for (var_6 = 0; var_6 < 4; var_6++) {
        for (var_7 = 0; var_7 < 4; var_7++) {
            scanf("%d ", &var_1[var_6][var_7]);
        }
    }
    func_0(var_2);
    scanf("%d ", &var_0);
    for (var_6 = 0; var_6 < 4; var_6++) {
        for (var_7 = 0; var_7 < 4; var_7++) {
            scanf("%d ", &var_1[var_6][var_7]);
        }
    }
    func_0(var_3);
    int var_8 = 0;
    int var_9 = 0;
    int var_10 = 0;
    for (var_6 = 1; var_6 <= 16; var_6++) {
        if (var_2[var_6] && var_3[var_6]) {
            if (var_8) {
                var_9 = 1;
            }
            var_8 = 1;
            var_10 = var_6;
        }
    }
    if (!var_8) {
        printf("Volunteer cheated!\n");
    } else {
        if (var_9) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", var_10);
        }
    }
    return;
}

int main(int argc, char **argv) {
    int var_11;
    int var_12;

    scanf("%d ", &var_11);
    for (var_12 = 0; var_12 < var_11; var_12++) {
        printf("Case #%d: ", var_12 + 1);
        func_1();
    }
    return 0;
}
