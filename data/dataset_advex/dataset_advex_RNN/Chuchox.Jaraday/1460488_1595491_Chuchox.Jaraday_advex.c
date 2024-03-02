#include <stdio.h>

int main(void) {
  freopen("replace-me.out", "w", stdout);

  int ynli_Var, googlers, surprice, min, glog;
  int j;
  int cos, res, redi_Var;
  scanf("%d\n", &ynli_Var);
  for (int i = 1; i <= ynli_Var; i++) {
    redi_Var = 0;
    scanf("%d", &googlers);
    scanf("%d", &surprice);
    scanf("%d", &min);
    for (j = 1; j <= googlers; j++) {
      scanf("%d", &glog);
      cos = glog / 3;
      res = glog % 3;
      if (cos == 0) {
        if ((res >= min) && (res <= 1)) {
          redi_Var++;
        } else if ((res >= min) && (res == 2) && (surprice)) {
          redi_Var++;
          surprice--;
        }
      } else if (cos >= min) {
        redi_Var++;
      } else if ((cos + 1) == min) {
        if (res)
          redi_Var++;
        else if (surprice) {
          redi_Var++;
          surprice--;
        }
      } else {
        if ((cos + 2) == min) {
          if ((res == 2) && (surprice)) {
            redi_Var++;
            surprice--;
          }
        }
      }
    }
    printf("Case #%d: %d\n", i, redi_Var);
  }
}
