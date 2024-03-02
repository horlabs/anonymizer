#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *dtgF_Var, *rffF_Var;
  int a[10][10], wlyi_Var, N, M, i, j, zjfi_Var, flag = 0;
  dtgF_Var = fopen("B-small-attempt1.in", "r");
  rffF_Var = fopen("output.txt", "w");
  fscanf(dtgF_Var, "%d", &wlyi_Var);
  for (int qnhi_Var = 1; qnhi_Var <= wlyi_Var; qnhi_Var++) {
    flag = 0;
    fscanf(dtgF_Var, "%d %d", &N, &M);
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++) {
        fscanf(dtgF_Var, "%d", &a[i][j]);
      }
    }
    for (i = 0; i < N; i++) {
      zjfi_Var = a[i][0];

      {
        j = 0;
        while (j < M) {
          if (a[i][j] != 0) {
            a[i][j] = (int)abs(zjfi_Var - a[i][j]);
          }
          j++;
        }
      }
    }

    for (j = 0; j < M; j++) {
      zjfi_Var = a[0][j];
      for (i = 0; i < N; i++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(zjfi_Var - a[i][j]);
        }
      }
    }

    {
      i = 0;
      for (; i < N;) {
        zjfi_Var = a[i][M - 1];
        if (zjfi_Var == 0) {
          i++;
          continue;
        }
        for (j = 0; j < M; j++) {
          if (a[i][j] != 0) {
            a[i][j] = (int)abs(zjfi_Var - a[i][j]);
          }
        }
        i++;
      }
    }

    {
      j = 0;
      for (; j < M;) {
        zjfi_Var = a[N - 1][j];
        if (zjfi_Var == 0) {
          j++;
          continue;
        }
        for (i = 0; i < N; i++) {
          if (a[i][j] != 0) {
            a[i][j] = (int)abs(zjfi_Var - a[i][j]);
          }
        }
        j++;
      }
    }

    {
      i = 1;
      while (i < N - 1) {
        for (j = 1; j < M - 1; j++) {
          if (a[i][j] != 0) {
            flag = 1;
            break;
          }
        }
        i++;
      }
    }
    if (flag == 0)
      fprintf(rffF_Var, "Case #%d: YES\n", qnhi_Var);
    else {
      fprintf(rffF_Var, "Case #%d: NO\n", qnhi_Var);
    }
  }
  fclose(dtgF_Var);
  fclose(rffF_Var);
  system("pause");
}
