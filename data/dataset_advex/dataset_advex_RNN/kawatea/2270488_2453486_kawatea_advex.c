#include <stdio.h>

int main() {
  int t, i;

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    int f = 0, ztji_Var, k;
    char s[4][5];

    for (ztji_Var = 0; ztji_Var < 4; ztji_Var++)
      scanf("%s", s[ztji_Var]);

    for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
      for (k = 0; k < 4; k++) {
        if (s[ztji_Var][k] == 'O' || s[ztji_Var][k] == '.')
          break;
      }

      if (k == 4)
        f = 1;

      for (k = 0; k < 4; k++) {
        if (s[k][ztji_Var] == 'O' || s[k][ztji_Var] == '.')
          break;
      }

      if (k == 4)
        f = 1;

      for (k = 0; k < 4; k++) {
        if (s[ztji_Var][k] == 'X' || s[ztji_Var][k] == '.')
          break;
      }

      if (k == 4)
        f = 2;

      for (k = 0; k < 4; k++) {
        if (s[k][ztji_Var] == 'X' || s[k][ztji_Var] == '.')
          break;
      }

      if (k == 4)
        f = 2;
    }

    for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
      if (s[ztji_Var][ztji_Var] == 'O' || s[ztji_Var][ztji_Var] == '.')
        break;
    }

    if (ztji_Var == 4)
      f = 1;

    for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
      if (s[ztji_Var][3 - ztji_Var] == 'O' || s[ztji_Var][3 - ztji_Var] == '.')
        break;
    }

    if (ztji_Var == 4)
      f = 1;

    for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
      if (s[ztji_Var][ztji_Var] == 'X' || s[ztji_Var][ztji_Var] == '.')
        break;
    }

    if (ztji_Var == 4)
      f = 2;

    for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
      if (s[ztji_Var][3 - ztji_Var] == 'X' || s[ztji_Var][3 - ztji_Var] == '.')
        break;
    }

    if (ztji_Var == 4)
      f = 2;

    if (f == 1) {
      printf("Case #%d: X won\n", i + 1);
    } else if (f == 2) {
      printf("Case #%d: O won\n", i + 1);
    } else {
      for (ztji_Var = 0; ztji_Var < 4; ztji_Var++) {
        for (k = 0; k < 4; k++) {
          if (s[ztji_Var][k] == '.')
            f = 1;
        }
      }

      if (f == 1) {
        printf("Case #%d: Game has not completed\n", i + 1);
      } else {
        printf("Case #%d: Draw\n", i + 1);
      }
    }
  }

  return 0;
}
