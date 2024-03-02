#include <stdio.h>
#include <math.h>

int main(void){
    int cases, min, max, num, cand;
    int ndigit, potencia, temp;
    int i, j, total;
    int k, enc, nenc;
    int encontrados[10];
    scanf("%d",&cases);
    for(i=1;i<=cases;i++){
        scanf("%d",&min);
        scanf("%d",&max);
        //first calculating the number of digits
        j = max;
        ndigit = 0;
        potencia = 1;
        while(j){
            j /= 10;
            ndigit++;
            potencia *= 10;
        }
        potencia /= 10;
        //now recyclated the numbers and compare
        total = 0;
        for(num = min;num<max;num++){
            cand = num;
            k = nenc = 0;
            for(j=1;j<ndigit;j++){
                temp = cand % 10;
                cand /= 10;
                cand += (temp*potencia);
                if((num < cand)&&(cand <= max)){
                    enc = 1;
                    for(k = 0;k<nenc;k++){
                        if(cand == encontrados[k]){
                            enc = 0;
                        }
                    }
                    if(enc){
                        encontrados[nenc] = cand;
                        nenc++;
                        total++;
                        //printf("%d:  %d < %d < %d < %d\n",total,min,num,cand,max);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",i,total);
    }
    return 0;
}
