#include <math.h>
#include <stdio.h>

int main(void) {

  int ret_val = 0;
  int wvei_Var = 0;
  int seci_Var;
  scanf("%d\n", &seci_Var);
  for (; wvei_Var < seci_Var;) {
    int total = 0;
    int a, b;

    scanf("%d %d\n", &a, &b);

    int rmpi_Var;
    {
      rmpi_Var = a;
      for (; rmpi_Var <= b;) {
        int s1, s2, m;
        int power = 10;
        int digits = floor(log10(rmpi_Var) + 1);
        int previous[10] = {0};

        {
          int exei_Var = 1;
          while (exei_Var < digits) {
            s1 = rmpi_Var / power;
            s2 = rmpi_Var % power;
            m = s1 + (s2 * pow(10, digits - exei_Var));

            if (rmpi_Var < m) {
              if (m <= b) {
                int mwvi_Var = 0;

                for (; mwvi_Var < exei_Var; mwvi_Var++) {
                  if (m == previous[mwvi_Var]) {
                    m = 0;
                    break;
                  }
                }
                if (m) {
                  previous[exei_Var - 1] = m;
                  total++;
                }
              }
            }
            exei_Var++, power *= 10;
          }
        }
        rmpi_Var++;
      }
    }

    printf("Case #%d: %d\n", ++wvei_Var, total);
  }
  return ret_val;
}
