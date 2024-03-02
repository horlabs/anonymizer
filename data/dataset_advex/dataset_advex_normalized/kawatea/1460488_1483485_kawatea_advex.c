#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;
    int var_3;

    char var_4[26] = {"yhesocvxduiglbkrztnwjpfmaq"};
    char var_5[110];

    scanf("%d%*c", &var_0);

    for (var_2 = 0; var_2 < var_0; var_2++) {
        fgets(var_5, 105, stdin);

        var_1 = strlen(var_5);

        var_5[var_1 - 1] = '\0';
        var_1--;

        for (var_3 = 0; var_3 < var_1; var_3++) {
            if (var_5[var_3] == ' ') {
                continue;
            } else {

                var_5[var_3] = var_4[var_5[var_3] - 'a'];
            }
        }

        printf("Case #%d: %s\n", var_2 + 1, var_5);
    }

    return 0;
}
