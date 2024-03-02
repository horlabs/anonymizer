#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i, j;
  int ii, jj, kk;
  int res;
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

    for (i = 0; i < strlen(line) / 2; i++) {
      if (line[i] != line[strlen(line) - 1 - i])
        break;
    }

    if (i == strlen(line) / 2)
      dp[j++] = llu * llu;
  }

  scanf("%d", &mm);

  for (ii = 1; ii <= mm; ii++) {
    result = 0;
    scanf("%llu%llu", &a, &b);

    for (i = 0; i < j; i++) {
      if (dp[i] >= a && dp[i] <= b)
        result++;

      if (dp[i] > b)
        break;
    }
    printf("Case #%d: %d\n", ii, result);
  }
}
