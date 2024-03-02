#include <stdio.h>

typedef double td_d;
int main(void) {
  freopen("replace-me.out", "w", stdout);

  int ret_val = 0;

  int nvpi_Var = 0;
  int ceti_Var;
  td_d farmPrice, extraCookieRate, cookiesToWin;
  scanf("%d\n", &ceti_Var);
  while (nvpi_Var < ceti_Var) {
    td_d timeSpent = 0;
    td_d cookieRate = 2;

    scanf("%lf %lf %lf\n", &farmPrice, &extraCookieRate, &cookiesToWin);

    for (; 1;) {
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

    printf("Case #%d: %lf\n", ++nvpi_Var, timeSpent);
  }
  return ret_val;
}
