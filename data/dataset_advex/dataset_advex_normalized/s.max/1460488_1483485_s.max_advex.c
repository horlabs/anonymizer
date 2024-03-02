#include <stdio.h>

int main(int argc, char **argv) {
    char var_0[50] = "yhesocvxduiglbkrztnwjpfmaq";
    char var_1[1000];
    int var_2;
    int var_3;

    fgets(var_1, 1000, stdin);
    sscanf(var_1, "%d", &var_2);

    for (var_3 = 1; var_3 <= var_2; var_3++) {
        int var_4;

        fgets(var_1, 1000, stdin);

        for (var_4 = 0; var_1[var_4]; var_4++) {
            if (var_1[var_4] != ' ' && var_1[var_4] != '\n') {
                var_1[var_4] = var_0[var_1[var_4] - 'a'];
            }
        }

        printf("Case #%d: %s", var_3, var_1);
    }

    return 0;
}
