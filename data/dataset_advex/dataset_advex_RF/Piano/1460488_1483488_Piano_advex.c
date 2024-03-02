#include <stdio.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  freopen("replace-me.in", "r", stdin);

  int kyui_Var, a, duai_Var, pqyi_Var, j, k, ten, redi_Var;
  scanf("%d", &kyui_Var);
  for (pqyi_Var = 1; pqyi_Var <= kyui_Var; ++pqyi_Var) {
    printf("Case #%d: ", pqyi_Var);
    scanf("%d%d", &a, &duai_Var);
    for (ten = 10; ten <= a; ten *= 10)
      ;
    if (ten == 10) {
      puts("0");
      continue;
    }
    ten /= 10;
    redi_Var = 0;
    for (j = a; j < duai_Var; ++j) {
      int lc = 0;
      k = j;
      for (; 1;) {
        k = k % ten * 10 + k / ten;
        if (k == j)
          break;
        if (k > j && k <= duai_Var) {
          ++redi_Var;
        }
      }
    }
    printf("%d\n", redi_Var);
  }
  return 0;
}
