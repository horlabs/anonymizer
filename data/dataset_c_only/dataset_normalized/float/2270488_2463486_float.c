#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0[1024];
    int var_1[1024];

    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    memset(var_0, sizeof var_0, 0);
    memset(var_1, sizeof var_1, 0);
    var_0[1] = 1;
    var_0[4] = 1;
    var_0[9] = 1;
    var_0[121] = 1;
    var_0[484] = 1;
    for (var_4 = 1; var_4 < 1024; var_4++) {
        var_1[var_4] = var_1[var_4 - 1] + var_0[var_4];
    }
    scanf("%d", &var_2);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        scanf("%d %d", &var_5, &var_6);
        printf("Case #%d: %d\n", var_3, var_1[var_6] - var_1[var_5 - 1]);
    }
    return 0;
}
