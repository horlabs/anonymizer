#include <stdio.h>

int main(void) {
  int ynli_Var, gnri_Var, hxoi_Var, j, n, m;
  int a, poder;
  int pasto[100][100];

  scanf("%d", &ynli_Var);
  for (gnri_Var = 1; gnri_Var <= ynli_Var; gnri_Var++) {

    scanf("%d %d\n", &n, &m);
    for (hxoi_Var = 0; hxoi_Var < n; hxoi_Var++) {
      {
        j = 0;
        while (j < m) {
          scanf("%d", &pasto[hxoi_Var][j]);
          j++;
        }
      }
    }
    if ((n < 2) || (m < 2)) {
      printf("Case #%d: YES\n", gnri_Var);
      continue;
    }

    for (hxoi_Var = 0; hxoi_Var < n; hxoi_Var++) {
      for (j = 0; j < m; j++) {

        poder = 1;
        for (a = 0; a < n; a++) {
          if (pasto[hxoi_Var][j] < pasto[a][j]) {
            poder = 0;
            break;
          }
        }
        if (poder) {
          continue;
        }

        poder = 1;
        for (a = 0; a < m; a++) {
          if (pasto[hxoi_Var][j] < pasto[hxoi_Var][a]) {
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
      printf("Case #%d: YES\n", gnri_Var);
    } else {

      printf("Case #%d: NO\n", gnri_Var);
    }
  }
  return (0);
}
