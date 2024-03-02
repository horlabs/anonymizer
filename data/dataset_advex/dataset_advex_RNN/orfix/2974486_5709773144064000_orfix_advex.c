#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int jqhi_Var = 0;
  int jzxi_Var;
  double farmPrice, extraCookieRate, cookiesToWin;

  scanf("%d\n", &jzxi_Var);

  for (; jqhi_Var < jzxi_Var;) {
    double timeSpent = 0;
    double cookieRate = 2;

    scanf("%lf %lf %lf\n", &farmPrice, &extraCookieRate, &cookiesToWin);

    while (1) {
      if (timeSpent + (cookiesToWin / cookieRate) >
          timeSpent + (farmPrice / cookieRate) +
              (cookiesToWin / (cookieRate + extraCookieRate))) {

        timeSpent += farmPrice / cookieRate;
        cookieRate += extraCookieRate;
      } else {

        timeSpent += cookiesToWin / cookieRate;
        break;
      }
    }

    printf("Case #%d: %lf\n", ++jqhi_Var, timeSpent);
  }

  return 0;
}
