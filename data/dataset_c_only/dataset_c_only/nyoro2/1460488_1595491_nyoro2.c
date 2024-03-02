//
// gcj_b.c
//

#include <stdio.h>


int main()
{
	int T;
	int i,j;
	int n,s,p;
	int t;
	int best_not_surprising;
	int best_surprising;
	int result;

	fscanf(stdin,"%d\n",&T);
	for(i = 0; i < T; i++) {
		fscanf(stdin,"%d %d %d",&n,&s,&p);
//		fprintf(stderr,"n=%d,s=%d,p=%d\n",n,s,p);
		result = 0;
		for(j = 0; j < n; j++) {
			fscanf(stdin,"%d",&t);
//			fprintf(stderr,"t=%d\n",t);
			best_not_surprising = (t+2)/3;
//			fprintf(stderr,"best result not surprising=%d\n",best_not_surprising);
			if(best_not_surprising >= p) {
				result++;
			} else if(s > 0) {
				if(((t%3) != 1) && (best_not_surprising != 0)) {
					best_surprising = best_not_surprising + 1;
//					fprintf(stderr,"best result surprising=%d\n",best_surprising);
					if(best_surprising >= p) {
						result++;
						s--;
					}
				}
			}
		}
		fprintf(stdout,"Case #%d: %d\n",i+1,result);
	}

	return 0;
}

// End of gcj_b.c
