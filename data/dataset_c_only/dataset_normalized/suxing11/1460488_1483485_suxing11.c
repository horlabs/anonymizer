#include <stdio.h>

char var_0[110];
char var_1[] = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char **argv) {
    int var_2;
    int var_3;
    int var_4 = 1;

    scanf("%d%*c", &var_3);

    freopen("out.txt", "w", stdout);

    while (var_3--) {
        gets(var_0);
        printf("Case #%d: ", var_4++);
        for (var_2 = 0; var_0[var_2]; var_2++) {
            if (var_0[var_2] >= 'a' && var_0[var_2] <= 'z') {
                putchar(var_1[var_0[var_2] - 'a']);
            } else {
                putchar(var_0[var_2]);
            }
        }
        printf("\n");
    }
    return 0;
}
