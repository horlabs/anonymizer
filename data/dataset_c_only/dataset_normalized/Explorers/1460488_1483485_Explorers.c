#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;

    char var_4[30][105];
    char var_5[30][105];
    int var_6[] = {25, 8,  5,  19, 15, 3,  22, 24, 4,  21, 9,  7, 12,
                   2,  11, 18, 26, 20, 14, 23, 10, 16, 6,  13, 1, 17};

    scanf("%d ", &var_0);
    for (var_1 = 0; var_1 < var_0; var_1++) {
        gets(var_4[var_1]);
        var_3 = strlen(var_4[var_1]);
        for (var_2 = 0; var_2 < var_3; var_2++) {
            if (var_4[var_1][var_2] == ' ') {
                continue;
            } else {
                var_4[var_1][var_2] = 96 + var_6[var_4[var_1][var_2] - 'a'];
            }
        }
    }

    for (var_1 = 0; var_1 < var_0; var_1++) {
        printf("Case #%d: ", var_1 + 1);
        puts(var_4[var_1]);
    }
    return 0;
}
