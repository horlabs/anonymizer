#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argvvoid) {
    int var_0;
    int var_1;

    scanf("%d\n", &var_0);
    for (var_1 = 1; var_1 <= var_0; var_1++) {
        int var_2;
        int var_3;

        scanf("%d %d\n", &var_2, &var_3);
        int var_4 = 0;

        int var_5;
        for (var_5 = var_2; var_5 <= var_3; var_5++) {

            char var_6[100];
            char var_7[100];

            int var_8;

            sprintf(var_6, "%d", var_5);
            var_8 = strlen(var_6);
            strcpy(var_7, var_6);
            while (1) {

                char var_9 = var_7[var_8 - 1];
                memmove(&var_7[1], &var_7[0], sizeof(char) * (var_8 - 1));
                var_7[0] = var_9;

                if (strcmp(var_7, var_6) == 0) {
                    break;
                } else {

                    if (var_7[0] == '0') {
                        continue;
                    } else {

                        int var_10 = atoi(var_7);

                        if (var_2 <= var_10 && var_10 <= var_3) {

                            var_4++;
                        }
                    }
                }
            }
        }
        assert(var_4 % 2 == 0);
        printf("Case #%d: %d\n", var_1, var_4 / 2);
    }
    return 0;
}
