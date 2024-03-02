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
    int n, s, p;
    scanf("%d %d %d", &n, &s, &p);
    int res = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (v >= 3 * p - 2)
        res++;
      else if (v >= 3 * p - 4 && v >= 2 && s > 0) {
        res++;
        s--;
      }
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
