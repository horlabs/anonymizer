#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, m, n, p, s;
  int i, j, k;
  int nc;
  int score;

  int result;
  int surprise;

  scanf("%d", &t);

  for (nc = 1; nc <= t; nc++) {
    result = 0;
    surprise = 0;
    scanf("%d%d%d", &n, &s, &p);
    for (i = 0; i < n; i++) {
      scanf("%d", &score);
      if ((score + 2) / 3 >= p) {
        result++;
      } else if ((score + 4) / 3 >= p) {
        if (score == 0 && p != 0) {
        } else {
          surprise++;
        }
      }
    }
    if (s >= surprise)
      result += surprise;
    else
      result += s;

    printf("Case #%d: %d\n", nc, result);
  }
}
