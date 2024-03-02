#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    freopen("B-small-attempt0.in", "r", stdin);

    int var_0 = 0;
    int var_1;

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {
        int var_2;
        int var_3;

        int var_4;
        int var_5;

        int var_6[99][99];
        int var_7 = 1;

        scanf("%d %d\n", &var_2, &var_3);

        for (var_4 = 0; var_4 < var_2; var_4++) {
            for (var_5 = 0; var_5 < var_3; var_5++) {
                scanf("%d", &var_6[var_4][var_5]);
            }
            getchar();
        }

        for (var_4 = 0; var_4 < var_2 && var_7 == 1; var_4++) {
            for (var_5 = 0; var_5 < var_3 && var_7 == 1; var_5++) {
                int var_8 = 1;
                int var_9 = 1;
                int var_10;
                int var_11;

                for (var_10 = 0; var_10 < var_2; var_10++) {
                    if (var_6[var_10][var_5] > var_6[var_4][var_5]) {
                        var_8 = 0;
                    }
                }
                for (var_11 = 0; var_11 < var_3; var_11++) {
                    if (var_6[var_4][var_11] > var_6[var_4][var_5]) {
                        var_9 = 0;
                    }
                }
                if (var_8 == 0 && var_9 == 0) {
                    var_7 = 0;
                }
            }
        }

        printf("Case #%d: %s\n", ++var_0, var_7 ? "YES" : "NO");
    }

    return 0;
}
