#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(){
	FILE *fin, *fout;
	fin = freopen("C-small-attempt0.in", "r", stdin);
	fout = freopen("C-small-attempt0.out", "w", stdout);
	
	int TestCases, t, A, B, i, m, n, P10, P, Answer, Number[10];
	scanf("%d", &TestCases);
	for (t=1; t<=TestCases; t++){
		Answer=0;
		scanf("%d%d", &A, &B);
		if (B<21) {printf("Case #%d: 0\n", t); continue;}
		
		for (i=A; i<B; i++){
			Number[0]=i;
			P10 = 0;
			P=1;
			while(Number[0]/=10) {
				P10++;
				P*=10;
			}
			Number[0]=i;
			for (n=1; n<=P10; n++) Number[n] = Number[n-1]/P + 10*(Number[n-1]%P);
				
			for (m=0; m<P10; m++) for (n=m+1; n<=P10; n++) if (Number[n]==Number[m]) Number[n]=0;
			for (m=1; m<=P10; m++){
				if (Number[m]<=i) { Number[m]=0; continue; }
				if (Number[m]>B) { Number[m]=0; continue; }
				if (Number[m]<A) { Number[m]=0; continue; }
				if (Number[m]>0) { Answer++; continue; }
			}
			
			
		}
		
		printf("Case #%d: %d\n", t, Answer);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
