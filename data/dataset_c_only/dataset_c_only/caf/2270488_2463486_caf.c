#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int is_fair(int n)
{
	if (n < 10)
		return 1;

	if (n < 100)
		return (n % 11) == 0;

	if (n < 1000)
		return (n / 100) == (n % 10);

	return 0;
}	

int is_square(int n)
{
	int root = sqrt(n);

	if (root * root == n)
		return root;

	return 0;
}

void do_test(int t)
{
	int a, b;
	int i;
	int n = 0;

	scanf("%d%d", &a, &b);

	for (i = a; i <= b; i++)
	{	
		int root;

		if (is_fair(i) && (root = is_square(i)) && is_fair(root))
			n++;
	}

	printf("Case #%d: %d\n", t + 1, n);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}