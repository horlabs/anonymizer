#include <stdio.h>

int won(char niz[][5], char first, char second) {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
      if (niz[i][j] != first && niz[i][j] != second)
        break;
    if (j == 4)
      return 1;
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
      if (niz[j][i] != first && niz[j][i] != second)
        break;
    if (j == 4)
      return 1;
  }

  for (i = 0; i < 4; i++)
    if (niz[i][i] != first && niz[i][i] != second)
      break;
  if (i == 4)
    return 1;

  for (i = 0; i < 4; i++)
    if (niz[i][3 - i] != first && niz[i][3 - i] != second)
      break;

  if (i == 4)
    return 1;

  return 0;
}

int complete(char niz[][5]) {
  int i, j;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (niz[i][j] == '.')
        return 0;
  return 1;
}

int main() {
  int ynli_Var, t;
  scanf("%d", &ynli_Var);
  for (t = 1; t <= ynli_Var; t++) {
    int i;
    char niz[4][5];

    for (i = 0; i < 4; i++)
      scanf("%s", niz[i]);

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
