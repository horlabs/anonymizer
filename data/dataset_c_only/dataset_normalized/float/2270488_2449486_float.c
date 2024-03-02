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

    int var_8[128][128];
    scanf("%d", &var_1);
    for (var_0 = 1; var_0 <= var_1; var_0++) {
        scanf("%d %d", &var_2, &var_3);
        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                scanf("%d", &var_8[var_4][var_5]);
            }
        }

        var_7 = 0;
        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                var_7 = 0;
                for (var_6 = 0; var_6 < var_2; var_6++) {
                    if (var_8[var_6][var_5] > var_8[var_4][var_5]) {
                        var_7++;
                        break;
                    }
                }
                for (var_6 = 0; var_6 < var_3; var_6++) {
                    if (var_8[var_4][var_6] > var_8[var_4][var_5]) {
                        var_7++;
                        break;
                    }
                }
                if (var_7 >= 2) {
                    goto CHECK_END;
                }
            }
        }
    CHECK_END:
        if (var_4 == var_2 && var_5 == var_3) {
            printf("Case #%d: YES\n", var_0);
        } else {
            printf("Case #%d: NO\n", var_0);
        }
    }
    return 0;
}
