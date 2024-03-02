#include "superheader.h"

int checkCard(a, b, c, d, e, f, g, h) {
  int flag1 = 0;
  int flag2 = 0;
  int num;

  if (a == e || a == f || a == g || a == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = a;
    } else if (flag2 == 0)
      return -2;
  }
  if (b == e || b == f || b == g || b == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = b;
    } else if (flag2 == 0)
      return -2;
  }
  if (c == e || c == f || c == g || c == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = c;
    } else if (flag2 == 0)
      return -2;
  }
  if (d == e || d == f || d == g || d == h) {
    if (flag1 == 0) {
      flag1 = 1;
      num = d;
    } else if (flag2 == 0)
      return -2;
  }
  if (flag1 == 0 && flag2 == 0)
    return -3;
  return num;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int ncase;
  int i, j, k, nans, n1rval1, n1rval2, n1rval3, n1rval4, n2rval1, n2rval2,
      n2rval3, n2rval4;
  int tmp1, tmp2, tmp3, tmp4;
  int res;

  scanf("%d", &ncase);

  for (i = 0; i < ncase; i++) {
    for (j = 0; j < 2; j++) {
      scanf("%d", &nans);
      for (k = 0; k < 4; k++) {
        if (k == nans - 1) {
          if (j == 0)
            scanf("%d %d %d %d", &n1rval1, &n1rval2, &n1rval3, &n1rval4);
          else
            scanf("%d %d %d %d", &n2rval1, &n2rval2, &n2rval3, &n2rval4);
        } else
          scanf("%d %d %d %d", &tmp1, &tmp2, &tmp3, &tmp4);
      }
    }

    res = checkCard(n1rval1, n1rval2, n1rval3, n1rval4, n2rval1, n2rval2,
                    n2rval3, n2rval4);
    if (res > 0)
      printf("Case #%d: %d\n", i + 1, res);
    else if (res == -2)
      printf("Case #%d: %s\n", i + 1, "Bad magician!");
    else if (res == -3)
      printf("Case #%d: %s\n", i + 1, "Volunteer cheated!");
  }
}
