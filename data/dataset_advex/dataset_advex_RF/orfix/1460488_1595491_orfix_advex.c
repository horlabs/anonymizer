#include <math.h>
#include <stdio.h>

typedef double td_d;
int main(void) {

  int ret_val = 0;
  int iydi_Var = 0;
  int duei_Var;
  scanf("%d\n", &duei_Var);
  for (; iydi_Var < duei_Var;) {

    int ojdi_Var = 0;
    int goodDancers = 0;
    int surprising = 0;
    td_d best = 0;
    td_d score;
    td_d mean_score;

    scanf("%d %d %lf", &ojdi_Var, &surprising, &best);

    for (; ojdi_Var--;) {
      td_d category;
      td_d max, max_sur;

      scanf("%lf", &score);

      if (score < best) {
        continue;
      }

      mean_score = score / 3;
      category = mean_score - floor(mean_score);
      mean_score = floor(mean_score);

      if (category == 0) {
        max = mean_score;
        max_sur = mean_score + 1;

      } else {
        if (category <= 0.5) {
          max = mean_score + 1;
          max_sur = max;

        } else {
          if (category >= 0.5) {
            max = mean_score + 1;
            max_sur = mean_score + 2;
          }
        }
      }

      if (max >= best)
        goodDancers++;
      else {
        if (surprising > 0) {
          if (max_sur >= best) {
            goodDancers++;
            surprising--;
          }
        }
      }
    }

    printf("Case #%d: %d\n", ++iydi_Var, goodDancers);
  }
  return ret_val;
}
