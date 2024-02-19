
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair<int, int> pii;
template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;
using namespace std;

ull num[20][10];

void precompute() {
  for (int i = 1; i <= 9; i++)
    num[1][i] = i;
  for (int i = 2; i <= 19; i++) {
    for (int j = 1; j <= 9; j++) {
      num[i][j] = num[i - 1][j] * 10 + j;
    }
  }
}

int digitCnt(ll n) {
  if (n == 0)
    return 1;
  int ans = 0;
  while (n > 0) {
    ans++;
    n /= 10;
  }
  return ans;
}

ull solve(ull n) {
  if (n <= 9)
    return n;
  int cnt = digitCnt(n);
  ull ans = 0;
  if (n < num[cnt][1])
    return num[cnt - 1][9];
  ull p = 1;
  for (int i = 0; i < cnt - 1; i++)
    p *= 10;
  for (int i = 9; i >= 1; i--) {
    if (num[cnt][i] <= n) {
      ll x = num[cnt][i] / p;
      ll nn = n - x * p;
      if (nn > p)
        nn = num[cnt - 1][9];
      ll y = solve(nn);
      return x * p + y;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precompute();
  int NUMBER_OF_TESTS;
  cin >> NUMBER_OF_TESTS;
  for (int t = 1; t <= NUMBER_OF_TESTS; t++) {
    ull n;
    cin >> n;
    cout << "Case #" << t << ": " << solve(n) << "\n";
  }
  return 0;
}
