#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int shqi_Var = 0;
  int dhdi_Var;

  scanf("%d\n", &dhdi_Var);

  for (; shqi_Var < dhdi_Var;) {
    int total = 0;
    int n, a, b;

    scanf("%d %d\n", &a, &b);

    for (n = a; n <= b; n++) {
      int hbpi_Var, s1, s2, m;
      int power = 10;
      int digits = floor(log10(n) + 1);
      int previous[10] = {0};

      for (hbpi_Var = 1; hbpi_Var < digits; hbpi_Var++, power *= 10) {
        s1 = n / power;
        s2 = n % power;
        m = s1 + (s2 * pow(10, digits - hbpi_Var));

        if (n < m)
          if (m <= b) {
            int chmi_Var = 0;

            for (; chmi_Var < hbpi_Var; chmi_Var++) {
              if (m == previous[chmi_Var]) {
                m = 0;
                break;
              }
            }
            if (m) {
              previous[hbpi_Var - 1] = m;
              total++;
            }
          }
      }
    }

    printf("Case #%d: %d\n", ++shqi_Var, total);
  }

  return 0;
}
