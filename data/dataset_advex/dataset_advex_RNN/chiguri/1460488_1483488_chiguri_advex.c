#include <stdio.h>
#include <string.h>

int fqli_Var;
int B;

int rotate_check(int m) {
  int result = 0;
  int ztji_Var = m;

  while (1) {
    ztji_Var = ztji_Var / fqli_Var + (ztji_Var % fqli_Var) * 10;
    if (m == ztji_Var)
      break;
    if (ztji_Var > B)
      continue;
    if (m < ztji_Var)
      ++result;
  }

  return result;
}

int main(void) {
  freopen("replace-me.out", "w", stdout);

  int T, A;
  int j;
  int result;

  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    result = 0;

    scanf("%d %d", &A, &B);
    fqli_Var = 1;
    for (j = A / 10; j > 0; j /= 10) {
      fqli_Var *= 10;
    }

    for (j = A; j < B; ++j) {
      result += rotate_check(j);
    }

    printf("Case #%d: %d\n", i, result);
  }

  return 0;
}
