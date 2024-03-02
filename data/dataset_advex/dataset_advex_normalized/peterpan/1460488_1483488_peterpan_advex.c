#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9[10];
    int var_10;
    int var_11;

    char var_12[20];

    scanf("%d", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        scanf("%d", &var_2);
        scanf("%d", &var_3);
        sprintf(var_12, "%d%d", var_2, var_2);
        var_7 = strlen(var_12) / 2;
        var_4 = 0;
        for (var_5 = var_2; var_5 < var_3; var_5++) {
            var_10 = 0;
            for (var_8 = 1; var_8 < var_7; var_8++) {
                var_12[var_8 + var_7] = 0;
                sscanf(var_12 + var_8, "%d", &var_6);
                var_12[var_8 + var_7] = var_12[var_8];
                if (var_5 < var_6 && var_6 <= var_3) {
                    for (var_11 = 0; var_11 < var_10; var_11++) {
                        if (var_9[var_10] == var_6) {
                            break;
                        }
                    }
                    if (var_11 == var_10) {
                        var_9[var_10++] = var_6;
                        var_4++;
                    }
                }
            }
            for (var_8 = var_7 - 1; var_8 >= 0; var_8--) {
                if (var_12[var_8] == '9') {
                    var_12[var_8] = var_12[var_8 + var_7] = '0';
                } else {
                    var_12[var_8]++;
                    var_12[var_8 + var_7]++;
                    break;
                }
            }
        }
        printf("Case #%d: %d\r\n", var_1, var_4);
    }
    return 0;
}
