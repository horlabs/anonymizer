#include  <stdio.h>
#include  <stdlib.h>

#define  N	99
#define  M	99
#define  NO  0
#define  YES 1

int main( void )
{
	freopen("B-small-attempt0.in","r",stdin);

	int testcase = 0;
	int testcases;

	scanf("%d\n", &testcases);

	while (testcase < testcases) {
		int n, m;
		int i, j;
		int lawn[N][M];
		int res = YES; /* Assume it's possible... */

		scanf("%d %d\n", &n, &m);
		/* load lawn into memory */
		for( i=0; i<n; i++) {
			for( j=0; j<m; j++) {
				scanf("%d", &lawn[i][j]);
			}
			getchar(); /* consume the \n */
		}
		/* ... then proove it's impossible (the hard way)*/
		for( i=0; i<n && res==YES; i++) {
			for( j=0; j<m && res==YES; j++) {
				int i_res = YES;
				int j_res = YES;
				int ii, jj;

				for( ii=0; ii<n; ii++) {
					if(lawn[ii][j]>lawn[i][j]) i_res = NO;
				}
				for( jj=0; jj<m; jj++) {
					if(lawn[i][jj]>lawn[i][j]) j_res = NO;
				}
				if( i_res==NO && j_res==NO) res = NO;
			}
		}


		printf("Case #%d: %s\n",++testcase, res ? "YES" : "NO" );
	}

	return 0;
}
