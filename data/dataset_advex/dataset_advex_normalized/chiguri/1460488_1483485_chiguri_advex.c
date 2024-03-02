#include <stdio.h>

const char var_0[] = {121, 104, 101, 115, 111, 99,  118, 120, 100,
                      117, 105, 103, 108, 98,  107, 114, 122, 116,
                      110, 119, 106, 112, 102, 109, 97,  113};

int main(int argc, char **argvvoid) {
    int var_1;
    char var_2[102];
    int var_3;
    int var_4;

    fgets(var_2, 10, stdin);
    sscanf(var_2, "%d", &var_1);
    for (var_3 = 1; var_3 <= var_1; ++var_3) {
        gets(var_2);
        for (var_4 = 0; var_2[var_4] != '\n' && var_2[var_4] != '\0'; ++var_4) {
            if (var_2[var_4] == ' ') {
                continue;
            } else {
                var_2[var_4] = var_0[var_2[var_4] - 'a'];
            }
        }
        var_2[var_4] = '\0';
        printf("Case #%d: %s\n", var_3, var_2);
    }

    return 0;
}
