#include <stdio.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;
  int fbwi_Var;
  scanf("%d", &fbwi_Var);
  int ceti_Var;
  for (ceti_Var = 1; ceti_Var <= fbwi_Var; ceti_Var++) {
    int dtgi_Var, b;
    scanf("%d %d", &dtgi_Var, &b);
    int idyi_Var = 0;
    int digmul = 1;
    int digs = 1;
    int hfhi_Var;
    {
      hfhi_Var = dtgi_Var;
      while (hfhi_Var >= 10) {
        digmul *= 10;
        digs++;
        hfhi_Var /= 10;
        hfhi_Var++;
      }
    }
    {
      int hwyi_Var = dtgi_Var;
      while (hwyi_Var <= b) {
        int m = hwyi_Var;
        int previous[digs];
        int d;
        for (d = 0; d < digs; d++) {
          previous[d] = m;
          m = (m % 10) * digmul + (m / 10);
          if (m / digmul == 0)
            continue;
          else if (m > b)
            continue;
          else if (m <= hwyi_Var)
            continue;
          int igbi_Var;
          for (igbi_Var = 0; igbi_Var < d; igbi_Var++) {
            if (previous[igbi_Var] == m)
              goto bad;
          }
          idyi_Var++;
        bad:;
        }
        hwyi_Var++;
      }
    }
    printf("Case #%d: %d\n", ceti_Var, idyi_Var);
  }
  return ret_val;
}
