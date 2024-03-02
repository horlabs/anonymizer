#include <stdio.h>

double calculate_time(double c, double f, double x) {
    double rate = 2;
    double time = 0;
    while (x / rate > (x / (rate + f) + c / rate)) {
        time += c / rate;
        rate += f;
    }
    return x / rate + time;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    for (int i = 0; i < num_cases; i++) {
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);

        double result = calculate_time(c, f, x);

        printf("Case #%d: %1.7lf\n", i + 1, result);
    }

    return 0;
}