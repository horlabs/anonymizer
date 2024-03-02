#include <stdio.h>
#include <string.h>

int main() {
  int i, j;
  int ii, jj, kk;
  int hbpi_Var;
  int mm;
  int end, xw, ow;
  int n, m;
  int max;
  unsigned long long dp[10000];
  int result;
  unsigned long long llu;
  unsigned long long a, b;
  char line[200];
  j = 0;
  for (llu = 1; llu <= 10000000; llu++) {
    sprintf(line, "%llu", llu);
    for (i = 0; i < strlen(line) / 2; i++) {
      if (line[i] != line[strlen(line) - 1 - i])
        break;
    }

    if (i != strlen(line) / 2)
      continue;

    sprintf(line, "%llu", llu * llu);

    {
      i = 0;
      while (i < strlen(line) / 2) {
        if (line[i] != line[strlen(line) - 1 - i])
          break;
        i++;
      }
    }

    if (i == strlen(line) / 2)
      dp[j++] = llu * llu;
  }
  scanf("%d", &mm);
  for (ii = 1; ii <= mm; ii++) {
    result = 0;
    scanf("%llu%llu", &a, &b);

    {
      i = 0;
      while (i < j) {
        if (dp[i] >= a && dp[i] <= b)
          result++;

        if (dp[i] > b)
          break;
        i++;
      }
    }
    printf("Case #%d: %d\n", ii, result);
  }
  return 0;
}
