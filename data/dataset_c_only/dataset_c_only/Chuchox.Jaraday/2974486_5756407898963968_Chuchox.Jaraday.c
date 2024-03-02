#include <stdio.h>

int main(void){
    int cases, casos, n, m, i, j, coincidencias, ganador;
    int c1[4][4], c2[4][4];

    scanf("%d",&cases);
    for(casos = 1;casos <= cases;casos++){
        //Primero leemos todos los datos
        scanf("%d",&n);
        for(i = 0;i < 4;i++){
            for(j = 0;j < 4;j++){
                scanf("%d",&c1[i][j]);
            }
        }
        scanf("%d",&m);
        for(i = 0;i < 4;i++){
            for(j = 0;j < 4;j++){
                scanf("%d",&c2[i][j]);
            }
        }
        //Ahora buscamos coincidencias
        coincidencias = 0;
        for(i = 0;i < 4;i++){
            for(j = 0;j < 4;j++){
                //printf("(%d,%d)=(%d,%d)    ",n-1,i,m-1,j);
                //printf("    %2d=%2d",c1[n-1][i],c2[m-1][j]);
                if(c1[n-1][i] == c2[m-1][j]){
                    ganador = c1[n-1][i];
                    coincidencias++;
                }
            }
        }
        //Imprimimos el resultado
        if(coincidencias == 0){
            printf("Case #%d: Volunteer cheated!\n",casos);
        }else if(coincidencias == 1){
            printf("Case #%d: %d\n",casos,ganador);
        }else{
            printf("Case #%d: Bad magician!\n",casos);
        }
    }

    return(0);
}
