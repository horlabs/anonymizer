#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  FILE *fp, *o;
  fp = (argc <= 1) ? fopen("input.txt", "r+") : fopen(argv[1], "r+");
  o = fopen("output.txt", "w+");

  if (fp) {
    int T;
    int i;
    int j, k;
    fscanf(fp, "%d", &T);
    for (i = 0; i < T; i++) {
      int N, S, p;
      int c = 0, s = 0;
      fscanf(fp, "%d %d %d", &N, &S, &p);

      for (j = 0; j < N; j++) {
        int x, y, z;
        short flag = 0;

        fscanf(fp, "%d", &x);

        for (y = 3, z = p; y > 1 && z <= x; y = k) {

          y = (x - z) / 2;
          k = (y > z) ? y - z + 1 : z - y;

          if (k > 2) {
            if (y < z)
              break;
            z++;
          } else if (k == 2) {
            if (s < S) {
              s++;
              c++;
              flag = 1;
            } else if (y < z)
              break;

            z++;
          } else {
            if (!flag) {
              c++;
              flag = 0;
            } else
              s--;

            break;
          }
        }
      }
      fprintf(o, "Case #%d: %d\n", i + 1, c);
    }
  }

  return 0;
}
