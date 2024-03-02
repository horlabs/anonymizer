#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *var_0;
    var_0 = (char *)malloc(sizeof(char) * 120);
    char var_1;
    char var_2[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                      'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                      'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

    int var_3;
    int var_4 = 1;
    int var_5;

    scanf("%d", &var_3);
    var_1 = getchar();
    while (var_3--) {

        printf("Case #%d: ", var_4);
        while ((var_1 = getchar()) != '\r' && var_1 != '\0' && var_1 != '\t' &&
               var_1 != '\n') {

            if (var_1 >= 'a' && var_1 <= 'z') {
                printf("%c", var_2[(int)var_1 - (int)'a']);
            } else {
                printf(" ");
            }
        }

        printf("\n");
        var_4++;
    }
    return 0;
}
