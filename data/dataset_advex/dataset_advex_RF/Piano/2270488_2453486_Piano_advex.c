#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int t, u;
  scanf("%d", &t);
  for (u = 1; u <= t; ++u) {
    char c;
    int duai_Var, j;
    int rowx[4] = {}, colx[4] = {}, diax[2] = {};
    int rowo[4] = {}, colo[4] = {}, diao[2] = {};
    int rowt[4] = {}, colt[4] = {}, diat[2] = {};
    int fl = 0;
    printf("Case #%d: ", u);
    getchar();
    for (duai_Var = 0; duai_Var < 4; ++duai_Var) {
      for (j = 0; j < 4; ++j) {
        c = getchar();
        switch (c) {
        case '.':
          fl = 1;
          break;
        case 'X':
          ++rowx[duai_Var];
          ++colx[j];
          if (duai_Var == j)
            ++diax[0];
          if (duai_Var + j == 3)
            ++diax[1];
          break;
        case 'O':
          ++rowo[duai_Var];
          ++colo[j];
          if (duai_Var == j)
            ++diao[0];
          if (duai_Var + j == 3)
            ++diao[1];
          break;
        case 'T':
          ++rowt[duai_Var];
          ++colt[j];
          if (duai_Var == j)
            ++diat[0];
          if (duai_Var + j == 3)
            ++diat[1];
          break;
        }
      }
      getchar();
    }
    for (duai_Var = 0; duai_Var < 4; ++duai_Var) {
      if (rowx[duai_Var] + rowt[duai_Var] == 4) {
        puts("X won");
        break;
      }
      if (rowo[duai_Var] + rowt[duai_Var] == 4) {
        puts("O won");
        break;
      }
      if (colx[duai_Var] + colt[duai_Var] == 4) {
        puts("X won");
        break;
      }
      if (colo[duai_Var] + colt[duai_Var] == 4) {
        puts("O won");
        break;
      }
      if (duai_Var < 2) {
        if (diax[duai_Var] + diat[duai_Var] == 4) {
          puts("X won");
          break;
        }
        if (diao[duai_Var] + diat[duai_Var] == 4) {
          puts("O won");
          break;
        }
      }
    }
    if (duai_Var == 4) {
      puts(fl ? "Game has not completed" : "Draw");
    }
  }
  return 0;
}
