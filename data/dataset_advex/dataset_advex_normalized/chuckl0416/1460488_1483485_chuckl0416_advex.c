#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *var_0;
    FILE *var_1;

    var_0 = freopen("A-small-attempt1.in", "r", stdin);
    var_1 = freopen("A-small-attempt1.out", "w", stdout);

    int var_2;
    int var_3;

    char var_4[100000];
    scanf("%d", &var_2);
    int var_5;
    int var_6;

    getchar();
    for (var_3 = 1; var_3 <= var_2; var_3++) {
        printf("Case #%d: ", var_3);
        gets(var_4);
        var_5 = 0;
        var_6 = strlen(var_4);

        for (var_5 = 0; var_5 < var_6; var_5++) {
            if (isalpha(var_4[var_5])) {
                if (var_4[var_5] == ('a')) {
                    putchar('y');
                } else if (var_4[var_5] == ('b')) {
                    putchar('h');
                } else if (var_4[var_5] == ('c')) {
                    putchar('e');
                } else if (var_4[var_5] == ('d')) {
                    putchar('s');
                } else if (var_4[var_5] == ('e')) {
                    putchar('o');
                } else if (var_4[var_5] == ('f')) {
                    putchar('c');
                } else if (var_4[var_5] == ('g')) {
                    putchar('v');
                } else if (var_4[var_5] == ('h')) {
                    putchar('x');
                } else if (var_4[var_5] == ('i')) {
                    putchar('d');
                } else if (var_4[var_5] == ('j')) {
                    putchar('u');
                } else if (var_4[var_5] == ('k')) {
                    putchar('i');
                } else if (var_4[var_5] == ('l')) {
                    putchar('g');
                } else if (var_4[var_5] == ('m')) {
                    putchar('l');
                } else if (var_4[var_5] == ('n')) {
                    putchar('b');
                } else if (var_4[var_5] == ('o')) {
                    putchar('k');
                } else if (var_4[var_5] == ('p')) {
                    putchar('r');
                } else if (var_4[var_5] == ('q')) {
                    putchar('z');
                } else if (var_4[var_5] == ('r')) {
                    putchar('t');
                } else if (var_4[var_5] == ('s')) {
                    putchar('n');
                } else if (var_4[var_5] == ('t')) {
                    putchar('w');
                } else if (var_4[var_5] == ('u')) {
                    putchar('j');
                } else if (var_4[var_5] == ('v')) {
                    putchar('p');
                } else if (var_4[var_5] == ('w')) {
                    putchar('f');
                } else if (var_4[var_5] == ('x')) {
                    putchar('m');
                } else if (var_4[var_5] == ('y')) {
                    putchar('a');
                } else if (var_4[var_5] == ('z')) {
                    putchar('q');
                }

            } else {
                putchar(var_4[var_5]);
            }
        }

        putchar(10);
    }

    fclose(var_0);
    fclose(var_1);

    return 0;
}
