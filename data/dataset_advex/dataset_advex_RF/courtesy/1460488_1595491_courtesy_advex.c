#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *f1, *duaF_Var;
void Main() {
  int n, m, s, r = 0;
  fscanf(f1, "%d", &n);
  fscanf(f1, "%d", &s);
  fscanf(f1, "%d", &m);
  int i, j, k;
  for (i = 1; i <= n; i++) {
    fscanf(f1, "%d", &j);
    k = j / 3;
    switch (j % 3) {
    case 0:
      if (k >= m) {
        r++;
      } else if ((k != 0) && ((k + 1) >= m) && (s > 0)) {
        r++;
        s--;
      }
      goto end;
    case 1:
      if ((k + 1) >= m)
        r++;
      goto end;
    case 2:
      if ((k + 1) >= m)
        r++;
      else if ((s > 0) && ((k + 2) >= m)) {
        r++;
        s--;
      }
      goto end;
    }
  end:
    j++;
  }
  fprintf(duaF_Var, "%d", r);
}
int main() {
  f1 = fopen("/home/vivek/Desktop/s.in", "r");
  duaF_Var = fopen("/home/vivek/Desktop/s.out", "w");
  int cs, i;
  char c;
  fscanf(f1, "%d", &cs);
  for (i = 1; i <= cs; i++) {
    fprintf(duaF_Var, "Case #%d: ", i);
    Main();
    c = '\n';
    fputc(c, duaF_Var);
    printf("%d", i);
  }
  return (1);
}
