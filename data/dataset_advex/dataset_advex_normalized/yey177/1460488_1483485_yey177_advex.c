#include <stdio.h>

char var_0[28] = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char **argv) {
    int var_1;
    int var_2;
    int var_3;

    char var_4[108];
    scanf("%d", &var_1);
    gets(var_4);
    for (var_3 = 1; var_3 <= var_1; var_3++) {
        gets(var_4);
        printf("Case #%d: ", var_3);
        for (var_2 = 0; var_4[var_2]; var_2++) {
            putchar(var_4[var_2] == 32 ? var_4[var_2]
                                       : var_0[(int)(var_4[var_2] - 'a')]);
        }
        puts("");
    }
    return 0;
}
