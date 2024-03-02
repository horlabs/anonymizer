#include <stdio.h>
#include <stdlib.h>

typedef FILE td_F;
typedef FILE td_FI;

int main() {
  int ret_val = 0;
  FILE *fp_in, *jzxF_Var;
  int a[10][10], T, N, M, i, j, n, flag = 0;
  fp_in = fopen("B-small-attempt1.in", "r");
  jzxF_Var = fopen("output.txt", "w");
  fscanf(fp_in, "%d", &T);
  for (int zvmi_Var = 1; zvmi_Var <= T; zvmi_Var++) {
    flag = 0;
    fscanf(fp_in, "%d %d", &N, &M);
    for (i = 0; i < N; i++) {
      for (j = 0; j < M; j++)
        fscanf(fp_in, "%d", &a[i][j]);
    }
    for (i = 0; i < N; i++) {
      n = a[i][0];

      for (j = 0; j < M; j++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (j = 0; j < M; j++) {
      n = a[0][j];
      for (i = 0; i < N; i++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (i = 0; i < N; i++) {
      n = a[i][M - 1];
      if (n == 0)
        continue;
      for (j = 0; j < M; j++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (j = 0; j < M; j++) {
      n = a[N - 1][j];
      if (n == 0) {
        continue;
      }
      for (i = 0; i < N; i++) {
        if (a[i][j] != 0) {
          a[i][j] = (int)abs(n - a[i][j]);
        }
      }
    }

    for (i = 1; i < N - 1; i++) {
      for (j = 1; j < M - 1; j++) {
        if (a[i][j] != 0) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0) {
      fprintf(jzxF_Var, "Case #%d: YES\n", zvmi_Var);
    } else
      fprintf(jzxF_Var, "Case #%d: NO\n", zvmi_Var);
  }
  fclose(fp_in);
  fclose(jzxF_Var);
  system("pause");
  return ret_val;
}
