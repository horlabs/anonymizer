#include<stdio.h>

#define READ( x )        fscanf( fp, "%d", &x )
#define READC( x )        fscanf( fp, "%c ", &x )
#define READ2( x, y)    fscanf( fp, "%d %d", &x, &y)

int isMatrixSane(int **matrix, int rows, int cols){
    int i, j, prev;
    int sane = 1;
    
    // Check rows
    for(i=0; i<rows; i++) {
        prev = -1;
        for(j=0; j<cols; j++) {
            int p = matrix[i][j];
            if(prev == -1)
                prev = p;
            else {
                if(i!=0 && j!=0 && i!=rows-1 && j!=cols-1 && p< prev) {
                    sane = 0;
                    break;
                }
            }
        }
        if(sane==0)
            break;
    }
    
    // Check columns
    if( sane ) {
        for(j=0; j<cols; j++) {
            prev = -1;
            for(i=0; i<rows; i++) {
                int p = matrix[i][j];
                if(prev == -1)
                    prev = p;
                else {
                    if(i!=0 && j!=0 && i!=rows-1 && j!=cols-1 && p< prev) {
                        sane = 0;
                        break;
                    }
                }
            }
        }
    }
    
    return sane;
}

int main()
{
    int T=-1;
    int c=0;
    char dummy[100];
    
    FILE *fp = fopen("B-small-attempt3.in","r");
    
    FILE *fo = fopen("output.txt","w");
    
    READ( T );
    
    while(++c<=T) {
        int x,y;
        int i,j;
        int sane = 1;
        int **matrix;
        int *rows;
        
        READ2( x, y);
        
        matrix = (int**)malloc(x*sizeof(int*));
        for(i=0; i<x; i++) {
            matrix[i] = (int*)malloc(y*sizeof(int));
            for(j=0; j<y; j++) {
                int p;
                READ(p);
                matrix[i][j] = p;
            }
        }
        
        int sanity = isMatrixSane(matrix, x, y);
        fprintf(fo,"Case #%d: %s\n", c, (sanity)?"YES":"NO");
    }

    fclose(fp);
    fclose(fo);
    return 0;
}