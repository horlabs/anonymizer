#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#include <fstream>
FILE *fin = freopen("a.in", "r", stdin);
FILE *fout = freopen("a.out", "w", stdout);

int main() {
  int T, t, a[30], m, i, j;
  long long n;
  cin >> T;
  for (t = 1; t <= T; t++) {
    cin >> n;
    m = 0;
    while (n) {
      a[++m] = n % 10;
      n /= 10;
    }
    for (i = 2; i <= m; i++)
      if (a[i - 1] < a[i]) {
        a[i]--;
        for (j = 1; j < i; j++)
          a[j] = 9;
      }
    printf("Case #%d: ", t);
    if (!a[m])
      m--;
    for (; m; m--)
      printf("%d", a[m]);
    printf("\n");
  }
  return 0;
}
