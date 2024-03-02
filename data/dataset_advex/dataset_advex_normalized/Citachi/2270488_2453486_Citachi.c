#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *fp_in, *fp_out;
    int i, j, T, flag_x, flag_o, flagd_x, flagd_o, c, flag = 0;
    char t[4][4];
    fp_in = fopen("A-small-attempt1(1).in", "r");
    fp_out = fopen("output.txt", "w");
    fscanf(fp_in, "%d", &T);


    for (c = 1; c <= T; c++) {
        for (i = 0; i < 4; i++)
            fscanf(fp_in, "%s", t[i]);
        flag = 0;
        flagd_x = flagd_o = 4;
        for (i = 0; i < 4; i++) {
            flag_x = flag_o = 4;
            for (j = 0; j < 4; j++) {
                if (t[i][j] == 'X' || t[i][j] == 'T')
                    flag_x -= 1;
                if (t[i][j] == 'O' || t[i][j] == 'T')
                    flag_o -= 1;
                if (i == j) {
                    if (t[i][j] == 'X' || t[i][j] == 'T')
                        flagd_x -= 1;
                    else if (t[i][j] == 'O' || t[i][j] == 'T')
                        flagd_o -= 1;
                }
            }
            if (flag_x == 0) {
                fprintf(fp_out, "Case #%d: X won\n", c);
                break;
            } else if (flag_o == 0) {
                fprintf(fp_out, "Case #%d: O won\n", c);
                break;
            }
        }
        if (flagd_x == 0) {
            fprintf(fp_out, "Case #%d: X won\n", c);
            continue;
        } else if (flagd_o == 0) {
            fprintf(fp_out, "Case #%d: O won\n", c);
            continue;

        } else if (flag_x == 0 || flag_o == 0)
            continue;
        flagd_x = flagd_o = 4;
        for (j = 0; j < 4; j++) {
            flag_x = flag_o = 4;
            for (i = 0; i < 4; i++) {
                if (t[i][j] == 'X' || t[i][j] == 'T')
                    flag_x -= 1;
                if (t[i][j] == 'O' || t[i][j] == 'T')
                    flag_o -= 1;
                if (t[i][j] == '.') {
                    flag = 1;
                }
                if ((i + j) == 3) {
                    if (t[i][j] == 'X' || t[i][j] == 'T')
                        flagd_x -= 1;
                    if (t[i][j] == 'O' || t[i][j] == 'T')
                        flagd_o -= 1;
                }
            }
            if (flag_x == 0) {
                fprintf(fp_out, "Case #%d: X won\n", c);
                break;
            } else if (flag_o == 0) {
                fprintf(fp_out, "Case #%d: O won\n", c);
                break;
            }
        }
        if (flagd_x == 0) {
            fprintf(fp_out, "Case #%d: X won\n", c);
            continue;
        } else if (flagd_o == 0) {
            fprintf(fp_out, "Case #%d: O won\n", c);
            continue;

        } else if (flag_x == 0 || flag_o == 0)
            continue;
        if (flag == 1)
            fprintf(fp_out, "Case #%d: Game has not completed\n", c);
        else
            fprintf(fp_out, "Case #%d: Draw\n", c);
    }
    fclose(fp_in);
    fclose(fp_out);
    system("pause");
}
