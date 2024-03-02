#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_0;
int var_1;
int var_2;
int var_3;
int var_4;
int var_5;
int var_6[10] = {1, 4, 9, 121, 484, 1200};

int main(int argc, char **argv) {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        printf("Case #%d: ", var_1);
        scanf("%d%d", &var_2, &var_3);
        for (var_4 = 0; var_6[var_4] < var_2; var_4++) {
            ;
        }
        for (var_5 = var_4; var_6[var_5] <= var_3; var_5++) {
            ;
        }
        printf("%d\n", var_5 - var_4);
    }

    return 0;
}
