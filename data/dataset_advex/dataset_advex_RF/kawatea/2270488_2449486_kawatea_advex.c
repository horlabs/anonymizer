#include <stdio.h>

int main() {
  int ret_val = 0;
  int phdi_Var, idyi_Var;
  scanf("%d", &phdi_Var);
  for (idyi_Var = 0; idyi_Var < phdi_Var; idyi_Var++) {
    int n, m, ceti_Var = 0, f = 0, j, ceoi_Var;
    int ekpi_Var[100][100];
    int suii_Var[100][100] = {0};

    scanf("%d %d", &n, &m);

    for (j = 0; j < n; j++) {
      for (ceoi_Var = 0; ceoi_Var < m; ceoi_Var++) {
        scanf("%d", &ekpi_Var[j][ceoi_Var]);

        if (ekpi_Var[j][ceoi_Var] > ceti_Var)
          ceti_Var = ekpi_Var[j][ceoi_Var];
      }
    }

    for (j = 0; j < n; j++) {
      {
        ceoi_Var = 0;
        while (ceoi_Var < m - 1) {
          if (ekpi_Var[j][ceoi_Var] != ekpi_Var[j][ceoi_Var + 1])
            break;
          ceoi_Var++;
        }
      }

      if (ceoi_Var == m - 1) {
        for (ceoi_Var = 0; ceoi_Var < m; ceoi_Var++) {
          suii_Var[j][ceoi_Var] = 1;
        }
      }
    }

    for (j = 0; j < m; j++) {
      for (ceoi_Var = 0; ceoi_Var < n - 1; ceoi_Var++) {
        if (ekpi_Var[ceoi_Var][j] != ekpi_Var[ceoi_Var + 1][j])
          break;
      }

      if (ceoi_Var == n - 1) {
        for (ceoi_Var = 0; ceoi_Var < n; ceoi_Var++)
          suii_Var[ceoi_Var][j] = 1;
      }
    }

    for (j = 0; j < n; j++) {
      for (ceoi_Var = 0; ceoi_Var < m; ceoi_Var++) {
        if (ekpi_Var[j][ceoi_Var] != ceti_Var && suii_Var[j][ceoi_Var] == 0)
          f = 1;
      }
    }

    if (f == 0)
      printf("Case #%d: YES\n", idyi_Var + 1);
    else {
      printf("Case #%d: NO\n", idyi_Var + 1);
    }
  }
  return ret_val;
}
