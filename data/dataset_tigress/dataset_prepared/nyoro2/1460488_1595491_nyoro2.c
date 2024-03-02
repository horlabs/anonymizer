#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int i, j;
  int n, s, p;
  int t;
  int best_not_surprising;
  int best_surprising;
  int result;

  scanf("%d\n", &T);
  for (i = 0; i < T; i++) {
    scanf("%d %d %d", &n, &s, &p);

    result = 0;
    for (j = 0; j < n; j++) {
      scanf("%d", &t);

      best_not_surprising = (t + 2) / 3;

      if (best_not_surprising >= p) {
        result++;
      } else if (s > 0) {
        if (((t % 3) != 1) && (best_not_surprising != 0)) {
          best_surprising = best_not_surprising + 1;

          if (best_surprising >= p) {
            result++;
            s--;
          }
        }
      }
    }
    printf("Case #%d: %d\n", i + 1, result);
  }

  return 0;
}
