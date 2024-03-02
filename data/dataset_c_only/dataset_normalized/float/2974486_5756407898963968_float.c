#include <stdio.h>
#include <stdlib.h>

int func_0(const void *var_0, const void *var_1) {
    return *(int *)var_0 - *(int *)var_1;
}

int main(int argc, char **argv) {
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;

    int var_8[8];
    int var_9;
    int var_10;

    scanf("%d", &var_2);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        var_9 = 0;
        scanf("%d", &var_4);
        for (var_5 = 1; var_5 <= 4; var_5++) {
            if (var_5 == var_4) {
                scanf("%d %d %d %d", &var_8[0], &var_8[1], &var_8[2],
                      &var_8[3]);
            } else {
                scanf("%d %d %d %d", &var_6, &var_6, &var_6, &var_6);
            }
        }
        scanf("%d", &var_4);
        for (var_5 = 1; var_5 <= 4; var_5++) {
            if (var_5 == var_4) {
                scanf("%d %d %d %d", &var_8[4], &var_8[5], &var_8[6],
                      &var_8[7]);
            } else {
                scanf("%d %d %d %d", &var_6, &var_6, &var_6, &var_6);
            }
        }
        qsort(var_8, 8, sizeof(int), func_0);
        for (var_7 = 1; var_7 < 8; var_7++) {
            if (var_8[var_7] == var_8[var_7 - 1]) {
                var_9++;
                var_10 = var_8[var_7];
            }
        }
        printf("Case #%d: ", var_3);
        if (var_9 == 1) {
            printf("%d\n", var_10);
        } else if (var_9 == 0) {
            printf("Volunteer cheated!\n");
        } else {
            printf("Bad magician!\n");
        }
    }
    return 0;
}
