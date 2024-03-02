#include <stdio.h>

int main(void) {
  char kyuc_Var[4 + 1],
      *output[] = {"X won", "O won", "Draw", "Game has not completed"};
  int zcei_Var, agni_Var, scti_Var, f, board[4][4], fbwi_Var;
  FILE *fsqF_Var = fopen("A-small-attempt0.in", "r"),
       *qwdF_Var = fopen("out.txt", "w");

  fscanf(fsqF_Var, "%d", &fbwi_Var);

  for (int omgi_Var = 0; omgi_Var < fbwi_Var; omgi_Var++) {
    for (zcei_Var = 0; zcei_Var < 4; zcei_Var++) {
      fscanf(fsqF_Var, "%s", kyuc_Var);
      for (agni_Var = 0; agni_Var < 4; agni_Var++) {
        board[zcei_Var][agni_Var] =
            (kyuc_Var[agni_Var] == 'X'
                 ? 10
                 : (kyuc_Var[agni_Var] == 'O'
                        ? 100
                        : (kyuc_Var[agni_Var] == 'T' ? 5 : 0)));
      }
    }

    for (f = zcei_Var = 0; zcei_Var < 4 && !f; zcei_Var++) {
      for (scti_Var = agni_Var = 0; agni_Var < 4;
           scti_Var += board[zcei_Var][agni_Var++]) {
        ;
      }
      if (scti_Var == 305) {
        {
          agni_Var = 0;
          while (agni_Var < 4 && board[zcei_Var][agni_Var] == 5) {
            ;
            agni_Var++;
          }
        }
        f = board[zcei_Var][agni_Var] == 10 ? 1 : 2;
      } else if (scti_Var == 400) {
        for (agni_Var = 0; agni_Var < 4 && board[zcei_Var][agni_Var] == 5;
             agni_Var++)
          ;
        f = board[zcei_Var][agni_Var] == 10 ? 1 : 2;
      } else if (scti_Var == 40 || scti_Var == 35) {
        for (agni_Var = 0; agni_Var < 4 && board[zcei_Var][agni_Var] == 5;
             agni_Var++)
          ;
        f = board[zcei_Var][agni_Var] == 10 ? 1 : 2;
      }
    }

    for (zcei_Var = 0; zcei_Var < 4 && !f; zcei_Var++) {
      {
        scti_Var = agni_Var = 0;
        for (; agni_Var < 4;) {
          ;
          scti_Var += board[agni_Var++][zcei_Var];
        }
      }
      if (scti_Var == 305) {
        for (agni_Var = 0; agni_Var < 4 && board[agni_Var][zcei_Var] == 5;
             agni_Var++)
          ;
        f = board[agni_Var][zcei_Var] == 10 ? 1 : 2;
      } else if (scti_Var == 400) {
        for (agni_Var = 0; agni_Var < 4 && board[agni_Var][zcei_Var] == 5;
             agni_Var++)
          ;
        f = board[agni_Var][zcei_Var] == 10 ? 1 : 2;
      } else if (scti_Var == 40 || scti_Var == 35) {
        for (agni_Var = 0; agni_Var < 4 && board[agni_Var][zcei_Var] == 5;
             agni_Var++)
          ;
        f = board[agni_Var][zcei_Var] == 10 ? 1 : 2;
      }
    }

    for (scti_Var = zcei_Var = 0; zcei_Var < 4 && !f; zcei_Var++) {
      scti_Var += board[zcei_Var][zcei_Var];
    }
    if (!f)
      if ((scti_Var == 40 || scti_Var == 35 || scti_Var == 400 ||
           scti_Var == 305)) {
        for (agni_Var = 0; agni_Var < 4 && board[agni_Var][agni_Var] == 5;
             agni_Var++)
          ;
        f = board[agni_Var][agni_Var] == 10 ? 1 : 2;
      }

    for (scti_Var = zcei_Var = 0; zcei_Var < 4 && !f; zcei_Var++)
      scti_Var += board[zcei_Var][4 - 1 - zcei_Var];
    if (!f && (scti_Var == 40 || scti_Var == 35 || scti_Var == 400 ||
               scti_Var == 305)) {
      for (agni_Var = 0; agni_Var < 4 && board[agni_Var][agni_Var] == 5;
           agni_Var++)
        ;

      f = board[agni_Var][4 - 1 - agni_Var] == 10 ? 1 : 2;
    }

    if (!f) {
      {
        agni_Var = 4, zcei_Var = 0;
        for (; zcei_Var < 4 && agni_Var == 4;) {
          for (agni_Var = 0; agni_Var < 4 && board[zcei_Var][agni_Var] != 0;
               agni_Var++)
            ;
          zcei_Var++;
        }
      }
      f = (zcei_Var == 4 ? 3 : 4);
    }

    fprintf(qwdF_Var, "Case #%d: %s\n", omgi_Var + 1, output[f - 1]);
  }

  fclose(fsqF_Var);
  fclose(qwdF_Var);
  return 0;
}
