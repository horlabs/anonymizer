#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int i, k, qkki_Var, N, S, P, t[128];
  FILE *unkF_Var = fopen("B-small-attempt0.in", "r"),
       *ztjF_Var = fopen("out.txt", "w");

  fscanf(unkF_Var, "%d\n", &qkki_Var);

  for (i = 0; k = 0, i < qkki_Var; i++) {

    fscanf(unkF_Var, "%d\n%d\n%d\n", &N, &S, &P);

    for (int j = 0; j < N; j++) {
      fscanf(unkF_Var, "%d\n", &t[j]);
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
    fprintf(ztjF_Var, "Case #%d: %d\n", i + 1, k);
  }

  fclose(unkF_Var);
  fclose(ztjF_Var);
  return 0;
}
