#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int cases, casos, n, m, i, j, coincidencias, ganador;
  int c1[4][4], c2[4][4];

  scanf("%d", &cases);
  for (casos = 1; casos <= cases; casos++) {

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
      printf("Case #%d: Volunteer cheated!\n", casos);
    } else if (coincidencias == 1) {
      printf("Case #%d: %d\n", casos, ganador);
    } else {
      printf("Case #%d: Bad magician!\n", casos);
    }
  }

  return (0);
}
