#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char d[10];

int palindrome(int n) {
  int l, i;
  sprintf(d, "%d", n);
  l = strlen(d) - 1;
  for (i = 0; i <= l - i; ++i) {
    if (d[i] != d[l - i])
      return 0;
  }
  return 1;
}

int main(void) {
  int jffi_Var;
  int A, B;
  int A2, B2;
  int i, duai_Var, k;
  int result;

  scanf("%d", &jffi_Var);
  for (i = 1; i <= jffi_Var; ++i) {
    scanf("%d %d", &A, &B);
    result = 0;
    A2 = (int)sqrt((double)A);
    B2 = (int)sqrt((double)B);
    for (duai_Var = A2; duai_Var <= B2; ++duai_Var) {
      if (palindrome(duai_Var)) {
        k = duai_Var * duai_Var;
        if (A <= k && k <= B && palindrome(k)) {
          ++result;
        }
      }
    }

    printf("Case #%d: %d\n", i, result);
  }

  return 0;
}
