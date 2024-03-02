#include <stdio.h>

int fcki_Var, qhoi_Var;
char Map[10][10];
int wgpi_Var, y, T, fbwi_Var;

int Solve() {
  for (y = 0; y < 4; y++) {
    T = 0;
    fbwi_Var = 0;
    {
      wgpi_Var = 0;
      for (; wgpi_Var < 4;) {
        if (Map[y][wgpi_Var] == 'X')
          fbwi_Var--;
        if (Map[y][wgpi_Var] == 'O')
          fbwi_Var++;
        if (Map[y][wgpi_Var] == 'T')
          T = 1;
        wgpi_Var++;
      }
    }
    if (T) {
      if (fbwi_Var < 0)
        fbwi_Var--;

      if (fbwi_Var > 0)
        fbwi_Var++;
    }
    if (fbwi_Var == -4) {
      printf("X won\n");
      return 0;
    }
    if (fbwi_Var == 4) {
      printf("O won\n");
      return 0;
    }
  }

  for (wgpi_Var = 0; wgpi_Var < 4; wgpi_Var++) {
    T = 0;
    fbwi_Var = 0;
    for (y = 0; y < 4; y++) {
      if (Map[y][wgpi_Var] == 'X')
        fbwi_Var--;
      if (Map[y][wgpi_Var] == 'O')
        fbwi_Var++;
      if (Map[y][wgpi_Var] == 'T')
        T = 1;
    }
    if (T) {
      if (fbwi_Var < 0)
        fbwi_Var--;
      if (fbwi_Var > 0)
        fbwi_Var++;
    }
    if (fbwi_Var == -4) {
      int ret_val = 0;
      printf("X won\n");
      return ret_val;
    }
    if (fbwi_Var == 4) {
      printf("O won\n");
      return 0;
    }
  }

  T = 0;
  fbwi_Var = 0;
  for (wgpi_Var = 0, y = 0; wgpi_Var < 4; wgpi_Var++, y++) {
    if (Map[y][wgpi_Var] == 'X')
      fbwi_Var--;
    if (Map[y][wgpi_Var] == 'O')
      fbwi_Var++;
    if (Map[y][wgpi_Var] == 'T')
      T = 1;
  }
  if (T) {
    if (fbwi_Var < 0)
      fbwi_Var--;
    if (fbwi_Var > 0)
      fbwi_Var++;
  }
  if (fbwi_Var == -4) {
    printf("X won\n");
    return 0;
  }
  if (fbwi_Var == 4) {
    printf("O won\n");
    return 0;
  }

  T = 0;
  fbwi_Var = 0;
  for (wgpi_Var = 3, y = 0; wgpi_Var >= 0; wgpi_Var--, y++) {
    if (Map[y][wgpi_Var] == 'X')
      fbwi_Var--;
    if (Map[y][wgpi_Var] == 'O')
      fbwi_Var++;
    if (Map[y][wgpi_Var] == 'T')
      T = 1;
  }
  if (T) {
    if (fbwi_Var < 0)
      fbwi_Var--;
    if (fbwi_Var > 0)
      fbwi_Var++;
  }
  if (fbwi_Var == -4) {
    printf("X won\n");
    return 0;
  }
  if (fbwi_Var == 4) {
    printf("O won\n");
    return 0;
  }

  for (y = 0; y < 4; y++)
    for (wgpi_Var = 0; wgpi_Var < 4; wgpi_Var++)
      if (Map[y][wgpi_Var] == '.') {
        printf("Game has not completed\n");
        return 0;
      }
  printf("Draw\n");
  return 0;
}

int main() {

  scanf("%d", &fcki_Var);
  for (qhoi_Var = 1; qhoi_Var <= fcki_Var; qhoi_Var++) {
    printf("Case #%d: ", qhoi_Var);

    for (y = 0; y < 4; y++)
      scanf("%s", Map[y]);

    Solve();
  }

  return 0;
}
