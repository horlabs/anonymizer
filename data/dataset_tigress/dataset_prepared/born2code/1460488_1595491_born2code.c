#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int a, count, t, n, s, p, i, j, k;

  scanf("%d", &t);
  for (i = 1; i <= t; i++) {
    scanf("%d%d%d", &n, &s, &p);
    count = 0;
    for (j = 0; j < n; j++) {
      scanf("%d", &a);
      if (a >= p) {
        if ((a + 2) / 3 >= p)
          count++;
        else if (s && (a + 1) / 3 == p - 1) {
          s--;
          count++;
        }
      }
    }
    printf("Case #%d: %d\n", i, count);
  }
  return 0;
}
