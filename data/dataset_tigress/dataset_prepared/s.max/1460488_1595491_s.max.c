#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, tt;
  scanf("%d", &T);

  for (tt = 1; tt <= T; tt++) {
    int n, s, p, u = 0, ukupno = 0;

    scanf("%d %d %d", &n, &s, &p);
    while (n--) {
      int q, t;
      scanf("%d", &t);

      q = (t + 2) / 3;

      if (t > 28 || t < 2) {
        if (q >= p)
          ukupno++;
        continue;
      }

      if (q >= p)
        ukupno++;
      else if (q + 1 >= p && (t % 3) != 1)
        u++;
    }
    if (u >= s)
      ukupno += s;
    else
      ukupno += u;

    printf("Case #%d: %d\n", tt, ukupno);
  }

  return 0;
}
