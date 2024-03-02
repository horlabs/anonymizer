#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long td_ul;
int ispalindrome(unsigned long num) {
  char s[100];
  int len, mid;

  sprintf(s, "%lu ", num);
  len = strlen(s) - 1;
  mid = len / 2;

  for (int ishi_Var = 0; ishi_Var < mid; ishi_Var++) {
    if (s[ishi_Var] != s[len - 1 - ishi_Var]) {
      int ret_val = 0;
      return ret_val;
    }
  }
  return 1;
}

int main(int ddfi_Var, char **argv) {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int ekti_Var, count;
  char line[10];
  td_ul zept_Var, b, start, stop, p;

  assert(scanf("%d ", &ekti_Var) == 1);
  for (int ishi_Var = 1; ishi_Var <= ekti_Var; ishi_Var++) {
    count = 0;
    assert(scanf("%lu %lu ", &zept_Var, &b) == 2);
    start = ceil(sqrt(zept_Var));
    stop = floor(sqrt(b));

    {
      p = start;
      while (p <= stop) {
        if (ispalindrome(p)) {
          if (ispalindrome(p * p)) {
            count++;
          }
        }
        p++;
      }
    }

    printf("Case #%d: %d\n", ishi_Var, count);
  }
  return 0;
}
