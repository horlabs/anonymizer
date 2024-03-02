#include <stdio.h>

int main(int argc, char **argvvoid) {
    int var_0[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                   'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                   'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
    int var_1;
    int var_2;
    int var_3;

    var_2 = 0;
    while ((var_1 = getchar()) != '\n') {
        var_2 = var_2 * 10;
        var_2 = var_2 + (var_1 - '0');
    }
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        printf("Case #%d: ", var_3);
        while (((var_1 = getchar()) != '\n') && (var_1 != EOF)) {

            if (var_1 == ' ') {
                putchar(var_1);
            } else {
                putchar(var_0[var_1 - 'a']);
            }
        }
        putchar(var_1);
    }
    return 0;
}
