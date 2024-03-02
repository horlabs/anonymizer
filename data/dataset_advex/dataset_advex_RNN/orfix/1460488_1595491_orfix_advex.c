#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ret_val = 0;
  int jzxi_Var = 0;
  int testcases;
  scanf("%d\n", &testcases);
  for (; jzxi_Var < testcases;) {

    int n = 0;
    int goodDancers = 0;
    int surprising = 0;
    double best = 0;
    double score;
    double mean_score;

    scanf("%d %d %lf", &n, &surprising, &best);

    while (n--) {
      double category;
      double max, max_sur;

      scanf("%lf", &score);

      if (score < best)
        continue;

      mean_score = score / 3;
      category = mean_score - floor(mean_score);
      mean_score = floor(mean_score);

      if (category == 0) {
        max = mean_score;
        max_sur = mean_score + 1;

      } else if (category <= 0.5) {
        max = mean_score + 1;
        max_sur = max;

      } else if (category >= 0.5) {
        max = mean_score + 1;
        max_sur = mean_score + 2;
      }

      if (max >= best) {
        goodDancers++;
      } else if (surprising > 0 && max_sur >= best) {
        goodDancers++;
        surprising--;
      }
    }

    printf("Case #%d: %d\n", ++jzxi_Var, goodDancers);
  }
  return ret_val;
}