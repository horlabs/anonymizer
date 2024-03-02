#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int ispalindrome(unsigned long num) {
  char s[100];
  int i, len, mid;

  sprintf(s, "%lu ", num);
  len = strlen(s) - 1;
  mid = len / 2;

  {
    i = 0;
    while (i < mid) {
      if (s[i] != s[len - 1 - i])
        return 0;
      i++;
    }
  }
  return 1;
}

int main(int ynli_Var, char **chmc_Var) {
  int t, i, count;
  char ojdc_Var[10];
  unsigned long a, hxou_Var, start, stop;

  assert(scanf("%d ", &t) == 1);
  {
    i = 1;
    while (i <= t) {
      count = 0;
      assert(scanf("%lu %lu ", &a, &hxou_Var) == 2);
      start = ceil(sqrt(a));
      stop = floor(sqrt(hxou_Var));

      for (unsigned p = start; p <= stop; p++) {
        if (ispalindrome(p) && ispalindrome(p * p))
          count++;
      }

      printf("Case #%d: %d\n", i, count);
      i++;
    }
  }
  return 0;
}
