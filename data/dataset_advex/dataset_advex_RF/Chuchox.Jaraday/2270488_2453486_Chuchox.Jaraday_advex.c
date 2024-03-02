#include <stdio.h>

int main(void) {

  int ret_val = 0;
  freopen("replace-me.in", "r", stdin);
  int gymi_Var, omgi_Var, ysxi_Var;
  int x, o, t, blanco;
  int ganax, ganao, encontrado;
  char tablero[4][4];
  scanf("%d\n", &gymi_Var);
  for (int deci_Var = 1; deci_Var <= gymi_Var; deci_Var++) {
    encontrado = 0;

    blanco = x = o = t = 0;
    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      {
        ysxi_Var = 0;
        for (; ysxi_Var < 4;) {
          tablero[omgi_Var][ysxi_Var] = getchar();
          if (tablero[omgi_Var][ysxi_Var] == '.') {
            blanco++;
          } else if (tablero[omgi_Var][ysxi_Var] == 'X') {
            x++;
          } else if (tablero[omgi_Var][ysxi_Var] == 'O') {
            o++;
          } else
            t++;
          ysxi_Var++;
        }
      }
      getchar();
    }
    getchar();

    if ((x + t) < 3) {
      printf("Case #%d: Game has not completed\n", deci_Var);
      continue;
    }

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      ganax = ganao = 0;
      for (ysxi_Var = 0; ysxi_Var < 4; ysxi_Var++) {
        if (tablero[omgi_Var][ysxi_Var] == 'X')
          ganax++;
        else if (tablero[omgi_Var][ysxi_Var] == 'O') {
          ganao++;
        } else if (tablero[omgi_Var][ysxi_Var] == 'T') {
          ganax++;
          ganao++;
        }
      }
      if (ganax == 4) {
        printf("Case #%d: X won\n", deci_Var);
        encontrado = 1;
      } else {
        if (ganao == 4) {
          printf("Case #%d: O won\n", deci_Var);
          encontrado = 1;
        }
      }
    }
    if (encontrado) {
      continue;
    }

    for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
      ganax = ganao = 0;
      {
        ysxi_Var = 0;
        for (; ysxi_Var < 4;) {
          if (tablero[ysxi_Var][omgi_Var] == 'X')
            ganax++;
          else {
            if (tablero[ysxi_Var][omgi_Var] == 'O') {
              ganao++;
            } else {
              if (tablero[ysxi_Var][omgi_Var] == 'T') {
                ganax++;
                ganao++;
              }
            }
          }
          ysxi_Var++;
        }
      }
      if (ganax == 4) {
        printf("Case #%d: X won\n", deci_Var);
        encontrado = 1;
      } else if (ganao == 4) {
        printf("Case #%d: O won\n", deci_Var);
        encontrado = 1;
      }
    }
    if (encontrado)
      continue;

    ganax = ganao = 0;
    {
      omgi_Var = 0;
      for (; omgi_Var < 4;) {
        if (tablero[omgi_Var][omgi_Var] == 'X') {
          ganax++;
        } else if (tablero[omgi_Var][omgi_Var] == 'O') {
          ganao++;
        } else {
          if (tablero[omgi_Var][omgi_Var] == 'T') {
            ganax++;
            ganao++;
          }
        }
        omgi_Var++;
      }
    }
    if (ganax == 4) {
      printf("Case #%d: X won\n", deci_Var);
      encontrado = 1;
    } else {
      if (ganao == 4) {
        printf("Case #%d: O won\n", deci_Var);
        encontrado = 1;
      }
    }
    if (encontrado) {
      continue;
    }

    ganax = ganao = 0;
    {
      omgi_Var = 0;
      while (omgi_Var < 4) {
        if (tablero[omgi_Var][3 - omgi_Var] == 'X') {
          ganax++;
        } else if (tablero[omgi_Var][3 - omgi_Var] == 'O') {
          ganao++;
        } else if (tablero[omgi_Var][3 - omgi_Var] == 'T') {
          ganax++;
          ganao++;
        }
        omgi_Var++;
      }
    }
    if (ganax == 4) {
      printf("Case #%d: X won\n", deci_Var);
      encontrado = 1;
    } else if (ganao == 4) {
      printf("Case #%d: O won\n", deci_Var);
      encontrado = 1;
    }
    if (encontrado)
      continue;

    if (blanco > 1) {
      printf("Case #%d: Game has not completed\n", deci_Var);
    } else {
      printf("Case #%d: Draw\n", deci_Var);
    }
  }
  return ret_val;
}
