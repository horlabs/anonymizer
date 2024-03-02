#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argvvoid) {
    freopen("A-small-attempt0.in", "r", stdin);

    int var_0 = 0;
    int var_1;

    scanf("%d\n", &var_1);

    while (var_0 < var_1) {
        int var_2;
        int var_3[4];
        int var_4;
        int var_5;
        int var_6;
        int var_7;

        scanf("%d\n", &var_2);
        for (var_4 = 1; var_4 <= 4; var_4++) {
            if (var_4 == var_2) {
                scanf("%d %d %d %d", &var_3[0], &var_3[1], &var_3[2],
                      &var_3[3]);
            } else {
                scanf("%*d %*d %*d %*d");
            }
        }

        scanf("%d\n", &var_2);
        for (var_4 = 1; var_4 <= 4; var_4++) {
            if (var_4 == var_2) {
                int var_8;
                int var_9;

                for (var_5 = 0, var_8 = 0; var_8 < 4; var_8++) {
                    scanf("%d", &var_6);

                    for (var_9 = 0; var_9 < 4; var_9++) {
                        if (var_6 == var_3[var_9]) {
                            var_5++;
                            var_7 = var_6;
                        }
                    }
                }
            } else {
                scanf("%*d %*d %*d %*d");
            }
        }

        if (var_5 == 0) {
            printf("Case #%d: %s\n", ++var_0, "Volunteer cheated!");
        } else if (var_5 == 1) {
            printf("Case #%d: %d\n", ++var_0, var_7);
        } else {
            printf("Case #%d: %s\n", ++var_0, "Bad magician!");
        }
    }

    return 0;
}
