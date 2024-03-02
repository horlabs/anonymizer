#include <stdio.h>
#include <stdlib.h>

double calculateResult(double c, double f, double x)
{
    double temp = 0;
    double r = 2.0;

    if (x <= c)
    {
        return x / r;
    }

    while (temp + x / r > temp + c / r + x / (r + f))
    {
        temp += c / r;
        r += f;
    }

    return temp + x / r;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++)
    {
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);

        double result = calculateResult(c, f, x);

        printf("Case #%d: %.07lf\n", i, result);
    }

    return 0;
}