#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// freopen("", "r", stdin);
// freopen("", "w", stdout);
// printf("Case #%d: ", ii);

struct NODE {
  long long k, d;
} nodes[1010];

int main() {
  freopen("A-small-attempt0(1).in", "r", stdin);
  freopen("A-small-attempt0(1).out", "w", stdout);
  int T;
  int d, n;
  scanf("%d", &T);
  for (int ii = 1; ii <= T; ii++) {
    scanf("%d%d", &d, &n);
    struct NODE min1;
    min1.k = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &nodes[i].d, &nodes[i].k);
      if (min1.k == -1) {
        min1.d = d - nodes[i].d;
        min1.k = nodes[i].k;
      } else if (min1.d * nodes[i].k < min1.k * (d - nodes[i].d)) {
        min1.d = d - nodes[i].d;
        min1.k = nodes[i].k;
      }
    }
    printf("Case #%d: %.10lf\n", ii, d * min1.k * 1.0 / min1.d);
  }
  return 0;
}
