#include <stdio.h>
#include <string.h>

char func_0(char);

int main(int argc, char **argv) {
    char var_0[105];
    int var_1;
    int var_2;
    int var_3;

    FILE *var_4;
    FILE *var_5;

    var_4 = fopen("A-small-attempt2.in", "r");
    if (var_4 == NULL) {
        printf("error");
    }
    var_5 = fopen("output1.out", "a");
    fscanf(var_4, "%d", &var_2);
    fgets(var_0, 2, var_4);
    for (var_3 = 0; var_3 < var_2; var_3++) {
        fprintf(var_5, "Case #%d: ", var_3 + 1);
        fgets(var_0, 105, var_4);
        for (var_1 = 0; var_1 < strlen(var_0) - 1; var_1++) {
            fprintf(var_5, "%c", func_0(var_0[var_1]));
        }
        fprintf(var_5, "\n", var_0);
    }
    return 0;
}

char func_0(char var_6) {
    int var_7;
    char var_8[] =
        "our language is impossible to understand there are twenty six "
        "factorial possibilities so it is okay if you want to just give up";
    char var_9[] =
        "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh "
        "wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    if (var_6 == 'z') {
        return 'q';
    } else {
        if (var_6 == 'q') {
            return 'z';
        } else {
            for (var_7 = 0; var_7 < strlen(var_9); var_7++) {
                if (var_6 == var_9[var_7]) {
                    break;
                }
            }
            return var_8[var_7];
        }
    }
}
