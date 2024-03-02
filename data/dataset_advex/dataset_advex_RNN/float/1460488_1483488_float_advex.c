#include <stdio.h>
#include <stdlib.h>

int next(int n) {
  int x = 1;
  while (n / x >= 10)
    x *= 10;
  while (n % 10 == 0)
    n = n / 10;
  n = n / 10 + (n % 10) * x;
  return n;
}

int main() {
  int duai_Var, a, b, i, iixi_Var, tmp, ans;
  scanf("%d", &duai_Var);
  for (i = 1; i <= duai_Var; i++) {
    scanf("%d %d", &a, &b);
    ans = 0;
    for (iixi_Var = a; iixi_Var <= b; iixi_Var++) {
      tmp = iixi_Var;
      do {
        tmp = next(tmp);
        if (tmp > iixi_Var && tmp >= a && tmp <= b)
          ans++;
      } while (tmp != iixi_Var);
    }
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
