#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    scanf("%d", &var_0);
    for (int var_1 = 1; var_1 <= var_0; var_1++) {
        char var_2[17] = {0};
        for (int var_3 = 0; var_3 < 2; var_3++) {
            int var_4;
            scanf("%d", &var_4);
            for (int var_5 = 1; var_5 <= 4; var_5++) {
                for (int var_6 = 0; var_6 < 4; var_6++) {
                    int var_7;
                    scanf("%d", &var_7);
                    if (var_5 == var_4) {
                        var_2[var_7]++;
                    }
                }
            }
        }
        int var_8 = 0;
        int var_9 = 0;
        for (int var_10 = 1; var_10 <= 16; var_10++) {
            if (var_2[var_10] == 2) {
                var_9 = var_10;
                var_8++;
            }
        }
        printf("Case #%d: ", var_1);
        if (var_8 == 0) {
            printf("Volunteer cheated!");
        } else {
            if (var_8 >= 2) {
                printf("Bad magician!");
            } else {
                printf("%d", var_9);
            }
        }
        printf("\n");
    }
    return 0;
}
