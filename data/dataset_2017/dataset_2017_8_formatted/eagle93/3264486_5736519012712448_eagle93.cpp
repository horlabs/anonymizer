#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define REP(i, n) for ((i) = 0; (i) < (n); (i)++)
#define rep(i, x, n) for ((i) = (x); (i) < (n); (i)++)
#define REV(i, n) for ((i) = (n); (i) >= 0; (i)--)
#define FORIT(it, x) for ((it) = (x).begin(); (it) != (x).end(); (it)++)
#define foreach(it, c)                                                         \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define rforeach(it, c)                                                        \
  for (__typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); ++it)
#define foreach2d(i, j, v)                                                     \
  foreach (i, v)                                                               \
    foreach (j, *i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define MMS(x, n) memset(x, n, sizeof(x))
#define mms(x, n, s) memset(x, n, sizeof(x) * s)
#define pb push_back
#define mp make_pair
#define NX next_permutation
#define UN(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#define CV(x, n) count(all(x), (n))
#define FIND(x, n) find(all(x), (n)) - (x).begin()
#define ACC(x) accumulate(all(x), 0)
#define PPC(x) __builtin_popcount(x)
#define LZ(x) __builtin_clz(x)
#define TZ(x) __builtin_ctz(x)
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))
#define low(x, i) lower_bound(all(x), i)
#define upp(x, i) upper_bound(all(x), i)
#define NXPOW2(x) (1ll << ((int)log2(x) + 1))
#define PR(x) cout << #x << " = " << (x) << endl;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

const int OO = (int)2e9;
const double eps = 1e-9;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //#ifndef ONLINE_JUDGE
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  //#endif
  int t, tt = 1;
  cin >> t;
  while (t--) {
    string s;
    int n, k, res = 0;
    bool ok = 1;
    cin >> s >> k;
    n = SZ(s);
    for (int i = 0; i <= n - k; i++) {
      if (s[i] == '-') {
        for (int j = 0; j < k; j++) {
          s[i + j] = (s[i + j] == '+') ? '-' : '+';
        }
        res++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '-') {
        ok = 0;
        break;
      }
    }
    if (ok)
      cout << "Case #" << tt++ << ": " << res << "\n";
    else
      cout << "Case #" << tt++ << ": "
           << "IMPOSSIBLE"
           << "\n";
  }
  return 0;
}
