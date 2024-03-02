#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TestCases, TCCount;
int A, B, S, E;
int Ans[10] = {1, 4, 9, 121, 484, 1200};

int main() {
  int ret_val = 0;
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);
  scanf("%d", &TestCases);
  for (TCCount = 1; TCCount <= TestCases; TCCount++) {
    printf("Case #%d: ", TCCount);
    scanf("%d%d", &A, &B);
    for (S = 0; Ans[S] < A; S++)
      ;
    for (E = S; Ans[E] <= B; E++)
      ;
    printf("%d\n", E - S);
  }
  return ret_val;
}
