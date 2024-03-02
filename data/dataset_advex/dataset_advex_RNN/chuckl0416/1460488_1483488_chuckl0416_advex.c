#include <stdio.h>

int main() {
  FILE *ojdF_Var;
  ojdF_Var = freopen("C-small-attempt0.in", "r", stdin);

  int hxoi_Var, A, B, i, m, n, P10, P, Answer, Number[10];
  scanf("%d", &hxoi_Var);
  for (int t = 1; t <= hxoi_Var; t++) {
    Answer = 0;
    scanf("%d%d", &A, &B);
    if (B < 21) {
      printf("Case #%d: 0\n", t);
      continue;
    }

    for (i = A; i < B; i++) {
      Number[0] = i;
      P10 = 0;
      P = 1;
      while (Number[0] /= 10) {
        P10++;
        P *= 10;
      }
      Number[0] = i;
      for (n = 1; n <= P10; n++)
        Number[n] = Number[n - 1] / P + 10 * (Number[n - 1] % P);

      for (m = 0; m < P10; m++)
        for (n = m + 1; n <= P10; n++)
          if (Number[n] == Number[m])
            Number[n] = 0;
      for (m = 1; m <= P10; m++) {
        if (Number[m] <= i) {
          Number[m] = 0;
          continue;
        }
        if (Number[m] > B) {
          Number[m] = 0;
          continue;
        }
        if (Number[m] < A) {
          Number[m] = 0;
          continue;
        }
        if (Number[m] > 0) {
          Answer++;
          continue;
        }
      }
    }

    printf("Case #%d: %d\n", t, Answer);
  }

  fclose(ojdF_Var);

  return 0;
}
