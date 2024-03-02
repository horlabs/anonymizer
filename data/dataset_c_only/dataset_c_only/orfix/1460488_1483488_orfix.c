#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>

/* When in doubt, use brute force ! */

int main( void )
{
	int testcase = 0;
	int testcases;


	scanf("%d\n", &testcases);

	while (testcase < testcases) {
		int total= 0;
		int n, a, b;

		scanf("%d %d\n", &a, &b);

		for( n=a; n<=b; n++) {
			int i, s1, s2, m;
			int power = 10;
			int digits = floor(log10(n)+1);
			int previous[10] = {0};

			for( i=1; i<digits; i++, power*=10) {
				s1 = n/power;
				s2 = n%power;
				m = s1 + (s2 * pow(10,digits-i));

				if(n<m && m<=b) {
					int j = 0;

					for( ; j<i; j++) {
						if(m==previous[j]) {
							m=0;
							break;
						}
					}
					if( m ) {
						previous[i-1] = m;
						total++;
					}
				}
			}
		}

		printf("Case #%d: %d\n",++testcase, total);
	}

	return 0;
}
