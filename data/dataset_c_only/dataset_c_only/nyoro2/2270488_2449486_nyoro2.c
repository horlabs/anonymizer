//
// qual_b.c
//

#include <stdio.h>


int main()
{
	int t;
	int i;
	int n,m;
	int l,k;
	int l2,k2;
	int lawn_ptn[128][128];
	int lawn_ref;
	int result;

	fscanf(stdin,"%d\n",&t);
	for(i = 0; i < t; i++) {
		fscanf(stdin,"%d %d\n",&n,&m);
//		fprintf(stderr,"%d %d\n",n,m);
		fprintf(stdout,"Case #%d: ",i+1);
		// data input
		for(l = 0; l < n; l++) {
			for(k = 0; k < m; k++) {
				fscanf(stdin,"%d",&(lawn_ptn[l][k]));
//				fprintf(stderr,"%d ",lawn_ptn[l][k]);
			}
//			fprintf(stderr,"\n");
		}
		// data check
		result = 1;
		for(l = 0; l < n; l++) {
			for(k = 0; k < m; k++) {
				lawn_ref = lawn_ptn[l][k];
				for(l2 = 0; l2 < n; l2++) {
					if(lawn_ptn[l2][k] > lawn_ref) break;
				}
				if(l2 < n) {
					for(k2 = 0; k2 < m; k2++) {
						if(lawn_ptn[l][k2] > lawn_ref) break;
					}
					if(k2 < m) {
						result = 0;
						goto out_result;
					}
				}
//				fprintf(stderr,"(%d,%d) : OK\n",k,l);
			}
		}
out_result:
		fprintf(stdout, "%s",result?"YES":"NO");
		fprintf(stdout,"\n");
	}

	return 0;
}

// End of qual_b.c
