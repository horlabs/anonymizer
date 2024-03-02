#include <stdio.h>

double calculateEfficiency(double c, double f, double x) {
    double rez = 0;
    int k = x / c - 2 / f;

    if (k < 0)
        k = 0;

    rez = x / (2 + k * f);

    while (k > 0) {
        k--;
        rez += c / (2 + k * f);
    }

    return rez;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);

        double efficiency = calculateEfficiency(c, f, x);

        printf("Case #%d: %.7lf\n", t, efficiency);
    }

    return 0;
}