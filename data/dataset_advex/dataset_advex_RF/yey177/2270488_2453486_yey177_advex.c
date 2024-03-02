#include <stdio.h>

char s[5][5];

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, duai_Var, j, k, f, f1;
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    for (duai_Var = 0; duai_Var < 4; duai_Var++)
      scanf("%s", s[duai_Var]);
    f1 = 1;
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      f = 3;
      for (j = 0; j < 4; j++) {
        if (s[duai_Var][j] == 'T')
          f &= 3;
        else if (s[duai_Var][j] == 'O')
          f &= 2;
        else if (s[duai_Var][j] == 'X')
          f &= 1;
        else if (s[duai_Var][j] == '.') {
          f = 0;
          f1 = 0;
        }
      }
      if (f)
        goto END;
    }
    for (j = 0; j < 4; j++) {
      f = 3;
      for (duai_Var = 0; duai_Var < 4; duai_Var++) {
        if (s[duai_Var][j] == 'T')
          f &= 3;
        else if (s[duai_Var][j] == 'O')
          f &= 2;
        else if (s[duai_Var][j] == 'X')
          f &= 1;
        else if (s[duai_Var][j] == '.') {
          f = 0;
          f1 = 0;
        }
      }
      if (f)
        goto END;
    }
    f = 3;
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      if (s[duai_Var][duai_Var] == 'T')
        f &= 3;
      else if (s[duai_Var][duai_Var] == 'O')
        f &= 2;
      else if (s[duai_Var][duai_Var] == 'X')
        f &= 1;
      else if (s[duai_Var][duai_Var] == '.') {
        f = 0;
        f1 = 0;
      }
    }
    if (f)
      goto END;
    f = 3;
    for (duai_Var = 0; duai_Var < 4; duai_Var++) {
      if (s[duai_Var][3 - duai_Var] == 'T')
        f &= 3;
      else if (s[duai_Var][3 - duai_Var] == 'O')
        f &= 2;
      else if (s[duai_Var][3 - duai_Var] == 'X')
        f &= 1;
      else if (s[duai_Var][3 - duai_Var] == '.') {
        f = 0;
        f1 = 0;
      }
    }
  END:
    printf("Case #%d: ", k);
    if (f == 2)
      puts("O won");
    else if (f == 1)
      puts("X won");
    else if (f1 == 1)
      puts("Draw");
    else
      puts("Game has not completed");
  }
  return 0;
}
