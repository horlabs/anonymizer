#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8[4];

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        var_7 = 0;
        scanf("%d", &var_2);
        for (var_3 = 1; var_3 <= 4; var_3++) {
            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_3 == var_2) {
                    scanf("%d", &var_8[var_4]);
                } else {
                    scanf("%*d");
                }
            }
        }
        scanf("%d", &var_2);
        for (var_3 = 1; var_3 <= 4; var_3++) {
            for (var_4 = 0; var_4 < 4; var_4++) {
                if (var_3 == var_2) {
                    scanf("%d", &var_6);
                    for (var_5 = 0; var_5 < 4; var_5++) {
                        if (var_8[var_5] == var_6) {
                            if (var_7 == 0) {
                                var_7 = var_6;
                            } else {
                                var_7 = -1;
                            }
                            break;
                        }
                    }
                } else {
                    scanf("%*d");
                }
            }
        }
        printf("Case #%d: ", var_1);
        if (var_7 == 0) {
            puts("Volunteer cheated!");
        } else {
            if (var_7 == -1) {
                puts("Bad magician!");
            } else {
                printf("%d\n", var_7);
            }
        }
    }
    return 0;
}
