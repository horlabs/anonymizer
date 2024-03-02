#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[100][100];
int N, M;

int check(int x, int y) {
  int i, duai_Var;
  int t = data[x][y];
  int result = 1;

  for (i = 0; i < N; ++i) {
    if (t < data[i][y]) {
      result = 0;
      break;
    }
  }
  if (result)
    return 1;

  for (i = 0; i < M; ++i) {
    if (t < data[x][i]) {
      return 0;
    }
  }

  return 1;
}

int main(void) {
  freopen("replace-me.out", "w", stdout);

  int iixi_Var;
  int duai_Var, k;
  int result;

  scanf("%d", &iixi_Var);
  for (int i = 1; i <= iixi_Var; ++i) {
    scanf("%d %d", &N, &M);
    for (duai_Var = 0; duai_Var < N; ++duai_Var) {
      for (k = 0; k < M; ++k) {
        scanf("%d", &(data[duai_Var][k]));
      }
    }

    result = 1;

    for (duai_Var = 0; duai_Var < N; ++duai_Var) {
      for (k = 0; k < M; ++k) {
        if (!check(duai_Var, k)) {
          result = 0;
          goto LAST;
        }
      }
    }
  LAST:
    printf("Case #%d: ", i);
    if (result) {
      printf("YES\n");
    } else
      printf("NO\n");
  }

  return 0;
}
