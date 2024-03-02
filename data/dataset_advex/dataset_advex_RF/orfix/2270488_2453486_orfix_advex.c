#include <stdio.h>

enum status_e { XPLYR, OPLYR, DRAW, INCOMPLETE };

int main(void) {
  freopen("replace-me.out", "w", stdout);

  int sxei_Var = 0;
  int kyui_Var;

  scanf("%d\n", &kyui_Var);

  for (; sxei_Var < kyui_Var;) {
    char *result_str[] = {"X won", "O won", "Draw", "Game has not completed"};
    enum status_e status = INCOMPLETE;
    unsigned char col[2][4] = {{0}};
    unsigned char row[2][4] = {{0}};
    unsigned char diag[2][2] = {{0}};
    unsigned char c, wlyu_Var, empty = 0;

    {
      wlyu_Var = 0;
      while (wlyu_Var < 4) {
        {
          unsigned char ahlu_Var = 0;
          for (; ahlu_Var < 4;) {
            switch (c = getchar()) {
            case 'T':
              if (++col[OPLYR][ahlu_Var] == 4) {
                status = OPLYR;
                break;
              } else if (++row[OPLYR][wlyu_Var] == 4) {
                status = OPLYR;
                break;
              }
              if (wlyu_Var == ahlu_Var && ++diag[OPLYR][0] == 4)
                status = OPLYR;
              else if (ahlu_Var == 3 - wlyu_Var && ++diag[OPLYR][1] == 4)
                status = OPLYR;
            case 'X':
              if (++col[XPLYR][ahlu_Var] == 4) {
                status = XPLYR;
                break;
              } else {
                if (++row[XPLYR][wlyu_Var] == 4) {
                  status = XPLYR;
                  break;
                }
              }
              if (wlyu_Var == ahlu_Var && ++diag[XPLYR][0] == 4)
                status = XPLYR;
              else {
                if (ahlu_Var == 3 - wlyu_Var)
                  if (++diag[XPLYR][1] == 4)
                    status = XPLYR;
              }
              break;
            case 'O':
              if (++col[OPLYR][ahlu_Var] == 4) {
                status = OPLYR;
                break;
              } else if (++row[OPLYR][wlyu_Var] == 4) {
                status = OPLYR;
                break;
              }
              if (wlyu_Var == ahlu_Var && ++diag[OPLYR][0] == 4)
                status = OPLYR;
              else if (ahlu_Var == 3 - wlyu_Var)
                if (++diag[OPLYR][1] == 4)
                  status = OPLYR;
              break;
            case '.':
              empty++;
              break;
            }
            ahlu_Var++;
          }
        }
        getchar();
        wlyu_Var++;
      }
    }
    getchar();

    if (!empty && status == INCOMPLETE) {
      status = DRAW;
    }

    printf("Case #%d: %s\n", ++sxei_Var, result_str[status]);
  }

  return 0;
}
