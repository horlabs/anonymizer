#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;

    int var_3;
    int var_4;
    int var_5;

    int var_6;

    scanf("%d", &var_0);

    char var_7[30] = "yhesocvxduiglbkrztnwjpfmaq";
    char var_8[1024];
    fgets(var_8, 1024, stdin);

    for (var_6 = 1; var_6 <= var_0; var_6++) {
        fgets(var_8, 1024, stdin);
        var_8[strlen(var_8) - 1] = '\0';
        for (var_3 = 0; var_3 < strlen(var_8); var_3++) {
            if (var_8[var_3] == ' ') {
                continue;
            } else {
                var_8[var_3] = var_7[var_8[var_3] - 'a'];
            }
        }
        printf("Case #%d: %s\n", var_6, var_8);
    }
    return 0;
}
