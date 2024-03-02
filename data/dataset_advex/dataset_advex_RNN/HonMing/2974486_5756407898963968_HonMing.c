#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int i, j;
    int ii, jj, kk;
    int res;
    int m;
    int map[10][10];
    int end, xw, ow;
    int r1, r2;
    int p[10];
    int p2[10];
    int count;
    int ans;

    unsigned long long result;

    scanf("%d", &m);

    for (ii = 1; ii <= m; ii++) {
        scanf("%d", &r1);
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++) {
                scanf("%d", &map[i][j]);
                if (i == r1 - 1)
                    p[j] = map[i][j];
            }


        scanf("%d", &r2);
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++) {
                scanf("%d", &map[i][j]);
                if (i == r2 - 1)
                    p2[j] = map[i][j];
            }

        count = 0;
        ans = -1;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (p[i] == p2[j]) {
                    ans = p[i];
                    count++;
                    break;
                }
            }
        }

        if (count == 0)
            printf("Case #%d: Volunteer cheated!\n", ii);
        else if (count == 1)
            printf("Case #%d: %d\n", ii, ans);
        else
            printf("Case #%d: Bad magician!\n", ii);
    }
}
