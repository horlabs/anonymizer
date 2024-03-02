#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itos(int a, char s[]) {
  int i, j, k;
  char x, y[100];
  i = a;
  j = 0;
  while (a) {
    s[j++] = a % 10 + '0';
    a /= 10;
  }
  s[j] = '\0';
  k = strlen(s);
  for (i = 0, j = k - 1; i <= k - 1; j--, i++)
    y[j] = s[i];

  for (i = 0; i <= k - 1; i++)
    s[i] = y[i];
}
int palind(int a) {
  char x[100];
  itos(a, x);
  int n = strlen(x);
  int i;

  for (i = 0; i < n - 1; i++) {
    if (x[i] != x[n - i - 1])
      return 0;
  }

  return 1;
}

int next(int i) {
  int j = i + 1;
  while (!(palind(j)))
    j++;
  return j;
}

int main() {
  freopen("replace-me.out", "w", stdout);

  int T, T1, a, b, lb, ub, count, i;

  T = 1;
  for (scanf("%d", &T1); T <= T1; T++) {
    scanf("%d%d", &a, &b);
    lb = ceil(sqrt(a));
    ub = floor(sqrt(b));
    count = 0;
    i = lb;
    while (!(palind(i)))
      i++;
    for (; i <= ub; i = next(i)) {
      if (palind(i * i))
        count++;
    }
    printf("Case #%d: %d\n", T, count);
  }
  return 0;
}
