#include <stdio.h>

char var_0[] = {

    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',

    'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w',

    'j', 'p', 'f', 'm', 'a', 'q'};

int main(int argc, char **argv) {
    int var_1;
    int var_2;
    char var_3[128];
    char *var_4;

    fscanf(stdin, "%d\n", &var_1);
    for (var_2 = 0; var_2 < var_1; var_2++) {
        fgets(var_3, 120, stdin);

        fprintf(stdout, "Case #%d: ", var_2 + 1);
        var_4 = var_3;
        while (*var_4) {

            if (*var_4 == ' ') {
                fprintf(stdout, " ");
            } else {
                if ((*var_4 >= 'a') && (*var_4 <= 'z')) {
                    fprintf(stdout, "%c", var_0[*var_4 - 'a']);
                }
            }
            var_4++;
        }
        fprintf(stdout, "\n");
    }

    return 0;
}
