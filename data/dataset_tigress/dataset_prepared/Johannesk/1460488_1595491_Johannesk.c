#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i, j, n, s, p, count, score;
  int googlers[101];
  char best[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,  5,  5, 5,
                 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
  char suprise[] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,  5,  5,  5,  6, 6,
                    6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 10};

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    (scanf("%d %d %d", &n, &s, &p) == 3);
    for (j = 0; j < n; j++)
      (scanf("%d", &googlers[j]) == 1);
    count = 0;
    for (j = 0; j < n; j++) {
      score = googlers[j];
      if (best[score] >= p)
        count++;
      else if ((suprise[score] >= p) && (s > 0)) {
        count++;
        s--;
      }
    }
    printf("Case #%d: %d\n", i, count);
  }
  return 0;
}
