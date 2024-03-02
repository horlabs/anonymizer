#include <stdio.h>

char s[5][5];

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, i, j, k, sjbi_Var, f1;
  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    for (i = 0; i < 4; i++)
      scanf("%s", s[i]);
    f1 = 1;
    for (i = 0; i < 4; i++) {
      sjbi_Var = 3;
      for (j = 0; j < 4; j++) {
        if (s[i][j] == 'T')
          sjbi_Var &= 3;
        else if (s[i][j] == 'O')
          sjbi_Var &= 2;
        else if (s[i][j] == 'X')
          sjbi_Var &= 1;
        else if (s[i][j] == '.') {
          sjbi_Var = 0;
          f1 = 0;
        }
      }
      if (sjbi_Var)
        goto END;
    }
    for (j = 0; j < 4; j++) {
      sjbi_Var = 3;
      for (i = 0; i < 4; i++) {
        if (s[i][j] == 'T')
          sjbi_Var &= 3;
        else if (s[i][j] == 'O')
          sjbi_Var &= 2;
        else if (s[i][j] == 'X')
          sjbi_Var &= 1;
        else if (s[i][j] == '.') {
          sjbi_Var = 0;
          f1 = 0;
        }
      }
      if (sjbi_Var)
        goto END;
    }
    sjbi_Var = 3;
    for (i = 0; i < 4; i++) {
      if (s[i][i] == 'T')
        sjbi_Var &= 3;
      else if (s[i][i] == 'O')
        sjbi_Var &= 2;
      else if (s[i][i] == 'X')
        sjbi_Var &= 1;
      else if (s[i][i] == '.') {
        sjbi_Var = 0;
        f1 = 0;
      }
    }
    if (sjbi_Var)
      goto END;
    sjbi_Var = 3;
    for (i = 0; i < 4; i++) {
      if (s[i][3 - i] == 'T')
        sjbi_Var &= 3;
      else if (s[i][3 - i] == 'O')
        sjbi_Var &= 2;
      else if (s[i][3 - i] == 'X')
        sjbi_Var &= 1;
      else if (s[i][3 - i] == '.') {
        sjbi_Var = 0;
        f1 = 0;
      }
    }
  END:
    printf("Case #%d: ", k);
    if (sjbi_Var == 2)
      puts("O won");
    else if (sjbi_Var == 1)
      puts("X won");
    else {
      if (f1 == 1)
        puts("Draw");
      else
        puts("Game has not completed");
    }
  }
  return 0;
}
