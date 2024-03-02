#include <math.h>
#include <stdio.h>

typedef long long ll;
int func_0(long long var_0) {
    int var_1[20];
    int var_2;
    int var_3;
    int var_4;

    for (var_2 = 0; var_0 > 0; var_2++, var_0 = var_0 / 10) {
        var_1[var_2] = var_0 % 10;
    }
    for (var_2--, var_3 = 0; var_2 > var_3; var_2--, var_3++) {
        if (var_1[var_2] != var_1[var_3]) {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char **argv) {
    freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
    freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);

    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;
    int var_10;
    int var_11;
    int var_12;

    scanf("%d", &var_9);
    for (var_8 = 1; var_8 <= var_9; var_8++) {
        scanf("%d %d", &var_10, &var_11);
        var_12 = sqrt(var_11);
        for (var_5 = sqrt(var_10), var_7 = 0; var_5 <= var_12; var_5++) {
            if (func_0(var_5)) {
                var_6 = var_5 * var_5;
                if ((var_6 >= var_10) && (var_6 <= var_11) && func_0(var_6)) {
                    var_7++;
                }
            }
        }
        printf("Case #%d: %d\n", var_8, var_7);
    }
    return 0;
}
