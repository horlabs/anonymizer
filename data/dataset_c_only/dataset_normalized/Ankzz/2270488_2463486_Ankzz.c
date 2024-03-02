#include <math.h>
#include <stdio.h>
short func_0(long long var_0) {
    long long var_1;
    long long var_2 = 0;

    var_1 = var_0;
    while (var_1 != 0) {
        var_2 = var_2 * 10;
        var_2 = var_2 + var_1 % 10;
        var_1 = var_1 / 10;
    }
    return var_0 == var_2;
}

int func_1(int var_3) {
    int var_4 = var_3 & 0xF;
    if (var_4 > 9) {
        return 0;
    } else {
        if (var_4 != 2 && var_4 != 3 && var_4 != 5 && var_4 != 6 &&
            var_4 != 7 && var_4 != 8) {
            int var_5 = (int)floor(sqrt((double)var_3) + 0.5);
            return (var_5 * var_5 == var_3) && func_0(var_5);
        } else {
            return 0;
        }
    }
}

int main(int argc, char **argv) {
    int var_6 = -1;
    int var_7 = 0;

    FILE *var_8 = fopen("C-small-attempt0.in", "r");

    FILE *var_9 = fopen("output.txt", "w");

    fscanf(var_8, "%d", &var_6);

    while (++var_7 <= var_6) {
        unsigned long long var_10 = 0;
        unsigned long long var_11 = 0;

        int var_12 = 0;
        fscanf(var_8, "%ld %ld", &var_10, &var_11);
        while (var_10 <= var_11) {
            if (func_0(var_10) && func_1(var_10)) {
                var_12++;
            }
            var_10++;
        }
        fprintf(var_9, "Case #%d: %d\n", var_7, var_12);
    }

    fclose(var_8);
    fclose(var_9);
    return 0;
}
