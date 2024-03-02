#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    char var_0[128];
    char var_1[27] = {"yhesocvxduiglbkrztnwjpfmaq"};

    int var_2;
    int var_3;
    int var_4;

    FILE *var_5 = fopen("A-small-attempt0.in", "r");
    FILE *var_6 = fopen("out.txt", "w");

    fscanf(var_5, "%d\n", &var_4);

    for (var_2 = 0; var_2 < var_4; var_2++) {

        fgets(var_0, 128, var_5);

        fprintf(var_6, "Case #%d: ", var_2 + 1);
        for (var_3 = 0; var_0[var_3] != 0; var_3++) {
            fputc(islower(var_0[var_3]) ? var_1[var_0[var_3] - 'a']
                                        : var_0[var_3],
                  var_6);
        }
    }

    fclose(var_5);
    fclose(var_6);
    return 0;
}
