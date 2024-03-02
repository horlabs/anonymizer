#include <stdio.h>

int main(void){
    int cases, casos, i, j, n, m;
    int a, poder;
    int pasto[100][100];

    scanf("%d",&cases);
    for(casos=1;casos<=cases;casos++){
        //Comenzamos leyendo la dimención y el arreglo en si
        scanf("%d %d\n",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&pasto[i][j]);
            }
        }

        /*//Ahora imprimimos para buscar el error
        printf("\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d ",pasto[i][j]);
            }
            printf("\n");
        }*/
        //Si alguno de los anchos del pasto es igual o menor que uno, no es necesario probar algo, obviamente se puede
        if((n<2)||(m<2)){
            printf("Case #%d: YES\n",casos);
            continue;
        }

        //Ahora estamos seguros de hacer una prueva, cuadro por cuadro
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                //Primero de arriva a abajo
                poder = 1;
                for(a=0;a<n;a++){
                    if(pasto[i][j] < pasto[a][j]){
                        poder = 0;
                        break;
                    }
                }
                if(poder){
                    continue;
                }
                //Ahora de izquierda a derecha
                poder = 1;
                for(a=0;a<m;a++){
                    if(pasto[i][j] < pasto[i][a]){
                        poder = 0;
                        break;
                    }
                }
                if(poder){
                    continue;
                }
                //Si no se pudo
                break;
            }
            if(!poder){
                break;
            }
        }
        if(poder){
            printf("Case #%d: YES\n",casos);
        }else{
            //printf("Case #%d: NO (%d,%d)\n",casos,i,j);
            printf("Case #%d: NO\n",casos);
        }
    }
    return(0);
}

