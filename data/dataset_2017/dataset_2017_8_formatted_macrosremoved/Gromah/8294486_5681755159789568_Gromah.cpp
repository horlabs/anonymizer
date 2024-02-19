#include <algorithm>
#include <cstdio>
using namespace std;
typedef long double LD;

int Case, n, q, V[100 + 5], E[100 + 5], S[100 + 5], Map[100 + 5][100 + 5],
    End[100 + 5], Sum[100 + 5];
LD ans, Dp[100 + 5][100 + 5];

int main() {
  scanf("%d", &Case);
  for (int T = 1; T <= Case; T++) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
      V[i] = End[i] = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d%d", E + i, S + i);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        scanf("%d", Map[i] + j);
    for (int i = 1; i < n; i++)
      Sum[i] = Sum[i - 1] + Map[i][i + 1];
    for (int i = 1; i < n; i++)
      for (int j = i; j < n && Sum[j] - Sum[i - 1] <= E[i]; j++)
        End[i] = j;
    scanf("%*d%*d");
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= n; j++)
        Dp[i][j] = 1e14;
    Dp[0][0] = 0;
    for (int i = 1; i < n; i++)
      for (int j = 0; j < i; j++) {
        if (End[j] >= i && j > 0)
          Dp[i][j] = min(Dp[i][j], Dp[i - 1][j] + (LD)Map[i][i + 1] / S[j]);
        if (i == 1 || j > 0)
          Dp[i][i] = min(Dp[i][i], Dp[i - 1][j] + (LD)Map[i][i + 1] / S[i]);
      }
    ans = Dp[n - 1][1];
    for (int j = 2; j < n; j++)
      ans = min(ans, Dp[n - 1][j]);
    printf("Case #%d: %.6f\n", T, (double)ans);
  }
  return 0;
}
