#include <stdio.h>

char var_0[] = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char **argv) {
    int var_1;
    scanf("%d ", &var_1);
    for (int var_2 = 1; var_2 <= var_1; var_2++) {
        char var_3[101];
        gets(var_3);
        for (int var_4 = 0; var_3[var_4]; var_4++) {
            if (var_3[var_4] >= 'a' && var_3[var_4] <= 'z') {
                var_3[var_4] = var_0[var_3[var_4] - 'a'];
            }
        }
        printf("Case #%d: %s\n", var_2, var_3);
    }
    return 0;
}
