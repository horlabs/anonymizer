#include <stdio.h>

int main(void){
    int t, casos, i, j;
    double c, f, x;
    double vel, tiempo1, tiempo2, acumulado, total, totalant;

    scanf("%d\n",&t);
    for(casos = 1;casos <= t;casos++){
        //inicializamos
        scanf("%lf %lf %lf\n",&c,&f,&x);
        //printf("%lf %lf %lf\n",c,f,x);
        vel = 2.0;
        acumulado = 0.0;
        //Calculando
        total = 0.0;
        acumulado = 0.0;
        totalant = x;
        do{
            tiempo1 = x / vel;
            tiempo2 = c / vel;
            total = acumulado + tiempo1;
            acumulado += tiempo2;
            vel += f;
            //printf("  %12lf %12lf %12lf %12lf\n",tiempo1,tiempo2,acumulado,total);
            if(totalant < total){
                break;
            }else{
                totalant = total;
            }
        }while(1);
        //imprimiendo
        printf("Case #%d: %.7lf\n",casos,totalant);
    }

    return(0);
}
