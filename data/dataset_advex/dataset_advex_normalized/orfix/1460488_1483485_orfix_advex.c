#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argvvoid) {
    freopen("A-small-attempt4.in", "r", stdin);

    int var_0 = 0;
    int var_1;

    char var_2[] = "yhesocvxduiglbkrztnwjpfmaq";
    char var_3[102] = "";

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {

        char *var_4 = var_3;

        fgets(var_3, 102, stdin);
        for (; *var_4 != '\0'; var_4++) {

            if (isalpha(*var_4)) {
                *var_4 = var_2[*var_4 - 'a'];
            }
        }

        printf("Case #%d: %s", ++var_0, var_3);
    }

    return 0;
}
