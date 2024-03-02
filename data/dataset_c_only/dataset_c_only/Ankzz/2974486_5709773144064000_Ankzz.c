#include <stdio.h>

#define fr(x,N) for(x=0;x<N;x++)
#define fr1(x,N) for(x=1;x<=N;x++)

int
main(int argc, char *argv[])
{
	FILE *fp,*o;
	fp = (argc<=1)?fopen("input.txt", "r+"):fopen(argv[1],"r+");
	o = fopen("output.txt","w+");

	if(fp) {
		int T;
		int i;
		int j,k;
		fscanf(fp,"%d",&T);
		fr(i,T) {
			float C, F, X; // C=> BasePrice F=> Cookie Increment X => Target
			double time = 0; float rate = 2;
			fscanf(fp,"%f %f %f", &C, &F, &X);
			//printf("%.7f %.7f %.7f\n", C, F, X);

			while(X) {
				double intervalForFarmBuying = 0, intervalWithCurrRate = 0;
				double nextIntervalRate = 0;

				intervalForFarmBuying = (double)(C / rate);

				intervalWithCurrRate = (double)(X / rate);

				if( intervalForFarmBuying >= intervalWithCurrRate ) {
					time += intervalWithCurrRate;
					//printf("Interval : %.7f %.7f %.7f\n", intervalForFarmBuying, intervalWithCurrRate, time);
					//printf("Final : %.7f %.7f\n", intervalWithCurrRate, time);
					break;
				}
				nextIntervalRate = (double)( X / (rate + F));

				if( (intervalWithCurrRate + time) <=
					(time + intervalForFarmBuying + nextIntervalRate) ) {
					//printf("Interval : %.7f %.7f %.7f %.7f\n",
					//		intervalForFarmBuying,
					//		intervalWithCurrRate,
					//		time,
					//		nextIntervalRate);
					time += intervalWithCurrRate;
					//printf("Interval : %.7f %.7f %.7f\n", intervalForFarmBuying, intervalWithCurrRate, time);
					//printf("Final : %.7f %.7f\n", intervalWithCurrRate, time);
					break;
				}

				time += intervalForFarmBuying;
				//printf("Interval : %.7f %.7f %.7f\n", intervalForFarmBuying, intervalWithCurrRate, time);
				rate += F;
				//getch();
			}

			fprintf(o,"Case #%d: %.7f\n",i+1, time );
		}
	}

	return 0;
}