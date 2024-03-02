#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long func_0(long long var_0) {
    long long var_1;

    for (var_1 = 1; var_0 >= 10; var_0 = var_0 / 10, var_1 = var_1 * 10) {
        ;
    }
    return var_1;
}

long long func_1(long long var_2, long long var_3) {
    return var_2 / 10 + var_3 * (var_2 % 10);
}

long long func_2(long long var_4, long long var_5, long long var_6) {
    const long long var_7 = func_0(var_4);
    long long var_8 = 0;
    long long var_9;

    for (var_9 = func_1(var_6, var_7); var_9 != var_6;
         var_9 = func_1(var_9, var_7)) {
        if (var_9 <= var_5 && var_9 > var_6) {
            var_8++;
            fprintf(stderr, "(%ld, %ld)\n", var_6, var_9);
        }
    }

    return var_8;
}
void func_3(int var_10) {
    long long var_11;
    long long var_12;
    long long var_13;

    long long var_14 = 0;

    scanf("%ld %ld", &var_11, &var_12);

    for (var_13 = var_11; var_13 <= var_12; var_13++) {
        var_14 = var_14 + func_2(var_11, var_12, var_13);
    }

    printf("Case #%d: %ld\n", var_10 + 1, var_14);
    return;
}

int main(int argc, char **argv) {
    int var_15;
    int var_16;

    scanf("%d", &var_15);

    for (var_16 = 0; var_16 < var_15; var_16++) {
        func_3(var_16);
    }

    return 0;
}
