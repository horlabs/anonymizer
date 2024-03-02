#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;

    char *var_3 = "yhesocvxduiglbkrztnwjpfmaq";
    char var_4[101];
    scanf("%d%*c", &var_0);
    for (var_1 = 1; var_1 <= var_0; ++var_1) {
        gets(var_4);
        printf("Case #%d: ", var_1);
        for (var_2 = 0; var_4[var_2]; ++var_2) {
            putchar(var_4[var_2] == ' ' ? ' ' : var_3[var_4[var_2] - 'a']);
        }
        puts("");
    }
    return 0;
}
