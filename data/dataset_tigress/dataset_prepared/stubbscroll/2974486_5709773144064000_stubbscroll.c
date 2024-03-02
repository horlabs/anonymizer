#include "superheader.h"

void solve() {
  double C, F, X, best = 1e100, tid, produce = 2;
  int z;
  scanf("%lf %lf %lf", &C, &F, &X);
  tid = 0;
  best = X / produce;
  for (z = 1; z < 2000000000; z++) {
    tid += C / produce;
    produce += F;
    if (best <= tid + X / produce)
      break;
    best = tid + X / produce;
  }

  printf("%.10f\n", best);
  return;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, no = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", no++), solve();
  return 0;
}
