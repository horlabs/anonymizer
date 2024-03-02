#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int T,
		i,j,k,b,
		row,
		board[4][4],
		psb,
		ans,
		num[16];
	FILE *fin=fopen("A-small-attempt0.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%d",&T);

	for(k=0;k<T;k++) {
		for(i=0;i<16;num[i++]=0);
		for(b=0;b<2;b++) {
			fscanf(fin,"%d",&row);
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					fscanf(fin,"%d",&(board[i][j]));
			for(i=0;i<4;i++)
				num[board[row-1][i]-1]+=1;
		}
		for(psb=i=0;i<16;i++)
			if(num[i]==2) psb+=1,ans=i+1;
		fprintf(fout,"Case #%d: ",k+1);
		if(psb==1) fprintf(fout,"%d\n",ans);
		else fprintf(fout,"%s\n",psb>1?"Bad magician!":"Volunteer cheated!");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
