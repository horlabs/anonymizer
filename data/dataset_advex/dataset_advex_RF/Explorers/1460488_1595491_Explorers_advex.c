#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int gbmi_Var, ryji_Var, nparticipant, nsurprising, bscore, pscore;
  int ngoogle[100] = {0};
  int sjscore;
  int remaining;
  scanf("%d", &gbmi_Var);
  for (ryji_Var = 0; ryji_Var < gbmi_Var; ryji_Var++) {
    scanf("%d", &nparticipant);
    scanf("%d", &nsurprising);
    scanf("%d", &bscore);

    for (int j = 0; j < nparticipant; j++) {
      scanf("%d", &pscore);
      sjscore = pscore / 3;
      remaining = pscore % 3;

      if (sjscore == 0 && remaining == 0 && bscore != 0)
        continue;
      if (sjscore >= bscore)
        ngoogle[ryji_Var]++;
      else if (remaining == 0 && nsurprising > 0 && sjscore + 1 >= bscore &&
               sjscore + 1 <= 10) {

        ngoogle[ryji_Var]++;
        nsurprising--;
      } else if (remaining == 1 && sjscore + 1 >= bscore && sjscore + 1 <= 10) {

        ngoogle[ryji_Var]++;
      } else if (remaining == 2) {

        if (sjscore + 1 >= bscore)
          ngoogle[ryji_Var]++;
        else if (nsurprising > 0 && sjscore + 2 >= bscore &&
                 sjscore + 2 <= 10) {
          nsurprising--;
          ngoogle[ryji_Var]++;
        }
      }
    }
  }
  {
    ryji_Var = 0;
    while (ryji_Var < gbmi_Var) {
      printf("Case #%d: %d\n", ryji_Var + 1, ngoogle[ryji_Var]);
      ryji_Var++;
    }
  }
  return 0;
}
