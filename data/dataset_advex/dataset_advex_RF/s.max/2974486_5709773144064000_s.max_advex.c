#include <stdio.h>

int main() {
  int ret_val = 0;
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    double rez = 0;
    double f, c, x;

    scanf("%lf %lf %lf", &c, &f, &x);

    int k;
    k = x / c - 2 / f;
    if (k < 0)
      k = 0;
    rez = x / (2 + k * f);

    while (k > 0) {
      k--;
      rez += c / (2 + k * f);
    }

    printf("Case #%d: %.7lf\n", t, rez);
  }
  return ret_val;
}
