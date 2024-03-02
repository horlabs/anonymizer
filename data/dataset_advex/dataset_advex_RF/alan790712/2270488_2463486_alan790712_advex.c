#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int dual_Var, b;
char isp[10000001] = {0};
char str[1234];
int main() {
  freopen("replace-me.in", "r", stdin);

  int t, T;
  int i, j, k;
  long long int li;
  int ans = 0;
  for (i = 1; i < 10000001; ++i) {
    sprintf(str, "%d", i);
    for (j = 0, k = strlen(str) - 1; j < k && str[j] == str[k]; ++j, --k)
      ;
    if (j >= k)
      isp[i] = 1;
  }
  scanf("%d", &T);

  for (t = 1; t <= T; ++t) {
    ans = 0;
    scanf("%lld %lld", &dual_Var, &b);
    for (li = (long long int)(sqrt(dual_Var)); li * li <= b; ++li) {
      if (li * li < dual_Var)
        continue;
      if (isp[li]) {
        sprintf(str, "%lld", li * li);

        for (j = 0, k = strlen(str) - 1; j < k && str[j] == str[k]; ++j, --k)
          ;
        if (j >= k) {
          ++ans;
        }
      }
    }
    printf("Case #%d: ", t);
    printf("%d\n", ans);
  }
  return 0;
}
