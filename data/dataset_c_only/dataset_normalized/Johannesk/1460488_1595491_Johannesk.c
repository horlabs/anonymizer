#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int var_0, char **var_1) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;

    int var_10[101];
    char var_11[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,  5,  5, 5,
                     6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
    char var_12[] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,  5,  5,  5,  6, 6,
                     6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 10};

    assert(scanf("%d ", &var_2) == 1);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        assert(scanf("%d %d %d", &var_5, &var_6, &var_7) == 3);
        for (var_4 = 0; var_4 < var_5; var_4++) {
            assert(scanf("%d", &var_10[var_4]) == 1);
        }
        var_8 = 0;
        for (var_4 = 0; var_4 < var_5; var_4++) {
            var_9 = var_10[var_4];
            if (var_11[var_9] >= var_7) {
                var_8++;
            } else {
                if ((var_12[var_9] >= var_7) && (var_6 > 0)) {
                    var_8++;
                    var_6--;
                }
            }
        }
        printf("Case #%d: %d\n", var_3, var_8);
    }
    return 0;
}
