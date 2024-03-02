#include <stdio.h>
#include <string.h>

typedef long long ll;

long long var_0[1000000];
int var_1;

void func_0() {
    char var_2[20];
    char var_3[20];

    int var_4;
    int var_5;
    int var_6;

    var_1 = 0;
    for (var_4 = 1; var_4 < 10000001; var_4++) {
        sprintf(var_2, "%d", var_4);
        var_6 = strlen(var_2);
        for (var_5 = 0; var_5 + var_5 < var_6; var_5++) {
            if (var_2[var_5] != var_2[var_6 - var_5 - 1]) {
                goto fail;
            }
        }
        sprintf(var_3, "%I64d", (long long)var_4 * var_4);
        var_6 = strlen(var_3);
        for (var_5 = 0; var_5 + var_5 < var_6; var_5++) {
            if (var_3[var_5] != var_3[var_6 - var_5 - 1]) {
                goto fail;
            }
        }
        var_0[var_1++] = (long long)var_4 * var_4;
    fail:;
    }
    return;
}

int main(int argc, char **argv) {
    int var_7;
    int var_8;
    int var_9;
    int var_10 = 1;
    int var_11;
    int var_12;

    func_0();
    scanf("%d", &var_7);
    while (var_7--) {
        scanf("%d %d", &var_8, &var_9);
        for (var_12 = var_11 = 0; var_11 < var_1; var_11++) {
            if (var_8 <= var_0[var_11] && var_0[var_11] <= var_9) {
                var_12++;
            }
        }
        printf("Case #%d: %d\n", var_10++, var_12);
    }
    return 0;
}
