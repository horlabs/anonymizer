#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double l;
    double r;
} Interval;

double binarySearchTime(double C, double F, double X) {
    double m;
    int i,j;
    double buildTime;
    double ans;
    Interval interval;
    
    interval.l = eps;
    interval.r = X;
    
    while(interval.l + eps <= interval.r){
        m = (interval.l + interval.r)/2;
        for(j=0;;++j){
            for(i=buildTime=0;i<j;++i){
                buildTime += C/(2.0 + F * i);
            }
            if( (buildTime >= m) || (m - buildTime) * (2.0 + F * j) >= X ){
                break;
            }
        }
        if(buildTime >= m){
            interval.l = m + eps;
        } else {
            if(m < ans) ans = m;
            interval.r = m - eps;
        }
    }
    return ans;
}

int main(){
    int t, T;
    double C, F, X;
    scanf("%d", &T);
    for(t = 1; t <= T; ++t){
        scanf("%lf %lf %lf", &C, &F, &X);
        printf("Case #%d: %.7lf\n",t, binarySearchTime(0.0, X/2.0));
    }
    return 0;
}