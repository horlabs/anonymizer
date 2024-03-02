#include <math.h>
#include <stdio.h>

unsigned long int rotate(unsigned long int n, int d) {
  unsigned long int x, p, q;
  x = pow(10, d - 1);
  p = n % x;
  q = n / x;
  p = p * 10 + q;
  return p;
}

int digits(unsigned long int n) {
  int d = 0;
  while (n) {
    d++;
    n /= 10;
  }
  return d;
}

int main() {
  unsigned long int t, a, b, m, n;
  unsigned long int i, j, k, d, p;
  scanf("%ld", &t);
  for (i = 1; i <= t; i++) {
    scanf("%ld%ld", &a, &b);
    d = digits(a);
    k = 0;
    for (m = a + 1; m <= b; m++) {
      for (p = a; p < m; p++) {
        n = rotate(p, d);
        j = 0;
        while (n != m && j < d - 1) {
          n = rotate(n, d);
          j++;
        }
        if (j < d - 1) {
          k++;
        }
      }
    }
    printf("Case #%ld: %ld\n", i, k);
  }

  return 0;
}
