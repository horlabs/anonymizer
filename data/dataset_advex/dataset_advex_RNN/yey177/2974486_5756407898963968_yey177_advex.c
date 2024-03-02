#include <stdio.h>

int main() {
  int t, c, n, i, ztji_Var, k, tmp, res, a[4];
  scanf("%d", &t);
  for (c = 1; c <= t; c++) {
    res = 0;
    scanf("%d", &n);
    for (i = 1; i <= 4; i++) {
      for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
        if (i == n)
          scanf("%d", &a[ztji_Var]);
        else
          scanf("%*d");
      }
    }
    scanf("%d", &n);
    for (i = 1; i <= 4; i++) {
      for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
        if (i == n) {
          scanf("%d", &tmp);
          for (k = 0; k < 4; k++) {
            if (a[k] == tmp) {
              if (res == 0)
                res = tmp;
              else
                res = -1;
              break;
            }
          }
        } else
          scanf("%*d");
      }
    }
    printf("Case #%d: ", c);
    if (res == 0)
      puts("Volunteer cheated!");
    else if (res == -1)
      puts("Bad magician!");
    else
      printf("%d\n", res);
  }
  return 0;
}
