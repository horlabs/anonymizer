#include <stdio.h>

void func_0(int var_0[4], int var_1[4]) {
    int var_2;
    int var_3;
    int var_4;
    int var_5 = 0;
    int var_6;
    int var_7;

    for (var_2 = 0; var_2 < 4; var_2++) {
        var_6 = var_0[var_2];
        for (var_3 = 0; var_3 < 4; var_3++) {
            if (var_6 == var_1[var_3]) {
                var_7 = var_6;
                var_5++;
            }
        }
    }
    if (var_5 == 1) {
        printf("%d", var_7);
    }
    if (var_5 > 1) {
        printf("Bad magician!");
    }
    if (var_5 == 0) {
        printf("Volunteer cheated!");
    }
    return;
}

int main(int argc, char **argv) {
    int var_8;
    int var_9;
    int var_10;
    int var_11[4];
    int var_12[4];
    int var_13;
    int var_14;
    int var_15;
    int var_16;
    int var_17;

    scanf("%d", &var_8);
    for (var_13 = 1; var_13 <= var_8; var_13++) {
        scanf("%d", &var_9);
        var_15 = 0;
        for (var_17 = 0; var_17 < 4; var_17++) {
            for (var_14 = 0; var_14 < 4; var_14++) {
                scanf("%d", &var_16);
                if (var_17 == var_9 - 1) {
                    var_11[var_15++] = var_16;
                }
            }
        }
        scanf("%d", &var_9);
        var_15 = 0;
        for (var_17 = 0; var_17 < 4; var_17++) {
            for (var_14 = 0; var_14 < 4; var_14++) {
                scanf("%d", &var_16);
                if (var_17 == var_9 - 1) {
                    var_12[var_15++] = var_16;
                }
            }
        }
        printf("Case #%d: ", var_13);
        func_0(var_11, var_12);
        printf("\n");
    }
    return 0;
}
