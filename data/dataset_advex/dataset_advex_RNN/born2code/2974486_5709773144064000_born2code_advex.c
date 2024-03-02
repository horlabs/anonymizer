#include <stdio.h>


void compute(double C, double F, double X) {
    int i, j, k;
    double min, temp;
    temp = X / 2.0;
    k = 0;
    do {
        min = temp;
        temp = 0;
        for (i = 0; i < k; i++) {
            temp = temp + C / (i * F + 2);
        }
        temp = temp + X / (i * F + 2);
        k++;
    } while (temp <= min);
    printf("%f\n", min);
}

int main() {
    int t, T;
    double C, F, X;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%lf%lf%lf", &C, &F, &X);
        printf("Case #%d: ", t);
        compute(C, F, X);
    }
    return 0;
}
