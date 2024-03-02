#include <stdio.h>

int main() {
  int iixi_Var, duai_Var, ceti_Var, nparticipant, nsurprising, bscore, pscore;
  int ngoogle[100] = {0};
  int sjscore;
  int remaining;
  scanf("%d", &iixi_Var);
  for (duai_Var = 0; duai_Var < iixi_Var; duai_Var++) {
    scanf("%d", &nparticipant);
    scanf("%d", &nsurprising);
    scanf("%d", &bscore);

    for (ceti_Var = 0; ceti_Var < nparticipant; ceti_Var++) {
      scanf("%d", &pscore);
      sjscore = pscore / 3;
      remaining = pscore % 3;

      if (sjscore == 0 && remaining == 0 && bscore != 0)
        continue;
      if (sjscore >= bscore)
        ngoogle[duai_Var]++;
      else if (remaining == 0 && nsurprising > 0 && sjscore + 1 >= bscore &&
               sjscore + 1 <= 10) {

        ngoogle[duai_Var]++;
        nsurprising--;
      } else if (remaining == 1 && sjscore + 1 >= bscore && sjscore + 1 <= 10) {

        ngoogle[duai_Var]++;
      } else if (remaining == 2) {

        if (sjscore + 1 >= bscore) {
          ngoogle[duai_Var]++;
        } else if (nsurprising > 0 && sjscore + 2 >= bscore &&
                   sjscore + 2 <= 10) {
          nsurprising--;
          ngoogle[duai_Var]++;
        }
      }
    }
  }
  for (duai_Var = 0; duai_Var < iixi_Var; duai_Var++) {
    printf("Case #%d: %d\n", duai_Var + 1, ngoogle[duai_Var]);
  }
  return 0;
}
