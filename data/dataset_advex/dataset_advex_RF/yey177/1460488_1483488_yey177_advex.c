#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int s[8], sn;
  int t, k, a, b, d, e, tmp, duai_Var, j, l, f, r;
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    scanf("%d%d", &a, &b);
    tmp = a;
    d = r = 0;
    while (tmp > 0) {
      tmp /= 10;
      d++;
    }
    e = 1;
    for (duai_Var = 1; duai_Var < d; duai_Var++)
      e *= 10;
    for (duai_Var = a; duai_Var <= b; duai_Var++) {
      tmp = duai_Var;
      s[0] = duai_Var;
      sn = 1;
      for (j = 1; j < d; j++) {
        tmp = (tmp % 10) * e + tmp / 10;
        if (tmp > b)
          continue;
        if (tmp <= duai_Var)
          continue;
        f = 1;
        for (l = 0; l < sn; l++) {
          if (s[l] == tmp) {
            f = 0;
            break;
          }
        }
        if (f) {
          s[sn++] = tmp;
          r++;
        }
      }
    }
    printf("Case #%d: %d\n", k, r);
  }
  return 0;
}
