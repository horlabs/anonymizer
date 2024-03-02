#include<stdio.h>
int main()
{
	float C,F,X;
	float time,x_bak,x;
	float f,time_tot,prev_time;
	int brk,t,T;
	FILE *fp1,*fp2;
	fp1=fopen("B-small-attempt0.in","r");
	fp2=fopen("cookie_out.txt","w");
	fscanf(fp1,"%d",&T);
	//printf("%d\n",T);
	t=1;
	while(t<=T){
	
	x_bak=X;
	//printf("Enter\n");
	fscanf(fp1,"%f %f %f",&C,&F,&X);
	time=time_tot=prev_time=0.0;
	f=2.0;
	
		if(X<C)
		{
			time=X/f;
		}
		//		time=time+C/f;
//		f=f+F;
//		X=X-C;
		else{
		x=0;
		time=C/f;
		time_tot=C/f+X/(f+F);
		x=x+C;
		//printf("x is %f\n",x);
		//printf("tot_time is %f\n",time_tot);
		brk=0;
		while(x<X)
		{
			prev_time=time_tot;
			f=f+F;
			time=time+C/f;
			time_tot=time+X/(f+F);
			x=x+C;
		//	printf("x is %f\n",x);
		//	printf("tot_time is %f\n",time_tot);
			if(time_tot>prev_time)
			{
				time=prev_time;
		//		printf("break %f\n",x);
				brk=1;
				break;
			}
		}
		if(!brk)
			time=time_tot;
		}
		if(t==T)
		fprintf(fp2,"Case #%d: %f",t,time);
		else
		fprintf(fp2,"Case #%d: %f\n",t,time);
		t++;
	}
		
		fclose(fp1);
		fclose(fp2);
	return 0;
}
