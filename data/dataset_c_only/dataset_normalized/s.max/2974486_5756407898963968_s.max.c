#include <stdio.h>

void func_0(int *var_0) {
    int var_1;
    int var_2;

    int var_3;
    int var_4;

    scanf("%d", &var_3);
    var_3--;
    for (var_1 = 0; var_1 < 4; var_1++) {
        for (var_2 = 0; var_2 < 4; var_2++) {
            scanf("%d", &var_4);
            if (var_3 == var_1) {
                var_0[var_4]++;
            }
        }
    }
    return;
}

int main(int argc, char **argv) {
    int var_5;
    int var_6;

    scanf("%d", &var_6);
    for (var_5 = 1; var_5 <= var_6; var_5++) {
        int var_7[17] = {0};

        func_0(var_7);
        func_0(var_7);

        int var_8;
        int var_9;
        int var_10 = 0;

        for (var_8 = 1; var_8 <= 16; var_8++) {
            if (var_7[var_8] == 2) {
                var_9 = var_8;
                var_10++;
            }
        }
        printf("Case #%d: ", var_5);
        if (var_10 == 0) {
            printf("Volunteer cheated!");
        }
        if (var_10 == 1) {
            printf("%d", var_9);
        }
        if (var_10 > 1) {
            printf("Bad magician!");
        }
        printf("\n");
    }
    return 0;
}
