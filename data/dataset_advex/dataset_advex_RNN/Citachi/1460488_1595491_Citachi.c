#include <stdio.h>

int main() {
    int a[200], b[200][3], i, p, q, r, j, N, S, count = 0, temp, T, m = 1;
    FILE *f1, *f2;
    f1 = fopen("B-small-attempt0.in", "r");
    f2 = fopen("output.txt", "w");
    fscanf(f1, "%d", &T);
    while (m <= T) {
        fscanf(f1, "%d %d %d", &N, &S, &p);
        a[0] = N;
        a[1] = S;
        a[2] = p;
        for (i = 0; i < N; i++) {
            fscanf(f1, "%d", &a[i + 3]);
        }
        for (i = 0; i < a[0]; i++) {
            for (j = 10; j > 0; j--) {

                if (a[i + 3] / j == 0) {
                    if (j - 1 == 0) {
                        b[i][0] = 0;
                        b[i][1] = 0;
                        b[i][2] = 0;
                    }
                    continue;
                }

                if (abs((a[i + 3] % j) - j) == 1 || abs((a[i + 3] % j) - j) == 2) {
                    b[i][1] = j;

                    b[i][0] = a[i + 3] % j;
                    b[i][2] = j;
                    break;
                }
            }
        }
        while (S > 0) {
            for (i = 0; i < N; i++) {
                if (b[i][0] <= p) {
                    S--;
                    b[i][0]++;
                    b[i][1]--;
                    b[i][2]--;
                    break;
                } else if (b[i][1] <= p) {
                    S--;
                    b[i][0]--;
                    b[i][1]++;
                    b[i][2]--;
                    break;
                } else {
                    S--;
                    b[i][0]--;
                    b[i][1]--;
                    b[i][2]++;
                    break;
                }
            }
        }
        for (i = 0; i < a[0]; i++) {
            if (b[i][1] >= p || b[i][0] >= p || b[i][2] >= p)
                count++;
        }
        fprintf(f2, "Case #%d: %d\n", m, count);
        m++;
        count = 0;
    }
    return 0;
}
