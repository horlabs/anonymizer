#include <stdio.h>
#include <string.h>
#include <assert.h>


void solve(int c, double C, double F, double X)
{
    double t=0, rate=2;

    while((X/rate) > (X/(rate+F) + (C/rate)))
    {
        t=t+C/rate;
        rate=rate+F;
        //printf("buy one farm at time %lf new rate %lf\n",t,rate);
    }
    //printf("last time %lf / %lf + %lf\n",X,rate,X/rate);
    t=t+X/rate;
    printf("Case #%d: %.7lf\n",c,t);
}

int main(int argc, char **argv)
{
    int t,i;
    double C,F,X;
    
    assert (scanf("%d ",&t) == 1); //Number of testcases
    for(i=1;i<=t;i++)
    {
        assert (scanf("%lf %lf %lf ",&C, &F, &X) == 3);
        solve(i, C, F, X);
    }
    return 0;
}
