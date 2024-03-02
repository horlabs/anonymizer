#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, tcase, A, B, res, n, m, d, i, ms[10], cands, j;
  char nstr[20];

  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    scanf("%d", &A);
    scanf("%d", &B);
    sprintf(nstr, "%d%d", A, A);
    d = strlen(nstr) / 2;
    res = 0;
    for (n = A; n < B; n++) {
      cands = 0;
      for (i = 1; i < d; i++) {
        nstr[i + d] = 0;
        sscanf(nstr + i, "%d", &m);
        nstr[i + d] = nstr[i];
        if (n < m && m <= B) {
          for (j = 0; j < cands; j++)
            if (ms[cands] == m)
              break;
          if (j == cands) {
            ms[cands++] = m;
            res++;
          }
        }
      }
      for (i = d - 1; i >= 0; i--) {
        if (nstr[i] == '9')
          nstr[i] = nstr[i + d] = '0';
        else {
          nstr[i]++;
          nstr[i + d]++;
          break;
        }
      }
    }
    printf("Case #%d: %d\r\n", tcase, res);
  }
  return 0;
}
