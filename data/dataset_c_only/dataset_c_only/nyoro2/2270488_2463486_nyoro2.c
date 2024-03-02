//
// qual_c.c
//

#include <stdio.h>


int main()
{
	int i;
	int t;
	long long num_a;
	long long num_b;
	long long num_x;
	long k;
	long k_min;
	long k_max;
	char num_buf[16];
	int l, l_max;
	int m, m_max;
	int result;

	fscanf(stdin,"%d\n",&t);
	for(i = 0; i < t; i++) {
		fscanf(stdin,"%lld %lld",&num_a,&num_b);
//		fprintf(stderr,"%lld %lld\n",num_a,num_b);
		fprintf(stdout,"Case #%d: ",i+1);
		k_min = sqrt((double)num_a) - 1;
		k_max = sqrt((double)num_b) - 1;
//		fprintf(stderr,"%ld %ld\n",k_min,k_max);
		num_x = k_min + 1;
		num_x = num_x * num_x;
		if(num_x < num_a) {
			k_min++;
			num_x += (k_min * 2 + 1);
		}
		result = 0;
//		fprintf(stderr,"start with %lld\n",num_x);
		for(k = k_min + 1; k <= k_max + 1; k++) {
			sprintf(num_buf, "%lld", num_x);
			l_max = strlen(num_buf);
			for(l = 0; l < l_max/2; l++) {
				if(num_buf[l] != num_buf[l_max-l-1]) break;
			}
			if(l >= l_max/2) {
				sprintf(num_buf, "%ld", k);
				m_max = strlen(num_buf);
				for(m = 0; m < m_max/2; m++) {
					if(num_buf[m] != num_buf[m_max-m-1]) break;
				}
				if(m >= m_max/2) {
//					fprintf(stderr, "%ld^2 = %lld\n", k, num_x);
					result++;
				}
			}
			num_x += (k * 2 + 1);
		}
		fprintf(stdout, "%d", result);
		fprintf(stdout,"\n");
	}

	return 0;
}

// End of qual_c.c
