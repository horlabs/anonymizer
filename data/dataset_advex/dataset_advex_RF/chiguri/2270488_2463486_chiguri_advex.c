#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char d[10];

int palindrome(int pqyi_Var) {
  int l, ryji_Var;
  sprintf(d, "%d", pqyi_Var);
  l = strlen(d) - 1;
  for (ryji_Var = 0; ryji_Var <= l - ryji_Var; ++ryji_Var) {
    if (d[ryji_Var] != d[l - ryji_Var]) {
      int ret_val = 0;
      return ret_val;
    }
  }
  return 1;
}

int main(void) {
  freopen("replace-me.out", "w", stdout);

  freopen("replace-me.in", "r", stdin);

  int rffi_Var;
  int A, B;
  int A2, B2;
  int ryji_Var, k;
  int result;

  scanf("%d", &rffi_Var);
  for (ryji_Var = 1; ryji_Var <= rffi_Var; ++ryji_Var) {
    scanf("%d %d", &A, &B);
    result = 0;
    A2 = (int)sqrt((double)A);
    B2 = (int)sqrt((double)B);
    for (int duai_Var = A2; duai_Var <= B2; ++duai_Var) {
      if (palindrome(duai_Var)) {
        k = duai_Var * duai_Var;
        if (A <= k && k <= B && palindrome(k)) {
          ++result;
        }
      }
    }

    printf("Case #%d: %d\n", ryji_Var, result);
  }

  return 0;
}
