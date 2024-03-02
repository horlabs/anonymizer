#include <stdio.h>

int main(int argc, char **argv) {
    char var_0[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k',
                      'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p',
                      'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'};
    char var_1;
    char var_2;
    char var_3;
    char var_4 = 0;
    char var_5;

    FILE *var_6;
    FILE *var_7;

    var_6 = fopen("A-small-attempt1.in", "r");
    var_7 = fopen("output.txt", "w");
    fscanf(var_6, "%d", &var_5);
    while ((var_3 = getc(var_6)) != EOF) {
        if (var_3 == '\n') {
            var_4++;
            if (var_4 != 1) {
                putc(var_3, var_7);
            }
            if (var_4 != var_5 + 1) {
                fprintf(var_7, "Case #%d: ", var_4);
            }
        }

        if (var_3 == ' ') {
            putc(var_3, var_7);
        } else {
            for (var_1 = 0; var_1 < 26; var_1++) {
                if (var_3 == var_0[var_1]) {
                    putc((var_1 + 'a'), var_7);
                }
            }
        }
    }
    fclose(var_6);
    fclose(var_7);
    return 0;
}
