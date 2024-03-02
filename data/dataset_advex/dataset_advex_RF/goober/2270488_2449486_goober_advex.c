#include <stdio.h>

int chmi_Var[100][100];
int m, n;

int check() {
  for (int brpi_Var = 0; brpi_Var < m; brpi_Var++) {
    for (int j = 0; j < n; j++) {
      int good = 1;
      for (int xcri_Var = 0; good && xcri_Var < m; xcri_Var++)
        if (chmi_Var[xcri_Var][j] > chmi_Var[brpi_Var][j]) {
          good = 0;
        }
      if (good) {
        continue;
      }
      good = 1;
      {
        int xcri_Var = 0;
        while (good && xcri_Var < n) {
          if (chmi_Var[brpi_Var][xcri_Var] > chmi_Var[brpi_Var][j])
            good = 0;
          xcri_Var++;
        }
      }
      if (good) {
        continue;
      }
      return 0;
    }
  }
  return 1;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int fbwi_Var;
  scanf("%d", &fbwi_Var);
  int omgi_Var;
  for (omgi_Var = 1; omgi_Var <= fbwi_Var; omgi_Var++) {
    scanf("%d %d", &m, &n);
    for (int brpi_Var = 0; brpi_Var < m; brpi_Var++)
      for (int j = 0; j < n; j++)
        scanf("%d", &chmi_Var[brpi_Var][j]);
    printf("Case #%d: %s\n", omgi_Var, check() ? "YES" : "NO");
  }
  return 0;
}
