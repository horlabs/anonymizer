#include <assert.h>
#include <stdio.h>
#include <string.h>

void func_0(int var_0, int *var_1, int *var_2) {
    int var_3;
    int var_4;

    char var_5;
    char var_6;

    var_6 = 0;
    for (var_3 = 0; var_3 < 4; var_3++) {
        for (var_4 = 0; var_4 < 4; var_4++) {

            if (var_1[var_3] == var_2[var_4]) {
                var_6++;
                var_5 = var_1[var_3];
            }
        }
    }
    if (var_6 == 1) {
        printf("Case #%d: %d\n", var_0, var_5);
    }
    if (var_6 == 0) {
        printf("Case #%d: Volunteer cheated!\n", var_0);
    }
    if (var_6 > 1) {
        printf("Case #%d: Bad magician!\n", var_0);
    }
    return;
}

int main(int var_7, char **var_8) {
    int var_9;
    int var_10;

    int var_11[4][4];
    int var_12[4][4];
    int var_13;
    int var_14;

    assert(scanf("%d ", &var_9) == 1);
    for (var_10 = 1; var_10 <= var_9; var_10++) {
        assert(scanf("%d ", &var_13) == 1);
        assert(scanf("%d%d%d%d ", &var_11[0][0], &var_11[0][1], &var_11[0][2],
                     &var_11[0][3]) == 4);
        assert(scanf("%d%d%d%d ", &var_11[1][0], &var_11[1][1], &var_11[1][2],
                     &var_11[1][3]) == 4);
        assert(scanf("%d%d%d%d ", &var_11[2][0], &var_11[2][1], &var_11[2][2],
                     &var_11[2][3]) == 4);
        assert(scanf("%d%d%d%d ", &var_11[3][0], &var_11[3][1], &var_11[3][2],
                     &var_11[3][3]) == 4);

        assert(scanf("%d ", &var_14) == 1);
        assert(scanf("%d%d%d%d ", &var_12[0][0], &var_12[0][1], &var_12[0][2],
                     &var_12[0][3]) == 4);
        assert(scanf("%d%d%d%d ", &var_12[1][0], &var_12[1][1], &var_12[1][2],
                     &var_12[1][3]) == 4);
        assert(scanf("%d%d%d%d ", &var_12[2][0], &var_12[2][1], &var_12[2][2],
                     &var_12[2][3]) == 4);
        assert(scanf("%d%d%d%d ", &var_12[3][0], &var_12[3][1], &var_12[3][2],
                     &var_12[3][3]) == 4);

        func_0(var_10, var_11[var_13 - 1], var_12[var_14 - 1]);
    }
    return 0;
}
