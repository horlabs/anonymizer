#include <stdio.h>

typedef struct {
    int t, q;
} Number;

int calculateTotalScores(int n, int s, int p, Number numbers[]) {
    int u = 0, ukupno = 0;

    for (int i = 0; i < n; i++) {
        int t = numbers[i].t;
        int q = numbers[i].q;

        if (t > 28 || t < 2) {
            if (q >= p) {
                ukupno++;
            }
            continue;
        }

        if (q >= p) {
            ukupno++;
        } else if (q + 1 >= p && (t % 3) != 1) {
            u++;
        }
    }

    if (u >= s) {
        ukupno += s;
    } else {
        ukupno += u;
    }

    return ukupno;
}

int main() {
    int T, tt;
    scanf("%d", &T);

    for (tt = 1; tt <= T; tt++) {
        int n, s, p;
        scanf("%d %d %d", &n, &s, &p);

        Number numbers[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i].t);
            numbers[i].q = (numbers[i].t + 2) / 3;
        }

        int ukupno = calculateTotalScores(n, s, p, numbers);

        printf("Case #%d: %d\n", tt, ukupno);
    }

    return 0;
}