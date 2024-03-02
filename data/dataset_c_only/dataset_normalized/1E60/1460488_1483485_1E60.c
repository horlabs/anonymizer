#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argvvoid) {

    char var_0[100 * 5];
    int var_1[26] = {
        24, 7,  4,  18, 14, 2,  21, 23, 3,  20, 8,  6, 11,
        1,  10, 17, 25, 19, 13, 22, 9,  15, 5,  12, 0, 16,
    };
    int var_2;
    int var_3;
    scanf("%d\n", &var_2);
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        memset(var_0, 0, sizeof var_0);
        scanf("%[a-z ]\n", var_0);
        int var_4 = 0;
        while (var_0[var_4] != '\0') {
            if (var_0[var_4] != ' ') {
                var_0[var_4] = 'a' + var_1[var_0[var_4] - 'a'];
            }
            var_4++;
        }
        printf("Case #%d: %s\n", var_3, var_0);
    }
    return 0;
}
