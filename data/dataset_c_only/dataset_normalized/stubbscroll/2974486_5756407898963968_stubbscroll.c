#include <stdio.h>

int var_0[4][4];
int var_1[4][4];
int var_2;
int var_3;

void func_0() {
    int var_4;
    int var_5;
    int var_6 = -1;
    int var_7;

    scanf("%d", &var_2);
    for (var_4 = 0; var_4 < 4; var_4++) {
        for (var_5 = 0; var_5 < 4; var_5++) {
            scanf("%d", &var_0[var_4][var_5]);
        }
    }
    scanf("%d", &var_3);
    for (var_4 = 0; var_4 < 4; var_4++) {
        for (var_5 = 0; var_5 < 4; var_5++) {
            scanf("%d", &var_1[var_4][var_5]);
        }
    }
    for (var_7 = 1; var_7 < 17; var_7++) {
        for (var_4 = 0; var_4 < 4; var_4++) {
            if (var_0[var_2 - 1][var_4] == var_7) {
                goto next;
            }
        }
        continue;
    next:
        for (var_4 = 0; var_4 < 4; var_4++) {
            if (var_1[var_3 - 1][var_4] == var_7) {
                goto next2;
            }
        }
        continue;
    next2:
        if (var_6 > -1) {
            puts("Bad magician!");
            return;
        }
        var_6 = var_7;
    }
    if (var_6 < 0) {
        puts("Volunteer cheated!");
    } else {
        printf("%d\n", var_6);
    }
    return;
}

int main(int argc, char **argv) {
    int var_8;
    int var_9 = 1;

    scanf("%d", &var_8);
    while (var_8--) {
        printf("Case #%d: ", var_9++);
        func_0();
    }
    return 0;
}
