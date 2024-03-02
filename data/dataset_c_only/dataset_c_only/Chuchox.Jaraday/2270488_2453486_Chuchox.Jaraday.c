#include <stdio.h>

int main(void){
    int cases, casos, i, j;
    int x, o, t, blanco;
    int ganax, ganao, encontrado;
    char tablero[4][4];

    scanf("%d\n",&cases);
    for(casos=1;casos<=cases;casos++){
            encontrado = 0;

        //Leemos el tablero
        blanco = x = o = t = 0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                tablero[i][j] = getchar();
                if(tablero[i][j] == '.'){
                    blanco++;
                }else if(tablero[i][j] == 'X'){
                    x++;
                }else if(tablero[i][j] == 'O'){
                    o++;
                }else{
                    t++;
                }
            }
            getchar();//no olvidar que se lee un espacio de nueva linea al final
        }
        getchar();//también se lee un espacio de separacion al final del tablero

        //Primero debemos tener las suficientes cosas para analizar
        if((x+t)<3){
            printf("Case #%d: Game has not completed\n",casos);
            continue;
        }

        //Comparamos por columnas
        for(i=0;i<4;i++){
            ganax = ganao = 0;
            for(j=0;j<4;j++){
                if(tablero[i][j] == 'X'){
                    ganax++;
                }else if(tablero[i][j] == 'O'){
                    ganao++;
                }else if(tablero[i][j] == 'T'){
                    ganax++;
                    ganao++;
                }
            }
            if(ganax == 4){
                printf("Case #%d: X won\n",casos);
                encontrado = 1;
            }else if(ganao == 4){
                printf("Case #%d: O won\n",casos);
                encontrado = 1;
            }
        }
        if(encontrado){
            continue;
        }

        //Comparamos por filas
        for(i=0;i<4;i++){
            ganax = ganao = 0;
            for(j=0;j<4;j++){
                if(tablero[j][i] == 'X'){
                    ganax++;
                }else if(tablero[j][i] == 'O'){
                    ganao++;
                }else if(tablero[j][i] == 'T'){
                    ganax++;
                    ganao++;
                }
            }
            if(ganax == 4){
                printf("Case #%d: X won\n",casos);
                encontrado = 1;
            }else if(ganao == 4){
                printf("Case #%d: O won\n",casos);
                encontrado = 1;
            }
        }
        if(encontrado){
            continue;
        }

        //Diagonal positiva
        ganax = ganao = 0;
        for(i=0;i<4;i++){
            if(tablero[i][i] == 'X'){
                ganax++;
            }else if(tablero[i][i] == 'O'){
                ganao++;
            }else if(tablero[i][i] == 'T'){
                ganax++;
                ganao++;
            }
        }
        if(ganax == 4){
            printf("Case #%d: X won\n",casos);
            encontrado = 1;
        }else if(ganao == 4){
            printf("Case #%d: O won\n",casos);
            encontrado = 1;
        }
        if(encontrado){
            continue;
        }

        //Diagonal negativa
        ganax = ganao = 0;
        for(i=0;i<4;i++){
            if(tablero[i][3-i] == 'X'){
                ganax++;
            }else if(tablero[i][3-i] == 'O'){
                ganao++;
            }else if(tablero[i][3-i] == 'T'){
                ganax++;
                ganao++;
            }
        }
        if(ganax == 4){
            printf("Case #%d: X won\n",casos);
            encontrado = 1;
        }else if(ganao == 4){
            printf("Case #%d: O won\n",casos);
            encontrado = 1;
        }
        if(encontrado){
            continue;
        }

        //verificando que el juego quedo en tablas o continua
        if(blanco > 1){
            printf("Case #%d: Game has not completed\n",casos);
        }else{
            printf("Case #%d: Draw\n",casos);
        }




    }
}
