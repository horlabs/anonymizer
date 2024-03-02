#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int res = 0;
    int digmul = 1;
    int digs = 1;
    for (int x = a; x >= 10; x++) {
      digmul *= 10;
      digs++;
      x /= 10;
    }
    for (int n = a; n <= b; n++) {
      int m = n;
      int previous[digs];
      for (int d = 0; d < digs; d++) {
        previous[d] = m;
        m = (m % 10) * digmul + (m / 10);
        if (m <= n || m > b || m / digmul == 0)
          continue;
        for (int k = 0; k < d; k++)
          if (previous[k] == m)
            goto bad;
        res++;
      bad:;
      }
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
