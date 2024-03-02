#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double time_to_buy(long n_farms, double c, double f)
{
	if (n_farms > 0)
		return c / ((n_farms - 1) * f + 2.0) + time_to_buy(n_farms - 1, c, f);
	return 0;
}

void do_test(int t)
{
	long n_farms;
	double c, f, x;
	double time = 0.0;

	scanf("%lf %lf %lf", &c, &f, &x);

	n_farms = x / c - 2.0/f;
	if (n_farms < 0)
		n_farms = 0;
	time = time_to_buy(n_farms, c, f) + x / (n_farms * f + 2.0);

	printf("Case #%d: %.7f\n", t + 1, time);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
