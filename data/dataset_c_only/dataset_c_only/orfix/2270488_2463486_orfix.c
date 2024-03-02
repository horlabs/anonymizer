#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

#define  LEN 1024
#define  EPSILON 0.000000000000000001L

char is_palindrome( unsigned long long i) 
{
	int ret = 1;
	char s[LEN] = "";

	if(sprintf(s, "%llu",i)>0) {
		unsigned int l = strlen(s);

		for( i=0; i < (l/2)+1 && ret; i++) {
			if(s[i]!=s[l-i-1]) ret = 0;
		}
	}

	return ret;
}

int main( void )
{
	freopen("C-small-attempt0.in","r",stdin);

	int testcase = 0;
	int testcases;

	scanf("%d\n", &testcases);

	while (testcase < testcases) {
		unsigned long long int res = 0;
		unsigned long long int a, b;

		scanf("%llu %llu\n", &a, &b);

		for( ; a<=b; a++) {
			if(is_palindrome(a)) {	/* PALINDROME */
				long double root = sqrtl(a);

				if( root-(long long int)root < EPSILON ) {	/* SQUARE */
					if(is_palindrome((unsigned long long) root)) res++;  /* ROOT SQUARE IS PALINDROME ! */
				}
			}
		}

		printf("Case #%d: %llu\n", ++testcase, res);
}

	return 0;
}
