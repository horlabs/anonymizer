#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1;
    int var_2;

    char var_3[150];

    char var_4[] = "yhesocvxduiglbkrztnwjpfmaq";

    fgets(var_3, sizeof var_3, stdin);
    var_0 = atoi(var_3);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        fgets(var_3, sizeof var_3, stdin);
        printf("Case #%d: ", var_1);
        for (var_2 = 0; var_3[var_2]; var_2++) {
            if (var_3[var_2] < 'a' || var_3[var_2] > 'z') {
                printf("%c", var_3[var_2]);
            } else {
                printf("%c", var_4[var_3[var_2] - 'a']);
            }
        }
        printf("\n");
    }
    return 0;
}
