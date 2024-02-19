/* ***************************************
Author        :Scau.ion
Created Time  :2017/04/23 00:52:23 UTC+8
File Name     :ion.cpp
*************************************** */

#include <bits/stdc++.h>
using namespace std;
const double inf = 1e18;

int dis[110][110];
int e[110], s[110];
double mi[110];

int main() {
  freopen("C-small-attempt0.in", "r", stdin);
  ;
  freopen("C-small-attempt0.out", "w", stdout);
  ;
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n, q;
    cin >> n >> q;
    for (int j = 1; j <= n; ++j)
      cin >> e[j] >> s[j];
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        cin >> dis[j][k];
      }
    }
    int u, v;
    cin >> u >> v;
    mi[1] = 0;
    for (int j = 2; j <= n; ++j)
      mi[j] = inf;
    for (int j = 1; j < n; ++j) {
      int sum = 0;
      for (int k = j + 1; k <= n; ++k) {
        sum += dis[k - 1][k];
        if (sum > e[j])
          break;
        double ti = (double)sum / (double)s[j];
        mi[k] = min(mi[k], mi[j] + ti);
      }
    }
    printf("Case #%d: %.6lf\n", i, mi[n]);
  }
  return 0;
}
