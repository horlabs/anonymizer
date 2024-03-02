#include <limits.h>
#include <stdio.h>

const int var_0[] = {
    1,       2,       3,       11,      22,      101,     111,     121,
    202,     212,     1001,    1111,    2002,    10001,   10101,   10201,
    11011,   11111,   11211,   20002,   20102,   100001,  101101,  110011,
    111111,  200002,  1000001, 1001001, 1002001, 1010101, 1011101, 1012101,
    1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002};

long long var_1[100];

int func_0(long long var_2) {
    int var_3;
    for (var_3 = 0; var_3 <= sizeof var_0 / sizeof(int); var_3++) {
        if (var_1[var_3] > var_2) {
            return var_3 - 1;
        }
    }
    return sizeof var_0 / sizeof(int);
}

int main(int argc, char **argv) {
    int var_4;
    int var_5 = 0;

    int var_6;
    for (var_6 = 0; var_6 < sizeof var_0 / sizeof(int); var_6++) {
        var_1[var_6] = (long long)var_0[var_6] * var_0[var_6];
    }
    var_1[var_6] = LLONG_MAX;
    for (scanf("%d", &var_4); var_4; var_4--) {
        long long var_7;
        long long var_8;

        scanf("%lld%lld", &var_7, &var_8);
        printf("Case #%d: %d\n", ++var_5, func_0(var_8) - func_0(var_7 - 1));
    }
    return 0;
}
