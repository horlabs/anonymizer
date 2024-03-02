#include <assert.h>
#include <stdio.h>
#include <string.h>

char var_0[100][100];

int func_0(int var_1, int var_2) {
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    for (var_3 = 0; var_3 < var_1; var_3++) {
        var_6 = 0;
        for (var_4 = 0; var_4 < var_2; var_4++) {
            if (var_0[var_3][var_4] > var_6) {
                var_6 = var_0[var_3][var_4];
            }
        }
        for (var_4 = 0; var_4 < var_2; var_4++) {
            if (var_0[var_3][var_4] < var_6) {

                for (var_5 = 0; var_5 < var_1; var_5++) {
                    if (var_0[var_5][var_4] > var_0[var_3][var_4]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void func_1(int var_7, int var_8) {
    int var_9;
    int var_10;

    for (var_9 = 0; var_9 < var_7; var_9++) {
        for (var_10 = 0; var_10 < var_8; var_10++) {
            printf("%c", var_0[var_9][var_10]);
        }
        printf("\n");
    }
    return;
}

int main(int var_11, char **var_12) {
    int var_13;
    int var_14;
    int var_15;
    int var_16;
    int var_17;
    int var_18;

    char var_19[10];

    assert(scanf("%d ", &var_13) == 1);
    for (var_14 = 1; var_14 <= var_13; var_14++) {
        assert(scanf("%d %d ", &var_15, &var_16) == 2);
        for (var_17 = 0; var_17 < var_15; var_17++) {
            for (var_18 = 0; var_18 < var_16; var_18++) {
                assert(scanf("%c ", &var_0[var_17][var_18]) == 1);
            }
        }

        if (func_0(var_15, var_16) == 1) {
            printf("Case #%d: YES\n", var_14);
        } else {
            printf("Case #%d: NO\n", var_14);
        }
    }
    return 0;
}
