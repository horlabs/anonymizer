#include <stdlib.h>
#include <stdio.h>

struct LawnSquare {
	int i,j,dH,good;
};

int cmp(const void *elem1, const void *elem2) {
	return ((struct LawnSquare*)elem1)->dH - ((struct LawnSquare*)elem2)->dH;
}

int main(void) {
	int i,j,z,k,N,M,T,row,column,good,height;
	struct LawnSquare lawn[100][100],lawnStraight[10000];
	FILE *fin=fopen("B-small-attempt0.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%d",&T);
	//printf("T: %d\n",T);

	for(k=0;k<T;k++) {
		fscanf(fin,"%d%d",&N,&M);
		for(i=0;i<N;i++)
			for(j=0;j<M;j++) {
				lawn[i][j].i=i;
				lawn[i][j].j=j;
				lawn[i][j].good=0;
				fscanf(fin,"%d",&(lawn[i][j].dH));
			}
		/*
		printf("\nlawn:\n");
		for(i=0;i<N;i++)
			for(j=0;j<M;j++)
				printf("%d%c",lawn[i][j].dH,j==M-1?'\n':'\t');
		*/

		for(z=i=0;i<N;i++)
			for(j=0;j<M;j++) {
				lawnStraight[z].i=lawn[i][j].i;
				lawnStraight[z].j=lawn[i][j].j;
				lawnStraight[z].good=lawn[i][j].good;
				lawnStraight[z].dH=lawn[i][j].dH;
				z++;

		}
		/*
		printf("\nlawnStraight:\n");
		for(i=0;i<z;i++)
			printf("%d\t",lawnStraight[i].dH);
		*/

		qsort(lawnStraight,z,sizeof(struct LawnSquare),cmp);

		/*
		printf("\nlawnStraight after qsort:\n");
		for(i=0;i<z;i++)
			printf("%d\t",lawnStraight[i].dH);
		*/

		for(i=0,good=1;i<z && good;i++) {
			height=lawnStraight[i].dH;
			row=lawnStraight[i].i;
			column=lawnStraight[i].j;

			//check row
			for(j=0;j<M && lawn[row][j].dH<=height;j++);
			if(j==M) good=1;
			else { //check column
				for(j=0;j<N && lawn[j][column].dH<=height;j++);
				if(j==N) good=1;
				else good=0;
			}

		}
	
		fprintf(fout,"Case #%d: %s\n",k+1,good==1?"YES":"NO");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

