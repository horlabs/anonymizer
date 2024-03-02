#include <stdio.h>
#include <stdlib.h>

void func_0();

char var_0[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd',
                'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't',
                'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main(int argc, char **argv) {
    int var_1;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d ", &var_1);
    int var_2;
    for (var_2 = 0; var_2 < var_1; var_2++) {
        printf("Case #%d: ", var_2 + 1);
        func_0();
    }
    return 0;
}

void func_0() {
    char var_3[2000];
    char var_4;
    int var_5 = 0;
    scanf("%c", &var_4);
    while (var_4 != '\n') {
        var_3[var_5] = var_4;
        var_5++;
        scanf("%c", &var_4);
    }
    var_3[var_5] = '\0';
    for (var_5 = 0; var_3[var_5] != '\0'; var_5++) {
        if (var_3[var_5] >= 'a' && var_3[var_5] <= 'z') {
            printf("%c", var_0[var_3[var_5] - 'a']);
        } else {
            printf(" ");
        }
    }
    printf("\n");
    return;
    return;
}
