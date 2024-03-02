#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *fp_in, *fp_out;
    int a[10][10], T, N, M, i, j, n, c, flag = 0;
    fp_in = fopen("B-small-attempt1.in", "r");
    fp_out = fopen("output.txt", "w");
    fscanf(fp_in, "%d", &T);
    for (c = 1; c <= T; c++) {
        flag = 0;
        fscanf(fp_in, "%d %d", &N, &M);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++)
                fscanf(fp_in, "%d", &a[i][j]);
        }
        for (i = 0; i < N; i++) {
            n = a[i][0];

            for (j = 0; j < M; j++) {
                if (a[i][j] != 0) {
                    a[i][j] = (int) abs(n - a[i][j]);
                }
            }
        }

        for (j = 0; j < M; j++) {
            n = a[0][j];
            for (i = 0; i < N; i++) {
                if (a[i][j] != 0) {
                    a[i][j] = (int) abs(n - a[i][j]);
                }
            }
        }


        for (i = 0; i < N; i++) {
            n = a[i][M - 1];
            if (n == 0)
                continue;
            for (j = 0; j < M; j++) {
                if (a[i][j] != 0) {
                    a[i][j] = (int) abs(n - a[i][j]);
                }
            }
        }

        for (j = 0; j < M; j++) {
            n = a[N - 1][j];
            if (n == 0)
                continue;
            for (i = 0; i < N; i++) {
                if (a[i][j] != 0) {
                    a[i][j] = (int) abs(n - a[i][j]);
                }
            }
        }

        for (i = 1; i < N - 1; i++) {
            for (j = 1; j < M - 1; j++)
                if (a[i][j] != 0) {
                    flag = 1;
                    break;
                }
        }
        if (flag == 0)
            fprintf(fp_out, "Case #%d: YES\n", c);
        else
            fprintf(fp_out, "Case #%d: NO\n", c);
    }
    fclose(fp_in);
    fclose(fp_out);
    system("pause");
}
