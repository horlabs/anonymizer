#include <stdio.h>

#define MAX(p,q) (((p)>(q))?(p):(q))
#define MIN(p,q) (((p)<(q))?(p):(q))

int arr[102][102];

int checkRange(int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        int min = 101, max = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                min = MIN(min, arr[i][j]);
                max = MAX(max, arr[i][j]);
            }
        }
        if (min == k && max == k) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int min = 101, max = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i][j]) {
                min = MIN(min, arr[i][j]);
                max = MAX(max, arr[i][j]);
            }
        }
        if (min == k && max == k) {
            for (int i = 0; i < n; i++) {
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == k) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int numOfCases, n, m, f, i, j, k, x;
    scanf("%d", &numOfCases);
    for (x = 1; x <= numOfCases; x++) {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        f = 1;
        for (k = 1; k <= 100; k++) {
            if (checkRange(n, m, k) == 0) {
                f = 0;
                break;
            }
        }
        printf("Case #%d: %s\n", x, f ? "YES" : "NO");
    }
    return 0;
}