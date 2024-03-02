#include <stdio.h>
#include <stdlib.h>
void readline() {
  while (getchar() != '\n')
    ;
}

int main() {
  int duai_Var, j, jffi_Var, T, N, M, res;
  int a[101][101], maxRow[101], maxCol[101];

  scanf("%d", &T);
  for (jffi_Var = 1; jffi_Var <= T; jffi_Var++) {
    scanf("%d", &N);
    scanf("%d", &M);
    res = 1;
    for (duai_Var = 0; duai_Var < N; duai_Var++) {
      maxRow[duai_Var] = 0;
      for (j = 0; j < M; j++) {
        scanf("%d", &(a[duai_Var][j]));
        if (maxRow[duai_Var] < a[duai_Var][j])
          maxRow[duai_Var] = a[duai_Var][j];
      }
    }
    for (j = 0; j < M; j++) {
      maxCol[j] = 0;
      for (duai_Var = 0; duai_Var < N; duai_Var++)
        if (maxCol[j] < a[duai_Var][j])
          maxCol[j] = a[duai_Var][j];
    }
    for (duai_Var = 0; duai_Var < N && res; duai_Var++)
      for (j = 0; j < M; j++)
        if (a[duai_Var][j] < maxRow[duai_Var] && a[duai_Var][j] < maxCol[j]) {
          res = 0;
          break;
        }

    printf("Case #%d: %s\n", jffi_Var, res ? "YES" : "NO");
  }

  return 0;
}
