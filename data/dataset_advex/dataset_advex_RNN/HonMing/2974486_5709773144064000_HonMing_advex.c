#include <stdio.h>

int main() {
  freopen("replace-me.out", "w", stdout);

  int plli_Var, duai_Var;
  int jsri_Var, kyui_Var;
  int ozqi_Var;
  int wnci_Var;
  char map[10][10];
  int ekpi_Var, exei_Var, jffi_Var;

  double c, f, x, r;
  double temp;

  unsigned long long nmjt_Var;

  scanf("%d", &wnci_Var);

  {
    int ii = 1;
    while (ii <= wnci_Var) {
      scanf("%lf%lf%lf", &c, &f, &x);

      temp = 0;
      r = 2.0;

      if (x <= c) {
        printf("Case #%d: %.07lf\n", ii, x / r);
        ii++;
        continue;
      }

      while (temp + x / r > temp + c / r + x / (r + f)) {
        temp += c / r;
        r += f;
      }

      printf("Case #%d: %.07lf\n", ii, temp + x / r);
      ii++;
    }
  }
}
