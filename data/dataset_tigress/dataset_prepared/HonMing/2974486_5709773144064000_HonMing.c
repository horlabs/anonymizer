#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i, j;
  int ii, jj, kk;
  int res;
  int m;
  char map[10][10];
  int end, xw, ow;

  double c, f, x, r;
  double temp;

  unsigned long long result;

  scanf("%d", &m);

  for (ii = 1; ii <= m; ii++) {
    scanf("%lf%lf%lf", &c, &f, &x);

    temp = 0;
    r = 2.0;

    if (x <= c) {
      printf("Case #%d: %.07lf\n", ii, x / r);
      continue;
    }

    while (temp + x / r > temp + c / r + x / (r + f)) {
      temp += c / r;
      r += f;
    }

    printf("Case #%d: %.07lf\n", ii, temp + x / r);
  }
}