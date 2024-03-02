#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func_0(int var_0) {
    int var_1;
    int var_2;

    int var_3[100][100];
    int var_4;
    int var_5;

    int var_6 = 1;

    scanf("%d%d", &var_1, &var_2);

    for (var_4 = 0; var_4 < var_1; var_4++) {
        for (var_5 = 0; var_5 < var_2; var_5++) {
            scanf("%d", &var_3[var_4][var_5]);
        }
    }

    for (var_4 = 0; var_4 < var_1; var_4++) {
        for (var_5 = 0; var_5 < var_2; var_5++) {
            int var_7;

            for (var_7 = 0; var_7 < var_1; var_7++) {
                if (var_3[var_4][var_5] < var_3[var_7][var_5]) {

                    int var_8;

                    for (var_8 = 0; var_8 < var_2; var_8++) {
                        if (var_3[var_4][var_5] < var_3[var_4][var_8]) {
                            goto done;
                        }
                    }
                    break;
                }
            }
        }
    }

    var_6 = 0;
done:

    printf("Case #%d: %s\n", var_0 + 1, var_6 ? "NO" : "YES");
    return;
}

int main(int argc, char **argv) {
    int var_9;
    int var_10;

    scanf("%d", &var_9);

    for (var_10 = 0; var_10 < var_9; var_10++) {
        func_0(var_10);
    }

    return 0;
}
