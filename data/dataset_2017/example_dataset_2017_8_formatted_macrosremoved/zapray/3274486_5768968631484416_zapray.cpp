
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

using namespace std;

bool comp(pair<double, double> &x, pair<double, double> &y) {
  return x.first * x.second > y.first * y.second;
}

int main() {
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    printf("Case #%d: ", cs);

    int k, n;
    cin >> n >> k;

    vector<pair<double, double>> cakes;

    for (int i = 0; i < n; i++) {
      double r, h;
      cin >> r >> h;
      cakes.push_back(make_pair(r, h));
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
      double base_r = cakes[i].first;

      vector<pair<double, double>> candidates;
      for (int j = 0; j < n; j++) {
        if (j == i)
          continue;
        if (cakes[j].first <= base_r)
          candidates.push_back(cakes[j]);
      }
      if (candidates.size() < k - 1)
        continue;

      sort(candidates.begin(), candidates.end(), comp);

      double area = base_r * base_r * 3.14159265358979323846;
      area += 2 * 3.14159265358979323846 * base_r * cakes[i].second;
      for (int j = 0; j < k - 1; j++) {
        area += 2 * 3.14159265358979323846 * candidates[j].first *
                candidates[j].second;
      }

      ans = max(ans, area);
    }

    printf("%.9lf\n", ans);
  }
  return 0;
}
