#include <stdio.h>
#include <stdlib.h>

void func_0() {
    while (getchar() != '\n') {
        ;
    }
    return;
}

int main(int argc, char **argv) {
    int var_0;
    int var_1;

    char var_2;
    char var_3[27] = "yhesocvxduiglbkrztnwjpfmaq";

    scanf("%d", &var_0);
    func_0();
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        printf("Case #%d: ", var_1);
        do {
            var_2 = getchar();
            if (var_2 >= 'a' && var_2 <= 'z') {
                putchar(var_3[var_2 - 'a']);
            } else {
                putchar(var_2);
            }
        } while (var_2 != '\n');
    }
    return 0;
}
