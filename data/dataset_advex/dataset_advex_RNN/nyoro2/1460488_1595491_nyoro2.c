#include <stdio.h>


int main() {
    int T;
    int i, j;
    int n, s, p;
    int t;
    int best_not_surprising;
    int best_surprising;
    int result;

    fscanf(stdin, "%d\n", &T);
    for (i = 0; i < T; i++) {
        fscanf(stdin, "%d %d %d", &n, &s, &p);

        result = 0;
        for (j = 0; j < n; j++) {
            fscanf(stdin, "%d", &t);

            best_not_surprising = (t + 2) / 3;

            if (best_not_surprising >= p) {
                result++;
            } else if (s > 0) {
                if (((t % 3) != 1) && (best_not_surprising != 0)) {
                    best_surprising = best_not_surprising + 1;

                    if (best_surprising >= p) {
                        result++;
                        s--;
                    }
                }
            }
        }
        fprintf(stdout, "Case #%d: %d\n", i + 1, result);
    }

    return 0;
}
