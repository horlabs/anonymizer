#include <stdio.h>

int main(int var_0, char *var_1[]) {
    FILE *var_2;
    FILE *var_3;

    var_2 = (var_0 <= 1) ? fopen("input.txt", "r+") : fopen(var_1[1], "r+");
    var_3 = fopen("output.txt", "w+");

    if (var_2) {
        int var_4;
        char var_5[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                          'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                          'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

        int var_6;

        fscanf(var_2, "%d", &var_4);
        fgetc(var_2);
        for (var_6 = 0; var_6 < var_4; var_6++) {
            int var_7;

            fprintf(var_3, "Case #%d: ", var_6 + 1);

            do {
                var_7 = fgetc(var_2);

                if (var_7 != ' ' && var_7 != '\n' && var_7 != EOF) {
                    var_7 = var_5[var_7 - 'a'];
                }
                if (var_7 != EOF) {
                    fprintf(var_3, "%c", var_7);
                }
            } while (var_7 != '\n' && var_7 != EOF);
        }
    }

    return 0;
}
