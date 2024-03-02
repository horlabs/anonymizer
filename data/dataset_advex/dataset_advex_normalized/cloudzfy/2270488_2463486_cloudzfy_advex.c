#include <math.h>
#include <stdio.h>
#include <string.h>
int var_0[10000001];
void func_0() {
    int var_1[20];
    int var_2;
    int var_3;

    long long var_4;
    freopen("C-small-attempt0.in.txt", "r", stdin);
    freopen("C-small-attempt0.out.txt", "w", stdout);
    memset(var_0, 0, sizeof var_0);
    for (int var_5 = 0; var_5 < 10000001; var_5++) {
        var_4 = var_5 * var_5;
        var_2 = 0;
        while (var_4 != 0) {
            var_1[var_2] = var_4 % 10;
            var_4 = var_4 / 10;
            var_2++;
        }
        var_3 = 1;
        for (int var_6 = 0; var_6 < var_2; var_6++) {
            if (var_1[var_6] != var_1[var_2 - var_6 - 1]) {
                var_3 = 0;
                break;
            }
        }
        var_4 = var_5;
        var_2 = 0;
        while (var_4 != 0) {
            var_1[var_2] = var_4 % 10;
            var_4 = var_4 / 10;
            var_2++;
        }
        for (int var_7 = 0; var_7 < var_2; var_7++) {
            if (var_1[var_7] != var_1[var_2 - var_7 - 1]) {
                var_3 = 0;
                break;
            }
        }
        if (var_3) {
            var_0[var_5] = 1;
        }
    }
    for (int var_8 = 1; var_8 < 10000001; var_8++) {
        var_0[var_8] = var_0[var_8 - 1] + var_0[var_8];
    }
    return;
}
int main(int argc, char **argv) {
    long long var_9;
    long long var_10;

    int var_11;

    func_0();
    scanf("%d", &var_11);
    for (int var_12 = 1; var_12 <= var_11; var_12++) {
        scanf("%lld%lld", &var_9, &var_10);
        int var_13 = (int)sqrt(var_9);
        int var_14 = (int)sqrt(var_10);
        if (var_13 * var_13 == var_9) {
            var_13--;
        }
        printf("Case #%d: %d\n", var_12, var_0[var_14] - var_0[var_13]);
    }
    return 0;
}
