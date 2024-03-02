#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int ntest, i, j, nparticipant, nsurprising, bscore, pscore;
  int ngoogle[100] = {0};
  int sjscore;
  int remaining;
  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    scanf("%d", &nparticipant);
    scanf("%d", &nsurprising);
    scanf("%d", &bscore);

    for (j = 0; j < nparticipant; j++) {
      scanf("%d", &pscore);
      sjscore = pscore / 3;
      remaining = pscore % 3;

      if (sjscore == 0 && remaining == 0 && bscore != 0)
        continue;
      if (sjscore >= bscore)
        ngoogle[i]++;
      else if (remaining == 0 && nsurprising > 0 && sjscore + 1 >= bscore &&
               sjscore + 1 <= 10) {

        ngoogle[i]++;
        nsurprising--;
      } else if (remaining == 1 && sjscore + 1 >= bscore && sjscore + 1 <= 10) {

        ngoogle[i]++;
      } else if (remaining == 2) {

        if (sjscore + 1 >= bscore)
          ngoogle[i]++;
        else if (nsurprising > 0 && sjscore + 2 >= bscore &&
                 sjscore + 2 <= 10) {
          nsurprising--;
          ngoogle[i]++;
        }
      }
    }
  }

  for (i = 0; i < ntest; i++) {
    printf("Case #%d: %d\n", i + 1, ngoogle[i]);
  }
}
