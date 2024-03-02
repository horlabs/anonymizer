#include "superheader.h"

int t[105];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int n, s, p, i, ans, test, testno = 1;
  scanf("%d", &test);
  while (test--) {
    scanf("%d %d %d", &n, &s, &p);
    for (i = 0; i < n; i++)
      scanf("%d", &t[i]);
    ans = 0;
    for (i = 0; i < n; i++) {
      if ((t[i] + 2) / 3 >= p)
        ans++;
      else if ((t[i] + 2) / 3 == (p - 1) && s > 0 && t[i] > 1 &&
               t[i] % 3 != 1) {
        ans++;
        s--;
      }
    }
    printf("Case #%d: %d\n", testno, ans);
    testno++;
  }
  return 0;
}
