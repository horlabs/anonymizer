#include <stdio.h>
#include <stdlib.h>

#define CHECK_CONDITION(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }

typedef struct {
    int rows[101];
    int cols[101];
} Matrix;

void readLine()
{
    while(getchar()!='\n')
        ;
}

void readMatrix(Matrix *matrix, int rows, int cols)
{
    int i,j;

    for(i=0;i<rows;i++)
    {
        matrix->rows[i]=0;
        for(j=0;j<cols;j++)
        {
            scanf("%d",&(matrix->cols[j]));
            if(matrix->rows[i]<matrix->cols[j])
                matrix->rows[i]=matrix->cols[j];
        }
    }
}

int checkMatrix(Matrix *matrix, int rows, int cols)
{
    int i, j;

    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            if(matrix->cols[j]<matrix->rows[i] && matrix->cols[j]<matrix->rows[i])
                return 0;

    return 1;
}

int main()
{
    int i, j, tcase, T, N, M, res;
    Matrix matrix;

    scanf("%d",&T);
    for(tcase=1;tcase<=T;tcase++)
    {
        scanf("%d",&N);
        scanf("%d",&M);
        res=1;

        readMatrix(&matrix, N, M);

        res = checkMatrix(&matrix, N, M);

        printf("Case #%d: %s\n",tcase,res?"YES":"NO");
    }

    return 0;
}