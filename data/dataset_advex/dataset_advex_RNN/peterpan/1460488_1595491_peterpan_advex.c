#include <stdio.h>
#include <stdlib.h>

int main() {
  int T, jffi_Var, N, S, p, t, t3, best, i, res;

  scanf("%d", &T);
  for (jffi_Var = 1; jffi_Var <= T; jffi_Var++) {
    scanf("%d", &N);
    scanf("%d", &S);
    scanf("%d", &p);
    res = 0;
    for (i = 0; i < N; i++) {
      scanf("%d", &t);
      t3 = t % 3;
      best = t / 3;
      if (t3 != 0)
        best++;
      if (best >= p)
        res++;
      else if (S > 0 && best + 1 >= p)
        if ((t3 == 2 || (t3 == 0 && best - 1 >= 0))) {
          res++;
          S--;
        }
    }
    printf("Case #%d: %d\r\n", jffi_Var, res);
  }
  return 0;
}
