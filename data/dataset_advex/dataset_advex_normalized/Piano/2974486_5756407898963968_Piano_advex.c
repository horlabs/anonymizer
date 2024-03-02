#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; ++var_1) {
        int var_2;
        int var_3;
        int var_4;
        int var_5;
        int var_6;
        int var_7;
        int var_8;

        int var_9[17] = {};
        scanf("%d", &var_2);
        for (var_7 = 1; var_7 <= 4; ++var_7) {
            if (var_7 != var_2) {
                scanf("%*d%*d%*d%*d");
            } else {
                scanf("%d%d%d%d", &var_3, &var_4, &var_5, &var_6);
                var_9[var_3] = var_9[var_4] = var_9[var_5] = var_9[var_6] = 1;
            }
        }
        scanf("%d", &var_2);
        for (var_7 = 1; var_7 <= 4; ++var_7) {
            if (var_7 != var_2) {
                scanf("%*d%*d%*d%*d");
            } else {
                int var_10;
                int var_11 = 0;

                for (var_8 = 0; var_8 < 4; ++var_8) {
                    scanf("%d", &var_3);
                    if (var_9[var_3]) {
                        ++var_11;
                        var_10 = var_3;
                    }
                }
                if (!var_11) {
                    printf("Case #%d: Volunteer cheated!\n", var_1);
                } else {
                    if (var_11 == 1) {
                        printf("Case #%d: %d\n", var_1, var_10);
                    } else {
                        printf("Case #%d: Bad magician!\n", var_1);
                    }
                }
            }
        }
    }
    return 0;
}
