#include <assert.h>
#include <math.h>
#include <stdio.h>

int move(int num, int steps, int size) {
  int r, m = 1, sm = 1, ddfi_Var;

  ddfi_Var = size - steps;
  while (ddfi_Var--)
    m = m * 10;

  while (steps--) {
    sm = sm * 10;
  }
  r = (num % m) * sm + (num / m);
  return r;
}

int main(int ahli_Var, char **zvmc_Var) {
  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;
  freopen("replace-me.out", "w", stdout);
  int qhoi_Var, dtgi_Var, dpii_Var, temp, digits, cbvi_Var, m;
  int dup;
  assert(scanf("%d", &dpii_Var) == 1);
  {
    int ysji_Var = 1;
    while (ysji_Var <= dpii_Var) {
      cbvi_Var = 0;
      assert(scanf("%d %d", &qhoi_Var, &dtgi_Var) == 2);
      for (int zvmi_Var = qhoi_Var; zvmi_Var <= dtgi_Var; zvmi_Var++) {
        dup = 0;
        digits = floor(log10(zvmi_Var)) + 1;
        {
          int k = 1;
          while (k < digits) {
            m = move(zvmi_Var, k, digits);
            if (m >= qhoi_Var && m <= dtgi_Var && m > zvmi_Var && m != dup) {

              cbvi_Var++;
              dup = m;
            }
            k++;
          }
        }
      }
      printf("Case #%d: %d\n", ysji_Var, cbvi_Var);
      ysji_Var++;
    }
  }
  return ret_val;
}
