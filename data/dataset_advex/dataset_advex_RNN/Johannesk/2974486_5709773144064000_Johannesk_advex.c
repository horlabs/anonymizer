#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef double td_d;
void solve(int c, double C, double F, double X) {
  td_d t = 0, rate = 2;

  while ((X / rate) > (X / (rate + F) + (C / rate))) {
    t = t + C / rate;
    rate = rate + F;
  }

  t = t + X / rate;
  printf("Case #%d: %.7lf\n", c, t);
}

int main(int argc, char **argv) {
  int ret_val = 0;
  int t, i;
  td_d C, F, X;
  assert(scanf("%d ", &t) == 1);
  {
    i = 1;
    while (i <= t) {
      assert(scanf("%lf %lf %lf ", &C, &F, &X) == 3);
      solve(i, C, F, X);
      i++;
    }
  }
  return ret_val;
}
