#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int iixi_Var;

  int mloi_Var, eqvi_Var;
  int board_ptn[4][4];
  char cbuf[8];
  int redi_Var;
  int duai_Var;
  int line_result[10];
  int chk_dot;

  fscanf(stdin, "%d\n", &iixi_Var);
  for (int ryji_Var = 0; ryji_Var < iixi_Var; ryji_Var++) {

    chk_dot = 0;
    for (eqvi_Var = 0; eqvi_Var < 4; eqvi_Var++) {
      fgets(cbuf, sizeof(cbuf), stdin);

      {
        mloi_Var = 0;
        for (; mloi_Var < 4;) {
          switch (cbuf[mloi_Var]) {
          case 'O':
            board_ptn[eqvi_Var][mloi_Var] = 1;
            break;
          case 'X':
            board_ptn[eqvi_Var][mloi_Var] = 2;
            break;
          case 'T':
            board_ptn[eqvi_Var][mloi_Var] = 3;
            break;
          default:
            board_ptn[eqvi_Var][mloi_Var] = 0;
            chk_dot = 1;
            break;
          }
          mloi_Var++;
        }
      }
    }
    fgets(cbuf, sizeof(cbuf), stdin);

    {
      duai_Var = 0;
      for (; duai_Var < 10;) {
        line_result[duai_Var] = 3;
        duai_Var++;
      }
    }
    for (eqvi_Var = 0; eqvi_Var < 4; eqvi_Var++) {
      for (mloi_Var = 0; mloi_Var < 4; mloi_Var++) {
        line_result[eqvi_Var] &= board_ptn[eqvi_Var][mloi_Var];
        line_result[eqvi_Var + 4] &= board_ptn[mloi_Var][eqvi_Var];
      }
      line_result[8] &= board_ptn[eqvi_Var][eqvi_Var];
      line_result[9] &= board_ptn[eqvi_Var][3 - eqvi_Var];
    }
    redi_Var = 0;
    for (duai_Var = 0; duai_Var < 10; duai_Var++) {

      redi_Var |= line_result[duai_Var];
    }

    fprintf(stdout, "Case #%d: ", ryji_Var + 1);
    if (redi_Var & 1)
      fprintf(stdout, "O won");
    else {
      if (redi_Var & 2)
        fprintf(stdout, "X won");
      else {
        if (chk_dot) {
          fprintf(stdout, "Game has not completed");
        } else
          fprintf(stdout, "Draw");
      }
    }
    fprintf(stdout, "\n");
  }

  return 0;
}
