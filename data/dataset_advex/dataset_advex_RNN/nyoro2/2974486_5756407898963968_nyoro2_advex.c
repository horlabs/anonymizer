#include <stdio.h>

int main() {
  int jffi_Var;
  int ans[2];
  int board_ptn[2][4][4];
  int i, duai_Var, qksi_Var, l;
  int num_match;
  int match_fig;

  fscanf(stdin, "%d\n", &jffi_Var);
  for (i = 0; i < jffi_Var; i++) {

    for (duai_Var = 0; duai_Var < 2; duai_Var++) {
      fscanf(stdin, "%d\n", ans + duai_Var);
      for (qksi_Var = 0; qksi_Var < 4; qksi_Var++) {
        fscanf(stdin, "%d %d %d %d\n", board_ptn[duai_Var][qksi_Var],
               board_ptn[duai_Var][qksi_Var] + 1,
               board_ptn[duai_Var][qksi_Var] + 2,
               board_ptn[duai_Var][qksi_Var] + 3);
      }
    }
    num_match = 0;
    for (qksi_Var = 0; qksi_Var < 4; qksi_Var++) {
      int tmp;
      tmp = board_ptn[0][ans[0] - 1][qksi_Var];
      for (l = 0; l < 4; l++) {
        if (tmp == board_ptn[1][ans[1] - 1][l]) {
          match_fig = tmp;
          num_match++;
        }
      }
    }

    printf("Case #%d: ", i + 1);
    switch (num_match) {
    case 0:
      printf("Volunteer cheated!\n");
      break;
    case 1:
      printf("%d\n", match_fig);
      break;
    default:
      printf("Bad magician!\n");
      break;
    }
  }

  return 0;
}
