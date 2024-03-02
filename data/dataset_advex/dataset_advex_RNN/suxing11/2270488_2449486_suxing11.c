#include <stdio.h>


int g[110][110], gg[110][110];
int row[110], col[110];
int h[220][3];


int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int main() {
    int T, nCase = 1;
    int ROW = 0, COL = 1;
    int flag, n, m, i, j, cc, t;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B_out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            row[i] = 0;
        for (j = 0; j < m; j++)
            col[j] = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &g[i][j]),
                        row[i] = max(row[i], g[i][j]),
                        col[j] = max(col[j], g[i][j]);
        cc = 0;
        for (i = 0; i < n; i++)
            h[cc][0] = row[i],
            h[cc][1] = i, h[cc][2] = ROW, cc++;
        for (i = 0; i < m; i++)
            h[cc][0] = col[i],
            h[cc][1] = i, h[cc][2] = COL, cc++;
        for (i = 0; i < cc; i++)
            for (j = 0; j < i; j++)
                if (h[i][0] < h[j][0])
                    (t = h[i][0], h[i][0] = h[j][0], h[j][0] = t),
                            (t = h[i][1], h[i][1] = h[j][1], h[j][1] = t),
                            (t = h[i][2], h[i][2] = h[j][2], h[j][2] = t);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) gg[i][j] = 100;
        for (i = cc - 1; i >= 0; i--) {
            if (h[i][2] == ROW)
                for (j = 0; j < m; j++) gg[h[i][1]][j] = h[i][0];
            else
                for (j = 0; j < n; j++) gg[j][h[i][1]] = h[i][0];
        }
        flag = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (g[i][j] != gg[i][j]) flag = 1;
        printf("Case #%d: %s\n", nCase++, flag ? "NO" : "YES");
    }
    return 0;
}
