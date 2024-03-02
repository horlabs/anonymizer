#include <stdio.h>
#include <stdlib.h>


int main(void) {
    freopen("B-small-attempt0.in", "r", stdin);

    int testcase = 0;
    int testcases;

    scanf("%d\n", &testcases);

    while (testcase < testcases) {
        int n, m;
        int i, j;
        int lawn[99][99];
        int res = 1;

        scanf("%d %d\n", &n, &m);

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &lawn[i][j]);
            }
            getchar();
        }

        for (i = 0; i < n && res == 1; i++) {
            for (j = 0; j < m && res == 1; j++) {
                int i_res = 1;
                int j_res = 1;
                int ii, jj;

                for (ii = 0; ii < n; ii++) {
                    if (lawn[ii][j] > lawn[i][j]) i_res = 0;
                }
                for (jj = 0; jj < m; jj++) {
                    if (lawn[i][jj] > lawn[i][j]) j_res = 0;
                }
                if (i_res == 0 && j_res == 0) res = 0;
            }
        }


        printf("Case #%d: %s\n", ++testcase, res ? "YES" : "NO");
    }

    return 0;
}
