
#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>

FILE *ifile = nullptr;
std::ofstream ofile;

void solve(int _case) {
  char str[1001];
  int data[1001];
  int adj[1001];
  int n = 0;
  int k = 0;
  int counter = 0;
  int sum = 0;

  std::fscanf(ifile, "%1000s %d", str, &k);

  for (n = 0; n < 1001; ++n) {
    if (0 == str[n])
      break;
    data[n] = '-' == str[n] ? 0 : 1;
    adj[n] = 0;
  }

  for (auto i = 0; i < n; ++i) {
    sum += adj[i];
    data[i] = (sum + data[i]) & 1;
    if (0 == data[i] && i < (n - k + 1)) {
      ++counter;
      ++sum;
      data[i] = 1;
      --adj[i + k];
    }
  }

  for (auto i = 0; i < n; ++i)
    if (0 == data[i]) {
      ofile << "Case #" << _case << ": IMPOSSIBLE\n";
      return;
    }

  ofile << "Case #" << _case << ": " << counter << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  ifile = fopen("1.in", "r");
  ofile.open("output.out");

  int n = 0;
  std::fscanf(ifile, "%d", &n);
  for (auto i = 0; i < n; ++i)
    solve(i + 1);

  ofile.close();

  return 0;
}
