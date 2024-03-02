#include <stdio.h>

int var_0[26] = {24, 7,  4,  18, 14, 2,  21, 23, 3,  20, 8,  6, 11,
                 1,  10, 17, 25, 19, 13, 22, 9,  15, 5,  12, 0, 16};
char var_1[200];
int main(int argc, char **argv) {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int var_2;
    int var_3;
    int var_4;

    scanf("%d", &var_3);
    getchar();
    for (var_2 = 1; var_2 <= var_3; var_2++) {
        gets(var_1);
        for (var_4 = 0; var_1[var_4] != 0; var_4++) {
            if (var_1[var_4] == ' ') {
                continue;
            } else {
                var_1[var_4] = var_0[var_1[var_4] - 'a'] + 'a';
            }
        }
        printf("Case #%d: %s\n", var_2, var_1);
    }
    return 0;
}
