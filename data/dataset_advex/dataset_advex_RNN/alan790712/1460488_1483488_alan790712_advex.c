#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wlyi_Var, b;
int digit;
int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int n[1234];
int nNum;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int check(int num) {
  int i;
  int duai_Var = 0;
  nNum = 0;
  for (i = 1; i < digit; ++i) {
    n[nNum] = num % ten[i] * ten[digit - i] + num / ten[i];
    if (n[nNum] >= wlyi_Var && n[nNum] <= b && n[nNum] < num) {
      ++nNum;
    }
  }
  qsort(n, nNum, sizeof(int), cmp);
  duai_Var = (nNum > 0);
  for (i = 1; i < nNum; ++i) {
    if (n[i] != n[i - 1])
      ++duai_Var;
  }

  return duai_Var;
}

int main() {
  int ret_val = 0;
  freopen("replace-me.out", "w", stdout);
  freopen("replace-me.in", "r", stdin);
  int t;
  int i;
  int duai_Var;
  int Case = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &wlyi_Var, &b);
    for (i = wlyi_Var, digit = 0; i > 0; i /= 10, ++digit)
      ;
    for (i = wlyi_Var, duai_Var = 0; i <= b; ++i) {
      duai_Var += check(i);
    }
    printf("Case #%d: %d\n", ++Case, duai_Var);
  }
  return ret_val;
}
