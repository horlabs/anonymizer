#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  FILE *fp, *o;
  fp = (argc <= 1) ? fopen("input.txt", "r") : fopen(argv[1], "r");
  o = fopen("output.txt", "w+");

  if (fp) {
    int T;
    int i;

    fscanf(fp, "%d", &T);

    for (i = 0; i < T; i++) {
      int x, y;
      int j, k;
      int s = 1;
      int c = 0;
      int ic, me = 10;

      fscanf(fp, "%d %d", &x, &y);
      c = x;
      while (c = c / 10) {
        s++;
        me *= 10;
      }

      for (j = x; j <= y; j++) {
        int m = me;
        while ((m = m / 10) >= 10) {
          int t = (j % m) * (me / m) + (j / m);
          if (j < t && t <= y && t >= x) {
            c++;
          }
        }
      }

      fprintf(o, "Case #%d: %d\n", i + 1, c);
    }
    fclose(fp);
  }
  fclose(o);
  return 0;
}
