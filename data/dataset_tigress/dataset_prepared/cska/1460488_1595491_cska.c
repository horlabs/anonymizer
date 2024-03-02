#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i, j, k, T, N, S, P, t[128];
  FILE *fin = fopen("B-small-attempt0.in", "r"), *fout = fopen("out.txt", "w");

  fscanf(fin, "%d\n", &T);

  for (i = 0; k = 0, i < T; i++) {

    fscanf(fin, "%d\n%d\n%d\n", &N, &S, &P);

    for (j = 0; j < N; j++) {
      fscanf(fin, "%d\n", &t[j]);
      switch (t[j] % 3) {
      case 0:
        if (t[j] / 3 >= P)
          k++;
        else if (S > 0 && t[j] / 3 > 0 && t[j] / 3 < 10 && t[j] / 3 + 1 >= P)
          S--, k++;
        break;
      case 1:
        if (t[j] / 3 + 1 >= P)
          k++;
        break;
      case 2:
        if (t[j] / 3 + 1 >= P)
          k++;
        else if (S > 0 && t[j] / 3 < 9 && t[j] / 3 + 2 >= P)
          S--, k++;
        break;
      }
    }
    fprintf(fout, "Case #%d: %d\n", i + 1, k);
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
