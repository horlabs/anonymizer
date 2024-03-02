#include <stdbool.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1 = 1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8[17];

    scanf("%d", &var_0);
    while (var_0--) {
        scanf("%d", &var_2);
        for (var_4 = 1; var_4 <= 16; var_4++) {
            var_8[var_4] = false;
        }
        for (var_4 = 0; var_4 < 4; var_4++) {
            for (var_5 = 0; var_5 < 4; var_5++) {
                scanf("%d", &var_7);
                if (var_4 == var_2 - 1) {
                    var_8[var_7] = true;
                }
            }
        }
        scanf("%d", &var_3);
        var_6 = -1;
        for (var_4 = 0; var_4 < 4; var_4++) {
            for (var_5 = 0; var_5 < 4; var_5++) {
                scanf("%d", &var_7);
                if (var_4 == var_3 - 1) {
                    if (var_8[var_7] && var_6 != -1) {
                        var_6 = -2;
                    } else {
                        if (var_8[var_7] && var_6 == -1) {
                            var_6 = var_7;
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", var_1++);
        if (var_6 == -2) {
            printf("Bad Magician!\n");
        } else {
            if (var_6 == -1) {
                printf("Volunteer cheated!\n");
            } else {
                printf("%d\n", var_6);
            }
        }
    }
    return 0;
}
