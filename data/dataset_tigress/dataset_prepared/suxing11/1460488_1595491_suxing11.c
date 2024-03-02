#include "superheader.h"

int a[110];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, i, nCase = 1;
  int num1, num2;
  int n, s, p;
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("bout.txt", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &s, &p);
    num1 = 0, num2 = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] >= 3 * p - 2)
        num1++;
      else if (p > 1 && a[i] >= 3 * p - 4)
        num2++;
    }
    if (num2 > s)
      num2 = s;
    printf("Case #%d: %d\n", nCase++, num1 + num2);
  }
  return 0;
}
