#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int var_0, char **var_1) {
    char var_2[26] = "yhesocvxduiglbkrztnwjpfmaq";
    char var_3[105];
    char var_4[105];

    int var_5;
    int var_6;
    int var_7;
    int var_8;
    int var_9;

    assert(scanf("%d ", &var_5) == 1);
    for (var_7 = 1; var_7 <= var_5; var_7++) {
        assert(fgets(var_3, 105, stdin) != NULL);
        var_9 = strlen(var_3);
        for (var_8 = 0; var_8 < var_9; var_8++) {
            if ((var_3[var_8] != ' ') && (var_3[var_8] != 0xA)) {
                var_4[var_8] = var_2[var_3[var_8] - 'a'];
            } else {
                if (var_3[var_8] == ' ') {
                    var_4[var_8] = var_3[var_8];
                }
            }
        }
        var_4[var_8 - 1] = '\0';
        printf("Case #%d: %s\n", var_7, var_4);
    }
    return 0;
}
