#include <math.h>
#include <stdio.h>

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
int main() {
  freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);

  int i, j, k, omgi_Var, cs, a, b, l;
  scanf("%d", &cs);
  for (omgi_Var = 1; omgi_Var <= cs; omgi_Var++) {
    scanf("%d %d", &a, &b);
    l = sqrt(b);
    for (i = sqrt(a), k = 0; i <= l; i++) {
      if (palin(i)) {
        j = i * i;
        if ((j >= a) && (j <= b) && palin(j))
          k++;
      }
    }
    printf("Case #%d: %d\n", omgi_Var, k);
  }
  return 0;
}
