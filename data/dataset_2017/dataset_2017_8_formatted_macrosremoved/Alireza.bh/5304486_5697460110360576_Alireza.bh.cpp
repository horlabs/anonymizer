
#pragma comment(linker, "/STACK:100000000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
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
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;

int findmini(int x, int s) {
  int res = (x * 10) / (11 * s);
  if ((x * 10) % (11 * s) == 0)
    return res;
  return res + 1;
}
int findmaxi(int x, int s) {
  int res = (x * 10) / (9 * s);
  return res;
}

bool graph[128][128];
bool seen[128];
int matchL[128], matchR[128];
int n, p;

bool bpm(int u) {
  for (int v = 0; v < p; v++)
    if (graph[u][v]) {
      if (seen[v])
        continue;
      seen[v] = true;

      if (matchR[v] < 0 || bpm(matchR[v])) {
        matchL[u] = v;
        matchR[v] = u;
        return true;
      }
    }
  return false;
}

int main() {
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int Tcas;
  cin >> Tcas;
  for (int(cas) = 0; (cas) < (Tcas); (cas)++) {
    printf("Case #%d: ", cas + 1);
    cin >> n >> p;
    vector<int> ingredients;
    for (int(i) = 0; (i) < (n); (i)++) {
      int x;
      cin >> x;
      ingredients.push_back(x);
    }
    int mini[100][100] = {0};
    int maxi[100][100] = {0};
    memset((mini), (0), sizeof(mini));
    memset((maxi), (0), sizeof(maxi));
    for (int(i) = 0; (i) < (n); (i)++) {
      vector<int> temp;
      for (int(j) = 0; (j) < (p); (j)++) {
        int x;
        cin >> x;
        temp.push_back(x);
      }
      sort((temp).begin(), (temp).end());
      for (int(j) = 0; (j) < (p); (j)++) {
        mini[i][j] = findmini(temp[j], ingredients[i]);
        maxi[i][j] = findmaxi(temp[j], ingredients[i]);
        if (mini[i][j] > maxi[i][j])
          mini[i][j] = maxi[i][j] = -1;
      }
    }
    memset((graph), (false), sizeof(graph));
    for (int(i) = 0; (i) < (p); (i)++)
      for (int(j) = 0; (j) < (p); (j)++) {
        if (mini[0][i] <= 0 || mini[1][j] <= 0)
          continue;
        if (max(mini[0][i], mini[1][j]) <= min(maxi[0][i], maxi[1][j]))
          graph[i][j] = true;
      }
    if (n == 2) {
      memset(matchL, -1, sizeof(matchL));
      memset(matchR, -1, sizeof(matchR));
      int cnt = 0;
      for (int i = 0; i < p; i++) {
        memset(seen, 0, sizeof(seen));
        if (bpm(i))
          cnt++;
      }
      cout << cnt << endl;
    } else {
      int sum = 0;
      for (int(i) = 0; (i) < (p); (i)++)
        if (mini[0][i] != -1 && mini[0][i] <= maxi[0][i])
          sum++;
      cout << sum << endl;
    }
  }
}
