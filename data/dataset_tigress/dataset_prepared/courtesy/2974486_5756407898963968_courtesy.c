#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i, j, k, r, x, an, b, c;
  int a[4];
  scanf("%d", &t);
  for (c = 1; c <= t; c++) {
    scanf("%d", &r);
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        scanf("%d", &x);
        if (j == (r - 1)) {
          a[k] = x;
        }
      }
    }
    b = 0;
    scanf("%d", &r);
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        scanf("%d", &x);
        if (j == (r - 1)) {
          if ((x == a[0]) || (x == a[1]) || (x == a[2]) || (x == a[3])) {
            if (b == 0) {
              an = x;
              b = 1;
            } else
              b = 2;
          }
        }
      }
    }
    if (b == 1)
      printf("Case #%d: %d\n", c, an);
    else if (b == 0)
      printf("Case #%d: Volunteer cheated!\n", c);
    else
      printf("Case #%d: Bad magician!\n", c);
  }
}
