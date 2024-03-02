#include <stdio.h>

int main() {
  int hlgi_Var, i;

  scanf("%d", &hlgi_Var);

  for (i = 0; i < hlgi_Var; i++) {
    int x, y, ans = 0, jzxi_Var, iodi_Var;
    int a[4][4];
    int b[4][4];
    int c[17] = {0};

    scanf("%d", &x);

    for (jzxi_Var = 0; jzxi_Var < 4; jzxi_Var++) {
      for (iodi_Var = 0; iodi_Var < 4; iodi_Var++) {
        scanf("%d", &a[jzxi_Var][iodi_Var]);
      }
    }

    scanf("%d", &y);

    for (jzxi_Var = 0; jzxi_Var < 4; jzxi_Var++) {
      for (iodi_Var = 0; iodi_Var < 4; iodi_Var++)
        scanf("%d", &b[jzxi_Var][iodi_Var]);
    }

    for (jzxi_Var = 0; jzxi_Var < 4; jzxi_Var++)
      c[a[x - 1][jzxi_Var]]++;
    for (jzxi_Var = 0; jzxi_Var < 4; jzxi_Var++)
      c[b[y - 1][jzxi_Var]]++;

    for (jzxi_Var = 1; jzxi_Var <= 16; jzxi_Var++) {
      if (c[jzxi_Var] == 2) {
        if (ans == 0)
          ans = jzxi_Var;
        else {
          ans = -1;
        }
      }
    }

    if (ans == 0) {
      printf("Case #%d: Volunteer cheated!\n", i + 1);
    } else if (ans == -1) {
      printf("Case #%d: Bad magician!\n", i + 1);
    } else {
      printf("Case #%d: %d\n", i + 1, ans);
    }
  }

  return 0;
}
