#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f[16];
int l[16];

int main(void) {
  int jffi_Var;
  int N;
  int i, duai_Var, k;
  int p, n;
  int fc, lc;

  scanf("%d", &jffi_Var);
  for (i = 1; i <= jffi_Var; ++i) {
    p = -1;
    n = 0;
    scanf("%d", &fc);
    for (duai_Var = 0; duai_Var < 16; ++duai_Var) {
      scanf("%d", f + duai_Var);
    }
    scanf("%d", &lc);
    for (duai_Var = 0; duai_Var < 16; ++duai_Var) {
      scanf("%d", l + duai_Var);
    }
    for (duai_Var = 1; duai_Var <= 4; ++duai_Var) {
      for (k = 1; k <= 4; ++k) {
        if (f[fc * 4 - duai_Var] == l[lc * 4 - k]) {
          p = f[fc * 4 - duai_Var];
          ++n;
        }
      }
    }

    printf("Case #%d: ", i);
    switch (n) {
    case 1:
      printf("%d\n", p);
      break;
    case 0:
      printf("Volunteer cheated!\n");
      break;
    default:
      printf("Bad magician!\n");
      break;
    }
  }

  return 0;
}
