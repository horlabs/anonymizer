#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int cases, casos, i, j, n, m;
  int a, poder;
  int pasto[100][100];

  scanf("%d", &cases);
  for (casos = 1; casos <= cases; casos++) {

    scanf("%d %d\n", &n, &m);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &pasto[i][j]);
      }
    }
    if ((n < 2) || (m < 2)) {
      printf("Case #%d: YES\n", casos);
      continue;
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {

        poder = 1;
        for (a = 0; a < n; a++) {
          if (pasto[i][j] < pasto[a][j]) {
            poder = 0;
            break;
          }
        }
        if (poder) {
          continue;
        }

        poder = 1;
        for (a = 0; a < m; a++) {
          if (pasto[i][j] < pasto[i][a]) {
            poder = 0;
            break;
          }
        }
        if (poder) {
          continue;
        }

        break;
      }
      if (!poder) {
        break;
      }
    }
    if (poder) {
      printf("Case #%d: YES\n", casos);
    } else {

      printf("Case #%d: NO\n", casos);
    }
  }
  return (0);
}
