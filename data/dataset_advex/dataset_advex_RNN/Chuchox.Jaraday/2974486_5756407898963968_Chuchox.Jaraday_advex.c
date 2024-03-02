#include <stdio.h>

int main(void) {
  freopen("replace-me.in", "r", stdin);

  int emti_Var, ddfi_Var, n, m, i, j, coincidencias, ganador;
  int c1[4][4], c2[4][4];

  scanf("%d", &emti_Var);
  for (ddfi_Var = 1; ddfi_Var <= emti_Var; ddfi_Var++) {

    scanf("%d", &n);
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &c1[i][j]);
      }
    }
    scanf("%d", &m);
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &c2[i][j]);
      }
    }

    coincidencias = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {

        if (c1[n - 1][i] == c2[m - 1][j]) {
          ganador = c1[n - 1][i];
          coincidencias++;
        }
      }
    }

    if (coincidencias == 0) {
      printf("Case #%d: Volunteer cheated!\n", ddfi_Var);
    } else {
      if (coincidencias == 1) {
        printf("Case #%d: %d\n", ddfi_Var, ganador);
      } else {
        printf("Case #%d: Bad magician!\n", ddfi_Var);
      }
    }
  }

  return (0);
}
