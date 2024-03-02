#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void Merge(int A[], int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1], R[n2+1];
	int i, j, k;
	for (i=0; i<n1; i++) L[i] = A[p+i];
	for (j=0; j<n2; j++) R[j] = A[q+j+1];
	
	i=0; j=0;
	for (k=p; k<=r; k++){
		if (i<n1 && j<n2){
			if (L[i] <= R[j]){ A[k]=L[i]; i++; }
			else{ A[k]=R[j]; j++; }
		}
		else if (i<n1){ A[k]=L[i]; i++; }
		else{ A[k]=R[j]; j++; }
	}
}

void Partition(int A[], int p, int r)
{
	if (p<r){
		int q = (p+r)/2;
		Partition(A, p, q);
		Partition(A, q+1, r);
		Merge(A, p, q, r);
	}
}

int main(){
	FILE *fin, *fout;
	fin = freopen("B-small-attempt0.in", "r", stdin);
	fout = freopen("B-small-attempt0.out", "w", stdout);
	
	int TestCases, t, i;
	scanf("%d", &TestCases);
	int Number, Surprise, StdScore, Answer, Score[100000], Highest;
	
	for (t=1; t<=TestCases; t++){
		Answer=0;
		scanf("%d%d%d", &Number, &Surprise, &StdScore);
		for (i=0; i<Number; i++) scanf("%d", &Score[i]);
		Partition(Score, 0, Number-1);
		
		for (i=Number-1; i>=0; i--){
			if (Score[i]==0){
				if (StdScore==0) Answer++;
				continue;
			}
			
			
			if ((Score[i]%3)==0){
				Highest = Score[i]/3;
				if (Highest>=StdScore) { Answer++;}
				else if (Surprise) {
					Highest++;
					if (Highest>=StdScore) { Answer++; Surprise--;}
				}
				continue;
			}
			
			if ((Score[i]%3)==1){
				Highest = (Score[i]+2)/3;
				if (Highest>=StdScore) Answer++;
				continue;
			}
			
			if ((Score[i]%3)==2){
				Highest = (Score[i]+1)/3;
				if (Highest>=StdScore) { Answer++;}
				else if (Surprise) {
					Highest++;
					if (Highest>=StdScore) { Answer++; Surprise--;}
				}
				continue;
			}
		}
		
		
		printf("Case #%d: %d\n", t, Answer);
		
		
	}
	
	
	fclose(fin);
	fclose(fout);
	//system("Pause");
	return 0;
}
