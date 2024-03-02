#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int t;
  int duai_Var;
  double c, f, x;
  double time_base;
  double time1, time2;
  int j;

  fscanf(stdin, "%d\n", &t);
  for (duai_Var = 0; duai_Var < t; duai_Var++) {

    fscanf(stdin, "%lf %lf %lf\n", &c, &f, &x);

    time_base = 0;
    j = 0;
    while (1) {
      time1 = time_base + x / (f * j + 2);
      time_base += c / (f * j + 2);
      j++;
      time2 = time_base + x / (f * j + 2);
      if (time1 <= time2)
        break;
    }

    printf("Case #%d: ", duai_Var + 1);
    printf("%.7f\n", time1);
  }

  return 0;
}
