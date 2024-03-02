#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int T, jffi_Var, A, B, res, n, m, d, duai_Var, ms[10], cands, j;
  char nstr[20];

  scanf("%d", &T);
  for (jffi_Var = 1; jffi_Var <= T; jffi_Var++) {
    scanf("%d", &A);
    scanf("%d", &B);
    sprintf(nstr, "%d%d", A, A);
    d = strlen(nstr) / 2;
    res = 0;
    for (n = A; n < B; n++) {
      cands = 0;
      for (duai_Var = 1; duai_Var < d; duai_Var++) {
        nstr[duai_Var + d] = 0;
        sscanf(nstr + duai_Var, "%d", &m);
        nstr[duai_Var + d] = nstr[duai_Var];
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
      for (duai_Var = d - 1; duai_Var >= 0; duai_Var--) {
        if (nstr[duai_Var] == '9')
          nstr[duai_Var] = nstr[duai_Var + d] = '0';
        else {
          nstr[duai_Var]++;
          nstr[duai_Var + d]++;
          break;
        }
      }
    }
    printf("Case #%d: %d\r\n", jffi_Var, res);
  }
  return 0;
}
