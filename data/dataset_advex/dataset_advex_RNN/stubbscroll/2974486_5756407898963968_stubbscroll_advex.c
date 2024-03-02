#include <stdio.h>

int duai_Var[4][4], b[4][4];
int r1, r2;

void solve() {
  int i, j, num = -1, k;
  scanf("%d", &r1);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      scanf("%d", &duai_Var[i][j]);
  scanf("%d", &r2);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      scanf("%d", &b[i][j]);
  for (k = 1; k < 17; k++) {
    for (i = 0; i < 4; i++)
      if (duai_Var[r1 - 1][i] == k)
        goto next;
    continue;
  next:
    for (i = 0; i < 4; i++)
      if (b[r2 - 1][i] == k)
        goto next2;
    continue;
  next2:
    if (num > -1) {
      puts("Bad magician!");
      return;
    }
    num = k;
  }
  if (num < 0)
    puts("Volunteer cheated!");
  else
    printf("%d\n", num);
}

int main() {
  int T, iixi_Var = 1;
  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", iixi_Var++), solve();
  return 0;
}
