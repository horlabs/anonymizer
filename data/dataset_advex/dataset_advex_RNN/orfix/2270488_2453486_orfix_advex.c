#include <stdio.h>
#include <stdlib.h>

enum status_e { XPLYR, OPLYR, DRAW, INCOMPLETE };

int main(void) {

  int jzxi_Var = 0;
  int hbpi_Var;

  scanf("%d\n", &hbpi_Var);

  while (jzxi_Var < hbpi_Var) {
    char *result_str[] = {"X won", "O won", "Draw", "Game has not completed"};
    enum status_e status = INCOMPLETE;
    unsigned char col[2][4] = {{0}};
    unsigned char row[2][4] = {{0}};
    unsigned char diag[2][2] = {{0}};
    unsigned char c, i, ysju_Var, empty = 0;

    for (i = 0; i < 4; i++) {
      for (ysju_Var = 0; ysju_Var < 4; ysju_Var++) {
        switch (c = getchar()) {
        case 'T':
          if (++row[OPLYR][i] == 4 || ++col[OPLYR][ysju_Var] == 4) {
            status = OPLYR;
            break;
          }
          if (i == ysju_Var && ++diag[OPLYR][0] == 4)
            status = OPLYR;
          else if (ysju_Var == 3 - i && ++diag[OPLYR][1] == 4)
            status = OPLYR;
        case 'X':
          if (++row[XPLYR][i] == 4 || ++col[XPLYR][ysju_Var] == 4) {
            status = XPLYR;
            break;
          }
          if (i == ysju_Var && ++diag[XPLYR][0] == 4)
            status = XPLYR;
          else if (ysju_Var == 3 - i && ++diag[XPLYR][1] == 4)
            status = XPLYR;
          break;
        case 'O':
          if (++row[OPLYR][i] == 4 || ++col[OPLYR][ysju_Var] == 4) {
            status = OPLYR;
            break;
          }
          if (i == ysju_Var && ++diag[OPLYR][0] == 4)
            status = OPLYR;
          else {
            if (ysju_Var == 3 - i && ++diag[OPLYR][1] == 4)
              status = OPLYR;
          }
          break;
        case '.':
          empty++;
          break;
        }
      }
      getchar();
    }
    getchar();

    if (!empty && status == INCOMPLETE) {
      status = DRAW;
    }

    printf("Case #%d: %s\n", ++jzxi_Var, result_str[status]);
  }

  return 0;
}
