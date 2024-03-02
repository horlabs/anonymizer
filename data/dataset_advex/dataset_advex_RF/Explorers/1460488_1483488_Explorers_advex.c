#include <math.h>
#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int ntest, i, len, k, npairs[50] = {0};
  long la, lb, dual_Var, divider, multiplier, remainder, divisor, pairnum;
  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    scanf("%ld %ld", &la, &lb);
    len = numlen(la);

    for (dual_Var = la; dual_Var < lb; dual_Var++) {

      for (k = len - 1; k >= 1; k--) {
        multiplier = pow(10, k);
        divider = pow(10, len - k);

        divisor = dual_Var / divider;
        remainder = dual_Var % divider;
        pairnum = remainder * multiplier + divisor;

        if (numlen(pairnum) != len)
          continue;

        if (pairnum > dual_Var && pairnum <= lb) {

          npairs[i]++;
        }
      }
    }
  }
  for (i = 0; i < ntest; i++) {
    printf("Case #%d: %d\n", i + 1, npairs[i]);
  }
}

int numlen(long n) {
  if (n < 10)
    return 1;
  else
    return 1 + numlen(n / 10);
}
