#include <stdio.h>

int main(void) {
  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;
  freopen("replace-me.out", "w", stdout);
  int zhzi_Var, duai_Var, brpi_Var, twgi_Var;
  int x, o, t, blanco;
  int ganax, ganao, encontrado;
  char tablero[4][4];
  scanf("%d\n", &zhzi_Var);
  for (duai_Var = 1; duai_Var <= zhzi_Var; duai_Var++) {
    encontrado = 0;

    blanco = x = o = t = 0;
    for (brpi_Var = 0; brpi_Var < 4; brpi_Var++) {
      {
        twgi_Var = 0;
        while (twgi_Var < 4) {
          tablero[brpi_Var][twgi_Var] = getchar();
          if (tablero[brpi_Var][twgi_Var] == '.') {
            blanco++;
          } else if (tablero[brpi_Var][twgi_Var] == 'X') {
            x++;
          } else if (tablero[brpi_Var][twgi_Var] == 'O') {
            o++;
          } else {
            t++;
          }
          twgi_Var++;
        }
      }
      getchar();
    }
    getchar();

    if ((x + t) < 3) {
      printf("Case #%d: Game has not completed\n", duai_Var);
      continue;
    }

    for (brpi_Var = 0; brpi_Var < 4; brpi_Var++) {
      ganax = ganao = 0;
      for (twgi_Var = 0; twgi_Var < 4; twgi_Var++) {
        if (tablero[brpi_Var][twgi_Var] == 'X') {
          ganax++;
        } else if (tablero[brpi_Var][twgi_Var] == 'O') {
          ganao++;
        } else if (tablero[brpi_Var][twgi_Var] == 'T') {
          ganax++;
          ganao++;
        }
      }
      if (ganax == 4) {
        printf("Case #%d: X won\n", duai_Var);
        encontrado = 1;
      } else if (ganao == 4) {
        printf("Case #%d: O won\n", duai_Var);
        encontrado = 1;
      }
    }
    if (encontrado) {
      continue;
    }

    {
      brpi_Var = 0;
      while (brpi_Var < 4) {
        ganax = ganao = 0;
        for (twgi_Var = 0; twgi_Var < 4; twgi_Var++) {
          if (tablero[twgi_Var][brpi_Var] == 'X')
            ganax++;
          else if (tablero[twgi_Var][brpi_Var] == 'O') {
            ganao++;
          } else if (tablero[twgi_Var][brpi_Var] == 'T') {
            ganax++;
            ganao++;
          }
        }
        if (ganax == 4) {
          printf("Case #%d: X won\n", duai_Var);
          encontrado = 1;
        } else if (ganao == 4) {
          printf("Case #%d: O won\n", duai_Var);
          encontrado = 1;
        }
        brpi_Var++;
      }
    }
    if (encontrado) {
      continue;
    }

    ganax = ganao = 0;
    for (brpi_Var = 0; brpi_Var < 4; brpi_Var++) {
      if (tablero[brpi_Var][brpi_Var] == 'X') {
        ganax++;
      } else if (tablero[brpi_Var][brpi_Var] == 'O') {
        ganao++;
      } else if (tablero[brpi_Var][brpi_Var] == 'T') {
        ganax++;
        ganao++;
      }
    }
    if (ganax == 4) {
      printf("Case #%d: X won\n", duai_Var);
      encontrado = 1;
    } else if (ganao == 4) {
      printf("Case #%d: O won\n", duai_Var);
      encontrado = 1;
    }
    if (encontrado) {
      continue;
    }

    ganax = ganao = 0;
    for (brpi_Var = 0; brpi_Var < 4; brpi_Var++) {
      if (tablero[brpi_Var][3 - brpi_Var] == 'X') {
        ganax++;
      } else if (tablero[brpi_Var][3 - brpi_Var] == 'O')
        ganao++;
      else {
        if (tablero[brpi_Var][3 - brpi_Var] == 'T') {
          ganax++;
          ganao++;
        }
      }
    }
    if (ganax == 4) {
      printf("Case #%d: X won\n", duai_Var);
      encontrado = 1;
    } else if (ganao == 4) {
      printf("Case #%d: O won\n", duai_Var);
      encontrado = 1;
    }
    if (encontrado)
      continue;

    if (blanco > 1) {
      printf("Case #%d: Game has not completed\n", duai_Var);
    } else {
      printf("Case #%d: Draw\n", duai_Var);
    }
  }
  return ret_val;
}
