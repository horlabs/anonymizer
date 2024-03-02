#include <stdio.h>
#include <stdlib.h>

int next(int n)
{
	int x = 1;
	while(n/x >= 10)
		x *= 10;
	while(n%10 == 0)
		n = n/10;
	n = n/10 + (n%10)*x;
	return n;
}

int main()
{
	int cas, a, b, i, j, tmp, ans;
	scanf("%d", &cas);
	for(i=1; i<=cas; i++)
	{
		scanf("%d %d", &a, &b);
		ans = 0;
		for(j=a; j<=b; j++)
		{
			tmp = j;
			do
			{
				tmp = next(tmp);
				if(tmp > j && tmp >= a && tmp<= b)
					ans++;
			}while(tmp != j);
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
