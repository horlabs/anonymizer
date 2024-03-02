#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *func_0(char *, int);

int main(int argc, char **argv) {
    char var_0[10];
    char *var_1;

    int var_2;
    int var_3;
    int var_4;
    int var_5;
    int var_6 = 0;

    long long var_7;
    long long var_8;
    long long var_9;

    FILE *var_10;
    FILE *var_11;

    var_10 = fopen("C-small-attempt0.in", "r");
    if (var_10 == NULL) {
        printf("ERROR");
    } else {
        fscanf(var_10, "%d", &var_2);
        for (var_3 = 0; var_3 < var_2; var_3++) {
            var_6 = 0;
            fscanf(var_10, "%ld%ld", &var_7, &var_8);
            for (var_9 = var_7; var_9 < var_8; var_9++) {
                itoa(var_9, var_0, 10);
                for (var_4 = 0; var_4 < strlen(var_0) - 1; var_4++) {
                    var_1 = func_0(&var_0[0], strlen(var_0));
                    var_5 = atoi(var_1);
                    if (var_5 > var_9 && var_5 <= var_8) {
                        var_6++;
                    }
                }
            }
            var_11 = fopen("out3.txt", "a");
            fprintf(var_11, "Case #%d: %d\n", var_3 + 1, var_6);
        }
    }
    return 0;
}

char *func_0(char *var_12, int var_13) {
    char var_14;
    int var_15;
    var_14 = *(var_12 + var_13 - 1);
    for (var_15 = var_13 - 1; var_15 > 0; var_15--) {
        *(var_12 + var_15) = *(var_12 + var_15 - 1);
    }
    *var_12 = var_14;
    return var_12;
}
