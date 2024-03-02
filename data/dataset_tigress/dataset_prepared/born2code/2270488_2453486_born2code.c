#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T1, T, dot, x, o, i, j, xc, oc, t;
  char a[4][4];

  T = 1;
  for (scanf("%d", &T1); T <= T1; T++) {
    dot = x = o = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        do {
          a[i][j] = getchar();
        } while (!(a[i][j] == '.' || a[i][j] == 'T' || a[i][j] == 'O' ||
                   a[i][j] == 'X'));

        if (a[i][j] == '.')
          dot = 1;
      }
    }

    for (i = 0; i < 4; i++) {
      xc = oc = t = 0;
      for (j = 0; j < 4; j++) {
        if (a[i][j] == 'T')
          t = 1;
        else if (a[i][j] == 'X')
          xc++;
        else if (a[i][j] == 'O')
          oc++;
      }
      if ((xc == 4) || (xc == 3 && t == 1))
        x = 1;
      if ((oc == 4) || (oc == 3 && t == 1))
        o = 1;
    }

    for (j = 0; j < 4; j++) {
      xc = oc = t = 0;
      for (i = 0; i < 4; i++) {
        if (a[i][j] == 'T')
          t = 1;
        else if (a[i][j] == 'X')
          xc++;
        else if (a[i][j] == 'O')
          oc++;
      }
      if ((xc == 4) || (xc == 3 && t == 1))
        x = 1;
      if ((oc == 4) || (oc == 3 && t == 1))
        o = 1;
    }
    xc = oc = t = 0;
    for (j = 0; j < 4; j++) {
      if (a[j][j] == 'T')
        t = 1;
      else if (a[j][j] == 'X')
        xc++;
      else if (a[j][j] == 'O')
        oc++;
    }
    if ((xc == 4) || (xc == 3 && t == 1))
      x = 1;
    if ((oc == 4) || (oc == 3 && t == 1))
      o = 1;

    xc = oc = t = 0;
    for (j = 3; j >= 0; j--) {
      if (a[j][3 - j] == 'T')
        t = 1;
      else if (a[j][3 - j] == 'X')
        xc++;
      else if (a[j][3 - j] == 'O')
        oc++;
    }
    if ((xc == 4) || (xc == 3 && t == 1))
      x = 1;
    if ((oc == 4) || (oc == 3 && t == 1))
      o = 1;

    printf("Case #%d: ", T);
    if (x == 1)
      printf("X won\n");
    else if (o == 1)
      printf("O won\n");
    else if (dot == 1)
      printf("Game has not completed\n");
    else
      printf("Draw\n");
  }
  return 0;
}
