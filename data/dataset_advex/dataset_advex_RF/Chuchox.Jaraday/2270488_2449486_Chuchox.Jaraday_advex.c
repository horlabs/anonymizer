#include <stdio.h>

int main(void) {

  freopen("replace-me.in", "r", stdin);

  int ryji_Var, ryfi_Var, nmji_Var, lcji_Var, m;
  int a, poder;
  int pasto[100][100];

  scanf("%d", &ryji_Var);

  for (int gnri_Var = 1; gnri_Var <= ryji_Var; gnri_Var++) {

    scanf("%d %d\n", &lcji_Var, &m);
    for (ryfi_Var = 0; ryfi_Var < lcji_Var; ryfi_Var++) {
      for (nmji_Var = 0; nmji_Var < m; nmji_Var++) {
        scanf("%d", &pasto[ryfi_Var][nmji_Var]);
      }
    }
    if ((m < 2)) {
      printf("Case #%d: YES\n", gnri_Var);
      continue;
    } else {
      if ((lcji_Var < 2)) {
        printf("Case #%d: YES\n", gnri_Var);
        continue;
      }
    }

    {
      ryfi_Var = 0;
      while (ryfi_Var < lcji_Var) {
        {
          nmji_Var = 0;
          for (; nmji_Var < m;) {

            poder = 1;
            for (a = 0; a < lcji_Var; a++) {
              if (pasto[ryfi_Var][nmji_Var] < pasto[a][nmji_Var]) {
                poder = 0;
                break;
              }
            }
            if (poder) {
              nmji_Var++;
              continue;
            }

            poder = 1;
            {
              a = 0;
              for (; a < m;) {
                if (pasto[ryfi_Var][nmji_Var] < pasto[ryfi_Var][a]) {
                  poder = 0;
                  break;
                }
                a++;
              }
            }
            if (poder) {
              nmji_Var++;
              continue;
            }

            break;
            nmji_Var++;
          }
        }
        if (!poder) {
          break;
        }
        ryfi_Var++;
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
