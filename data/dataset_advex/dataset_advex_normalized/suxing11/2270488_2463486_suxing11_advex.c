#include <stdio.h>

long long var_0[41] = {
    0LL,       1LL,       2LL,       3LL,       11LL,      22LL,      101LL,
    111LL,     121LL,     202LL,     212LL,     1001LL,    1111LL,    2002LL,
    10001LL,   10101LL,   10201LL,   11011LL,   11111LL,   11211LL,   20002LL,
    20102LL,   100001LL,  101101LL,  110011LL,  111111LL,  200002LL,  1000001LL,
    1001001LL, 1002001LL, 1010101LL, 1011101LL, 1012101LL, 1100011LL, 1101011LL,
    1102011LL, 1110111LL, 1111111LL, 2000002LL, 2001002LL, 10000001LL};

int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;
    int var_4 = 1;

    long long var_5;
    long long var_6;

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C_out.txt", "w", stdout);
    for (var_1 = 0; var_1 < 41; var_1++) {
        var_0[var_1] = var_0[var_1] * var_0[var_1];
    }
    scanf("%d", &var_2);
    while (var_2--) {
        scanf("%I64d%I64d", &var_5, &var_6);
        var_3 = 0;
        for (var_1 = 0; var_1 < 41; var_1++) {
            if (var_0[var_1] >= var_5 && var_0[var_1] <= var_6) {
                var_3++;
            }
        }
        printf("Case #%d: %d\n", var_4++, var_3);
    }
    return 0;
}
