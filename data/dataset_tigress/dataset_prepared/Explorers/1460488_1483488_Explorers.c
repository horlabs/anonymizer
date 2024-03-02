#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int ntest, i, len, k, npairs[50] = {0};
  long la, lb, j, divider, multiplier, remainder, divisor, pairnum;
  scanf("%d", &ntest);

  for (i = 0; i < ntest; i++) {
    scanf("%ld %ld", &la, &lb);
    len = numlen(la);

    for (j = la; j < lb; j++) {

      for (k = len - 1; k >= 1; k--) {
        multiplier = pow(10, k);
        divider = pow(10, len - k);

        divisor = j / divider;
        remainder = j % divider;
        pairnum = remainder * multiplier + divisor;

        if (numlen(pairnum) != len)
          continue;

        if (pairnum > j && pairnum <= lb) {

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
