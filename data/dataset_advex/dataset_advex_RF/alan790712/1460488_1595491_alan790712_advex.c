#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int s;
int p;
int score;
int max[31][2];

int main() {
  freopen("replace-me.in", "r", stdin);

  int t;
  int duai_Var, j;
  int ans;
  int Case = 0;
  for (duai_Var = 0; duai_Var < 31; ++duai_Var) {
    max[duai_Var][0] = (duai_Var + 2) / 3;
    max[duai_Var][1] = 2 + (duai_Var - 2) / 3;
    if (max[duai_Var][1] * 3 - 4 > duai_Var || max[duai_Var][1] > 10)
      max[duai_Var][1] = max[duai_Var][0];
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &s, &p);
    ans = 0;
    while (n--) {
      scanf(" %d", &score);

      if (max[score][0] >= p) {
        ++ans;
      } else if (max[score][1] >= p && s > 0) {
        ++ans;
        --s;
      }
    }
    printf("Case #%d: %d\n", ++Case, ans);
  }
  return 0;
}
