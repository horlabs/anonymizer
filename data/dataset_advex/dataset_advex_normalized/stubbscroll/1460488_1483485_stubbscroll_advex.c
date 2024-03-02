#include <stdio.h>
#include <string.h>

char var_0[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char var_1[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char var_2[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

char var_3[] = "our language is impossible to understand";
char var_4[] = "there are twenty six factorial possibilities";
char var_5[] = "so it is okay if you want to just give up";

int var_6[256];

void func_0(char *var_7, char *var_8) {
    while (*var_7) {
        var_6[(int)*(var_7++)] = *(var_8++);
    }
    return;
}

char var_9[16384];

int main(int argc, char **argv) {
    int var_10 = 1;
    int var_11;
    int var_12;

    memset(var_6, 0, sizeof var_6);
    func_0(var_0, var_3);
    func_0(var_1, var_4);
    func_0(var_2, var_5);
    var_6['q'] = 'z';
    var_6['z'] = 'q';
    gets(var_9);
    sscanf(var_9, "%d", &var_11);
    while (var_11--) {
        gets(var_9);
        for (var_12 = 0; var_9[var_12]; var_12++) {
            var_9[var_12] = var_6[(int)var_9[var_12]];
        }
        printf("Case #%d: %s\n", var_10++, var_9);
    }
    return 0;
}
