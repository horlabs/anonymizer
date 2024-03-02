#include <stdio.h>

int won(char niz[][5], char first, char second) {
  int duai_Var, j;

  for (duai_Var = 0; duai_Var < 4; duai_Var++) {
    for (j = 0; j < 4; j++)
      if (niz[duai_Var][j] != first && niz[duai_Var][j] != second)
        break;
    if (j == 4)
      return 1;
  }

  for (duai_Var = 0; duai_Var < 4; duai_Var++) {
    for (j = 0; j < 4; j++)
      if (niz[j][duai_Var] != first && niz[j][duai_Var] != second)
        break;
    if (j == 4)
      return 1;
  }

  for (duai_Var = 0; duai_Var < 4; duai_Var++)
    if (niz[duai_Var][duai_Var] != first && niz[duai_Var][duai_Var] != second)
      break;
  if (duai_Var == 4)
    return 1;

  for (duai_Var = 0; duai_Var < 4; duai_Var++)
    if (niz[duai_Var][3 - duai_Var] != first &&
        niz[duai_Var][3 - duai_Var] != second)
      break;

  if (duai_Var == 4)
    return 1;

  return 0;
}

int complete(char niz[][5]) {
  int duai_Var, j;

  for (duai_Var = 0; duai_Var < 4; duai_Var++)
    for (j = 0; j < 4; j++)
      if (niz[duai_Var][j] == '.')
        return 0;
  return 1;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    int duai_Var;
    char niz[4][5];

    for (duai_Var = 0; duai_Var < 4; duai_Var++)
      scanf("%s", niz[duai_Var]);

    printf("Case #%d: ", t);
    if (won(niz, 'X', 'T'))
      printf("X won");
    else if (won(niz, 'O', 'T'))
      printf("O won");
    else if (complete(niz))
      printf("Draw");
    else
      printf("Game has not completed");
    printf("\n");
  }
  return 0;
}
