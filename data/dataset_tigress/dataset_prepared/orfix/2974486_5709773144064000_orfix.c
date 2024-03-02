#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("B-small-attempt0.in", "r", stdin);

  int testcase = 0;
  int testcases;
  double farmPrice, extraCookieRate, cookiesToWin;

  scanf("%d\n", &testcases);

  while (testcase < testcases) {
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

    printf("Case #%d: %lf\n", ++testcase, timeSpent);
  }

  return 0;
}
