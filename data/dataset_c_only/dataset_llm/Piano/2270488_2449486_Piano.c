#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void fillMatrix(int n, int m, int a[][m]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

int isMatrixValid(int n, int m, int a[][m], int mrow[], int mcol[]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != max(mrow[i], mcol[j])) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int u = 1; u <= t; ++u) {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n][m], mrow[n], mcol[m];
        for (int i = 0; i < n; ++i) {
            mrow[i] = 0;
        }
        for (int j = 0; j < m; ++j) {
            mcol[j] = 0;
        }
        fillMatrix(n, m, a);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mrow[i] = max(mrow[i], a[i][j]);
                mcol[j] = max(mcol[j], a[i][j]);
            }
        }
        printf("Case #%d: %s\n", u, isMatrixValid(n, m, a, mrow, mcol) ? "YES" : "NO");
    }
    return 0;
}