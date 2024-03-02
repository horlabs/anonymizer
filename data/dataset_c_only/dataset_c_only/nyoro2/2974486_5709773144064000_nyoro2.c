//
// qual_b.c
//

#include <stdio.h>


int main()
{
	int t;
	int i;
	double c, f, x;
	double time_base;
	double time1, time2;
	int j;

	fscanf(stdin,"%d\n",&t);
	for(i = 0; i < t; i++) {
		// input data
		fscanf(stdin,"%lf %lf %lf\n",&c,&f,&x);
		// show parameter
//		fprintf(stderr, "%.7f %.7f %.7f\n",c,f,x);
		// calc time
		time_base = 0;
		j = 0;
		while(1) {
			time1 = time_base + x/(f*j+2);
			time_base += c/(f*j+2);
			j++;
			time2 = time_base + x/(f*j+2);
			if(time1 <= time2) break;
		}
		// output result
		printf("Case #%d: ", i+1);
		printf("%.7f\n",time1);
	}

	return 0;
}

// End of qual_b.c
