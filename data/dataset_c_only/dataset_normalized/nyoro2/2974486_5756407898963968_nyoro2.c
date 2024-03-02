#include <stdio.h>

int main(int argc, char **argv) {
    int var_0;
    int var_1[2];
    int var_2[2][4][4];
    int var_3;
    int var_4;
    int var_5;
    int var_6;

    int var_7;
    int var_8;

    fscanf(stdin, "%d\n", &var_0);
    for (var_3 = 0; var_3 < var_0; var_3++) {

        for (var_4 = 0; var_4 < 2; var_4++) {
            fscanf(stdin, "%d\n", var_1 + var_4);
            for (var_5 = 0; var_5 < 4; var_5++) {
                fscanf(stdin, "%d %d %d %d\n", var_2[var_4][var_5],
                       var_2[var_4][var_5] + 1, var_2[var_4][var_5] + 2,
                       var_2[var_4][var_5] + 3);
            }
        }
        var_7 = 0;
        for (var_5 = 0; var_5 < 4; var_5++) {
            int var_9;
            var_9 = var_2[0][var_1[0] - 1][var_5];
            for (var_6 = 0; var_6 < 4; var_6++) {
                if (var_9 == var_2[1][var_1[1] - 1][var_6]) {
                    var_8 = var_9;
                    var_7++;
                }
            }
        }

        printf("Case #%d: ", var_3 + 1);
        if (var_7 == 0) {
            printf("Volunteer cheated!\n");
        } else if (var_7 == 1) {
            printf("%d\n", var_8);
        } else {
            printf("Bad magician!\n");
        }
    }

    return 0;
}
