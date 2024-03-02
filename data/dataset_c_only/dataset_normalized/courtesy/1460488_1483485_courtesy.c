#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *var_0;
FILE *var_1;
char var_2[26];
void func_0() {
    var_2[0] = 'y';
    var_2[1] = 'n';
    var_2[2] = 'f';
    var_2[3] = 'i';
    var_2[4] = 'c';
    var_2[5] = 'w';
    var_2[6] = 'l';
    var_2[7] = 'b';
    var_2[8] = 'k';
    var_2[9] = 'u';
    var_2[10] = 'o';
    var_2[11] = 'm';
    var_2[12] = 'x';
    var_2[13] = 's';
    var_2[14] = 'e';
    var_2[15] = 'v';
    var_2[16] = 'z';
    var_2[17] = 'p';
    var_2[18] = 'd';
    var_2[19] = 'r';
    var_2[20] = 'j';
    var_2[21] = 'g';
    var_2[22] = 't';
    var_2[23] = 'h';
    var_2[24] = 'a';
    var_2[25] = 'q';
    return;
}
char func_1(char var_3) {
    int var_4;
    for (var_4 = 0; var_4 < 26; var_4++) {
        if (var_2[var_4] == var_3) {
            return (var_4 + 'a');
        }
    }
    return (' ');
}
void func_2() {
    char var_5;
    char var_6;
    char var_7[500];
    char var_8 = 0;

    int var_9;

    var_5 = fgetc(var_0);
    while (var_5 != '\n') {
        var_7[var_8++] = var_5;
        var_5 = fgetc(var_0);
    }
    for (var_9 = 0; var_9 < var_8; var_9++) {
        var_7[var_9] = func_1(var_7[var_9]);
    }
    var_7[var_8] = '\0';
    fprintf(var_1, "%s", var_7);
    return;
}
int main(int argc, char **argv) {
    var_0 = fopen("/home/vivek/Desktop/s.in", "r");
    var_1 = fopen("/home/vivek/Desktop/s.out", "w");
    int var_10;
    int var_11;

    char var_12;
    func_0();
    fscanf(var_0, "%d", &var_10);
    while (fgetc(var_0) != '\n') {
        ;
    }
    for (var_11 = 1; var_11 <= var_10; var_11++) {
        fprintf(var_1, "Case #%d: ", var_11);
        func_2();
        var_12 = '\n';
        fputc(var_12, var_1);
        printf("%d", var_11);
    }
    return 1;
}
