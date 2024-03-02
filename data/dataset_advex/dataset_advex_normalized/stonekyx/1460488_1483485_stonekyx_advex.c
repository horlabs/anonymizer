#include <ctype.h>
#include <stdio.h>
#include <string.h>
const char var_0[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                        'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                        'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main(int argc, char **argv) {
    int var_1;
    int var_2 = 0;
    for (scanf("%d\n", &var_1); var_1; var_1--, var_2++) {
        static char var_3[200];
        int var_4 = 0;
        int var_5 = 0;
        fgets(var_3, 200, stdin);
        var_4 = strlen(var_3);
        while (var_4 && !isprint(var_3[var_4 - 1])) {
            var_3[--var_4] = 0;
        }
        for (var_5 = 0; var_5 < var_4; var_5++) {
            if (var_3[var_5] == ' ') {
                continue;
            } else {
                var_3[var_5] = var_0[var_3[var_5] - 'a'];
            }
        }
        printf("Case #%d: %s\n", var_2 + 1, var_3);
    }
    return 0;
}
