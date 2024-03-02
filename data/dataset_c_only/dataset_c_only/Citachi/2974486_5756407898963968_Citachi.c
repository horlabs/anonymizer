#include<stdio.h>
#define R 4
#define C 4
//t is_null_matrix(int [][C],int [][C]);
//int find_selected_number(int [][],int [][]);
int main()
{
	int a[R][C],b[R][C];
	FILE *fp1,*fp2;
	fp1=fopen("A-small-attempt2.in","r");
	fp2=fopen("magic_out.txt","w");
	int r1,r2,i,j,count,y,t,T;
	fscanf(fp1,"%d",&T);
	//printf("%d\n",T);
	t=1;
	while(t<=T)
	{
		fscanf(fp1,"%d",&r1);
		//printf("%d\n",r1);
		for(i=0;i<R;i++)
		{
			//for(j=0;j<C;j++)
				fscanf(fp1,"%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
			//printf("%d %d %d %d\n",a[i][0],a[i][1],a[i][2],a[i][3]);
		}
        fscanf(fp1,"%d",&r2);
		for(i=0;i<R;i++)
		{
				fscanf(fp1,"%d %d %d %d",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);
		}
		count=0;
		for (i=0;i<C;i++){
			for(j=0;j<C;j++)
			{
				if(a[r1-1][i]==b[r2-1][j])
				{
					count++;
					//printf("%d\n",b[r2-1][j]);
					y=a[r1-1][i];
				}	
			}
	   }
		//printf("%d\n",count);
		if(t==T)
		{
			if(count==1)
				fprintf(fp2,"Case #%d: %d",t,y);
			else if(count>1)
				fprintf(fp2,"Case #%d: Bad magician!",t);
			//else if(count == 0 && r1==r2)
			//	fprintf(fp2,"Case #%d: Bad magician!",t);
			else
				fprintf(fp2,"Case #%d: Volunteer cheated!",t);

		}
		else
		{
			if(count==1)
				fprintf(fp2,"Case #%d: %d\n",t,y);
			else if(count>1)
				fprintf(fp2,"Case #%d: Bad magician!\n",t);	
			//else if(count == 0 && r1==r2)
				//fprintf(fp2,"Case #%d: Bad magician!\n",t);
			else
				fprintf(fp2,"Case #%d: Volunteer cheated!\n",t);

		}
			
		t++;
	}
		fclose(fp1);
		fclose(fp2);
		return 0;
}


