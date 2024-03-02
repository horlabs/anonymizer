#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeABValues(int A, int B, int* ms, int* res)
{
	char nstr[20];
	int n, m, d, i, j, cands;

	sprintf(nstr, "%d%d", A, A);
	d = strlen(nstr) / 2;
	*res = 0;
	for (n = A; n < B; n++)
	{
		cands = 0;
		for (i = 1; i < d; i++)
		{
			nstr[i + d] = 0;
			sscanf(nstr + i, "%d", &m);
			nstr[i + d] = nstr[i];
			if (n < m && m <= B)
			{
				for (j = 0; j < cands; j++)
					if (ms[j] == m)
						break;
				if (j == cands)
				{
					ms[cands++] = m;
					(*res)++;
				}
			}
		}
		for (i = d - 1; i >= 0; i--)
		{
			if (nstr[i] == '9')
				nstr[i] = nstr[i + d] = '0';
			else
			{
				nstr[i]++;
				nstr[i + d]++;
				break;
			}
		}
	}
}

int main()
{
	int T, tcase, A, B, res, m;
	int ms[10];

	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%d", &A);
		scanf("%d", &B);
		computeABValues(A, B, ms, &res);
		printf("Case #%d: %d\r\n", tcase, res);
	}

	return 0;
}
