#include <stdio.h>


int main() {
    int a[4][4], b[4][4];
    FILE *fp1, *fp2;
    fp1 = fopen("A-small-attempt2.in", "r");
    fp2 = fopen("magic_out.txt", "w");
    int r1, r2, i, j, count, y, t, T;
    fscanf(fp1, "%d", &T);

    t = 1;
    while (t <= T) {
        fscanf(fp1, "%d", &r1);

        for (i = 0; i < 4; i++) {

            fscanf(fp1, "%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        }
        fscanf(fp1, "%d", &r2);
        for (i = 0; i < 4; i++) {
            fscanf(fp1, "%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
        }
        count = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (a[r1 - 1][i] == b[r2 - 1][j]) {
                    count++;

                    y = a[r1 - 1][i];
                }
            }
        }

        if (t == T) {
            if (count == 1)
                fprintf(fp2, "Case #%d: %d", t, y);
            else if (count > 1)
                fprintf(fp2, "Case #%d: Bad magician!", t);


            else
                fprintf(fp2, "Case #%d: Volunteer cheated!", t);

        } else {
            if (count == 1)
                fprintf(fp2, "Case #%d: %d\n", t, y);
            else if (count > 1)
                fprintf(fp2, "Case #%d: Bad magician!\n", t);


            else
                fprintf(fp2, "Case #%d: Volunteer cheated!\n", t);
        }

        t++;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
