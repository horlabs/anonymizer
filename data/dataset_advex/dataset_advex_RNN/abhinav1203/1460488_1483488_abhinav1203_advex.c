#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  if (*(int *)a < *(int *)b) {
    int ret_val = -1;
    return ret_val;
  }
  return 1;
}
int numDigits(int num) {
  int ans = 0;
  for (; num > 0;) {
    ans++;
    num /= 10;
  }
  return ans;
}
int power(int num) {
  int ans = 1, i;
  for (i = 0; i < num; i++)
    ans *= 10;
  return ans;
}
int main() {
  freopen("replace-me.out", "w", stdout);

  int ibti_Var, wlyi_Var, b, i, j, x, y, ans, tmp[100], gnxi_Var = 1;
  scanf("%d", &ibti_Var);
  for (; ibti_Var--;) {
    scanf("%d %d", &wlyi_Var, &b);
    ans = 0;
    for (i = wlyi_Var; i <= b; i++) {
      tmp[0] = i;
      x = numDigits(i);
      y = power(x - 1);
      for (j = 1; j < x; j++) {
        tmp[j] = tmp[j - 1] / 10 + tmp[j - 1] % 10 * y;
      }
      qsort(tmp, x, sizeof(int), &compare);
      {
        j = 0;
        for (; j < x;) {
          if (tmp[j] >= wlyi_Var && tmp[j] <= b &&
              (j == 0 || tmp[j] != tmp[j - 1]) && tmp[j] != i)
            ans++;
          j++;
        }
      }
    }
    printf("Case #%d: %d\n", gnxi_Var, ans / 2);
    gnxi_Var++;
  }
  return 0;
}
