#include <stdio.h>

int main() {
  int jffi_Var, s, p, i, j, n, score, count = 0;
  FILE *fpin, *fpout;
  fpin = fopen("B-small-attempt0.in", "r");
  if (fpin == NULL)
    printf("ERROR\n");
  else {
    fscanf(fpin, "%d", &jffi_Var);
    for (i = 0; i < jffi_Var; i++) {
      count = 0;
      fscanf(fpin, "%d", &n);
      fscanf(fpin, "%d", &s);
      fscanf(fpin, "%d", &p);
      for (j = 0; j < n; j++) {
        fscanf(fpin, "%d", &score);
        if (score / 3 >= p)
          count++;
        else if (score % 3 > 0 && score / 3 + 1 >= p)
          count++;
        else if ((s > 0 && score % 3 == 0 && score / 3 + 1 == p && score > 0)) {
          count++;
          s--;
        } else if ((s > 0 && score % 3 == 2 && score / 3 + 2 >= p)) {
          count++;
          s--;
        }
      }
      fpout = fopen("output2.out", "a");
      fprintf(fpout, "Case #%d: %d\n", i + 1, count);
    }
  }
}
