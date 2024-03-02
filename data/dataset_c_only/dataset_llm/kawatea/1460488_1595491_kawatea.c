#include <stdio.h>

void initializeArrays(int b[31][11], int dp[101][101]) {
  for (int i = 0; i <= 30; i++) {
    for (int j = 0; j <= 10; j++) {
      if (i % 3 == 0) {
        if (i / 3 >= j) b[i][j] |= 1;
      } else {
        for (int k = 10; k >= 1; k--) {
          if (k * 3 - 1 >= i && k * 3 - 2 <= i) {
            if (k >= j) b[i][j] |= 1;
            break;
          }
        }
      }

      for (int k = 10; k >= 2; k--) {
        if (k * 3 - 2 >= i && k * 3 - 4 <= i) {
          if (k >= j) b[i][j] |= 2;
          break;
        }
      }
    }
  }

  for (int j = 0; j <= 101; j++) {
    for (int k = 0; k <= 101; k++) {
      dp[j][k] = 0;
    }
  }
}

int maximum(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int t, n, s, p, i, j, k;
  int a[100];
  int b[31][11] = {0};
  int dp[101][101];

  initializeArrays(b, dp);

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    scanf("%d %d %d", &n, &s, &p);

    for (j = 0; j < n; j++) scanf("%d", &a[j]);

    for (j = 0; j < n; j++) {
      for (k = 0; k < s; k++) {
        if (b[a[j]][p] & 1) {
          dp[j + 1][k] = maximum(dp[j + 1][k], dp[j][k] + 1);
        } else {
          dp[j + 1][k] = maximum(dp[j + 1][k], dp[j][k]);
        }

        if (b[a[j]][p] & 2) {
          dp[j + 1][k + 1] = maximum(dp[j + 1][k + 1], dp[j][k] + 1);
        } else {
          dp[j + 1][k + 1] = maximum(dp[j + 1][k + 1], dp[j][k]);
        }
      }

      if (b[a[j]][p] & 1) {
        dp[j + 1][s] = maximum(dp[j + 1][s], dp[j][s] + 1);
      } else {
        dp[j + 1][s] = maximum(dp[j + 1][s], dp[j][s]);
      }
    }

    printf("Case #%d: %d\n", i + 1, dp[n][s]);
  }

  return 0;
}