#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char var_0[1234567];
char var_1[256];
int main(int argc, char **argv) {
    int var_2;
    int var_3;
    int var_4;

    for (var_3 = 0; var_3 < 256; ++var_3) {
        var_1[var_3] = var_3;
    }
    var_1['a'] = 'y';
    var_1['b'] = 'h';
    var_1['c'] = 'e';
    var_1['d'] = 's';
    var_1['e'] = 'o';
    var_1['f'] = 'c';
    var_1['g'] = 'v';
    var_1['h'] = 'x';
    var_1['i'] = 'd';
    var_1['j'] = 'u';
    var_1['k'] = 'i';
    var_1['l'] = 'g';
    var_1['m'] = 'l';
    var_1['n'] = 'b';
    var_1['o'] = 'k';
    var_1['p'] = 'r';
    var_1['q'] = 'z';
    var_1['r'] = 't';
    var_1['s'] = 'n';
    var_1['t'] = 'w';
    var_1['u'] = 'j';
    var_1['v'] = 'p';
    var_1['w'] = 'f';
    var_1['x'] = 'm';
    var_1['y'] = 'a';
    var_1['z'] = 'q';

    scanf("%d", &var_2);
    gets(var_0);

    for (var_3 = 1; var_3 <= var_2; ++var_3) {
        gets(var_0);
        printf("Case #%d: ", var_3);
        for (var_4 = 0; var_0[var_4] != '\0'; ++var_4) {
            putchar(var_1[var_0[var_4]]);
        }
        puts("");
    }

    return 0;
}
