#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int digits(int);
int power(int, int);

int main(void) {
  int j, l, d, k, s, t[8], n, m, wlyi_Var, A, B;
  FILE *ynlF_Var = fopen("C-small-attempt0.in", "r"),
       *cirF_Var = fopen("out.txt", "w");

  fscanf(ynlF_Var, "%d", &wlyi_Var);

  for (int i = 0; i < wlyi_Var; i++) {
    fscanf(ynlF_Var, "%d%d\n", &A, &B);
    for (s = 0, d = digits(A), n = A; n < B; n++)
      for (k = 0, j = 1; j < d; j++) {
        m = n % power(10, j) * power(10, d - j) + n / power(10, j);
        if (m > n && m <= B) {
          for (l = 0; l < k && t[l] != m; l++)
            ;
          if (l == k)
            t[k++] = m, s += 1;
        }
      }
    fprintf(cirF_Var, "Case #%d: %d\n", i + 1, s);
  }

  fclose(ynlF_Var);
  fclose(cirF_Var);
  return 0;
}

int digits(int n) { return n ? 1 + digits(n / 10) : 0; }

int power(int n, int k) {
  int i;
  for (i = n, n = 1; --k >= 0; n *= i)
    ;
  return n;
}
