#include "superheader.h"

typedef long long ll;
int palin(ll n) {
  int a[20], i, j, k;
  for (i = 0; n > 0; i++, n /= 10)
    a[i] = n % 10;
  for (i--, j = 0; i > j; i--, j++) {
    if (a[i] != a[j])
      return 0;
  }
  return 1;
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
  freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);

  int i, j, k, t, cs, a, b, l;
  scanf("%d", &cs);
  for (t = 1; t <= cs; t++) {
    scanf("%d %d", &a, &b);
    l = sqrt(b);
    for (i = sqrt(a), k = 0; i <= l; i++) {
      if (palin(i)) {
        j = i * i;
        if ((j >= a) && (j <= b) && palin(j))
          k++;
      }
    }
    printf("Case #%d: %d\n", t, k);
  }
  return 0;
}
