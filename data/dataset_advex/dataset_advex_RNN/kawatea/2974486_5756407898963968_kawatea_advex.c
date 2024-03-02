#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, duai_Var;

  scanf("%d", &t);

  for (duai_Var = 0; duai_Var < t; duai_Var++) {
    int x, y, ans = 0, j, k;
    int a[4][4];
    int b[4][4];
    int c[17] = {0};

    scanf("%d", &x);

    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        scanf("%d", &a[j][k]);
      }
    }

    scanf("%d", &y);

    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        scanf("%d", &b[j][k]);
      }
    }

    for (j = 0; j < 4; j++)
      c[a[x - 1][j]]++;
    for (j = 0; j < 4; j++)
      c[b[y - 1][j]]++;

    for (j = 1; j <= 16; j++) {
      if (c[j] == 2) {
        if (ans == 0) {
          ans = j;
        } else {
          ans = -1;
        }
      }
    }

    if (ans == 0) {
      printf("Case #%d: Volunteer cheated!\n", duai_Var + 1);
    } else if (ans == -1) {
      printf("Case #%d: Bad magician!\n", duai_Var + 1);
    } else {
      printf("Case #%d: %d\n", duai_Var + 1, ans);
    }
  }

  return 0;
}
